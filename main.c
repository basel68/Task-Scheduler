/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Bassel Mohamed
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "main.h"
#include "led.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
uint8_t current_task=1;
uint32_t g_tick_count=0;

/* This is a task control block carries private information of each task */
typedef struct
{
	uint32_t psp_value;
	uint32_t block_count;
	uint8_t  current_state;
	void (*task_handler)(void);
}TCB_t;
TCB_t user_tasks[MAX_TASKS];

//semihosting init function 
extern void initialise_monitor_handles(void);
int main(void)
{
	enable_processor_faults();
	initialise_monitor_handles();
	init_scheduler_stack(SCHEDULER_STACK_START);
	init_task_stack();
	led_init_all();
	init_systick_timer(TICK_HZ);// Starting the systick timer
	change_msp_to_psp();
	void Task1();
}

void idle_task(void)
{
	while(1);
}
void enable_processor_faults(){
	uint32_t *pSHCSR = (uint32_t*)0xE000ED24;

		*pSHCSR |= ( 1 << 16); //mem manage
		*pSHCSR |= ( 1 << 17); //bus fault
		*pSHCSR |= ( 1 << 18); //usage fault

}
uint32_t get_psp_value(){
	return user_tasks[current_task].psp_value;
}
__attribute ((naked)) void change_msp_to_psp(){
	 //1. initialize the PSP with TASK1 stack start address

		//get the value of psp of current_task
		__asm volatile ("PUSH {LR}"); //preserve LR which connects back to main()
		__asm volatile ("BL get_psp_value");
		__asm volatile ("MSR PSP,R0"); //initialize psp
		__asm volatile ("POP {LR}");  //pops back LR value

		//2. change SP to PSP using CONTROL register
		__asm volatile ("MOV R0,#0X02");
		__asm volatile ("MSR CONTROL,R0");
		__asm volatile ("BX LR");
}
void init_task_stack(){
	uint32_t *pPSP;


		user_tasks[0].psp_value = IDLE_STACK_START;
		user_tasks[1].psp_value = TASK1_STACK_START;
		user_tasks[2].psp_value = TASK2_STACK_START;
		user_tasks[3].psp_value = TASK3_STACK_START;
		user_tasks[4].psp_value = TASK4_STACK_START;

		user_tasks[0].task_handler = idle_task;
		user_tasks[1].task_handler = Task1;
		user_tasks[2].task_handler = Task2;
		user_tasks[3].task_handler = Task3;
		user_tasks[4].task_handler = Task4;
	for(int i=0;i<MAX_TASKS;i++){
		user_tasks[i].current_state = TASK_READY_STATE;

		pPSP= (uint32_t*) user_tasks[i].psp_value;
		pPSP--;
		*pPSP=dummy_xPSR;
		pPSP--;
		*pPSP=(uint32_t) user_tasks[i].task_handler;//pc
		pPSP--;
		*pPSP=0XFFFFFFFD;
		for(int j=0;j<13;j++){
			pPSP--;
			*pPSP=0;
			}
		user_tasks[i].psp_value = (uint32_t)pPSP;
	}

}
void init_systick_timer(uint32_t tick_hz){
	uint32_t count=(SYSTICK_HZ/tick_hz)-1;
	uint32_t *pCSR=(uint32_t*)SYST_CSR;//address of SysTick Control and Status Register
	uint32_t *pRVR=(uint32_t*)SYST_RVR;//address of SysTick Reload Value Register
//	uint32_t *pCVR=(uint32_t*)SYST_CVR;//address of SysTick Current Value Register
	*pCSR |=7;// activating first 3 bits which are used for counter enable,exception request,taking processor freq.
	*pRVR &=~(0x00FFFFFF);
	*pRVR |=(count);//set count value in reload register

}
void schedule(void)
{
	//pend the pendsv exception
	uint32_t *pICSR = (uint32_t*)0xE000ED04;
	*pICSR |= ( 1 << 28);

}
void task_delay(uint32_t tick_count)
{
	//disable interrupt
	INTERRUPT_DISABLE();

	if(current_task)
	{
	   user_tasks[current_task].block_count = g_tick_count + tick_count;
	   user_tasks[current_task].current_state = TASK_BLOCKED_STATE;
	   schedule();
	}

	//enable interrupt
	INTERRUPT_ENABLE();
}
__attribute ((naked)) void init_scheduler_stack(uint32_t start_of_stack){
	__asm volatile("MSR MSP, %0 "::"r" (start_of_stack):);
	__asm volatile("BX LR");

}


void HardFault_Handler(void)
{
	printf("Exception : Hardfault\n");
	while(1);
}


void MemManage_Handler(void)
{
	printf("Exception : MemManage\n");
	while(1);
}

void BusFault_Handler(void)
{
	printf("Exception : BusFault\n");
	while(1);
}
void save_psp(uint32_t current_stack_psp){
	user_tasks[current_task].psp_value=current_stack_psp;
}

void get_next_task_id(){
	int state = TASK_BLOCKED_STATE;

		for(int i= 0 ; i < (MAX_TASKS) ; i++)
		{
			current_task++;
		    current_task %= MAX_TASKS;
			state = user_tasks[current_task].current_state;
			if( (state == TASK_READY_STATE) && (current_task != 0) )
				break;
		}

		if(state != TASK_READY_STATE)
			current_task = 0;
}
__attribute((naked)) void PendSV_Handler(void)
{
	__asm("PUSH {LR}");
//save last running task stack info
	__asm("MRS R0 , PSP");
	__asm("STMDB R0!,{R4,R11}");
	__asm("BL save_psp ");
//retrieve next task info
	__asm("BL get_next_task_id");
	__asm("BL get_psp_value");
	__asm("LDMIA R0!,{R4-R11}");
	__asm("MSR PSP,R0");
	__asm("POP {LR}");
	__asm("BX LR");


}


void update_global_tick_count(void)
{
	g_tick_count++;
}
void unblock_tasks(void)
{
	for(int i = 1 ; i < MAX_TASKS ; i++)
	{
		if(user_tasks[i].current_state != TASK_READY_STATE)
		{
			if(user_tasks[i].block_count == g_tick_count)
			{
				user_tasks[i].current_state = TASK_READY_STATE;
			}
		}

	}

}
 void SysTick_Handler(){


	uint32_t *pICSR = (uint32_t*)0xE000ED04;

	    update_global_tick_count();

	    unblock_tasks();

	    //pend the pendsv exception
	    *pICSR |= ( 1 << 28);


}
void Task1(void){
	while(1)
		{
			led_on(LED_GREEN);
			task_delay(1000);
			led_off(LED_GREEN);
			task_delay(1000);
		}
}
void Task2(void){
	while(1)
		{
			led_on(LED_ORANGE);
			task_delay(500);
			led_off(LED_ORANGE);
			task_delay(500);
		}
}
void Task3(void){

	while(1)
	{
		led_on(LED_BLUE);
		task_delay(250);
		led_off(LED_BLUE);
		task_delay(250);
	}
}
void Task4(void){
	while(1)
		{
			led_on(LED_RED);
			task_delay(125);
			led_off(LED_RED);
			task_delay(125);
		}
}
