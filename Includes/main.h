/*
 * main.h
 *
 *  Created on: Sep 18, 2023
 *      Author: Lenovo
 */

#ifndef MAIN_H_
#define MAIN_H_
#include <stdint.h>
#define TASK_STACK_SIZE 1024U
#define SCHEDULER_STACK_SIZE 1024U

#define SRAM_START 0x20000000U
#define SRAM_SIZE (128*1024)
#define SRAM_END (SRAM_START+SRAM_SIZE)

#define TASK1_STACK_START SRAM_END
#define TASK2_STACK_START (SRAM_END-TASK_STACK_SIZE)
#define TASK3_STACK_START (SRAM_END-(2*TASK_STACK_SIZE))
#define TASK4_STACK_START (SRAM_END-(3*TASK_STACK_SIZE))
#define IDLE_STACK_START  (SRAM_END - (4 * TASK_STACK_SIZE) )
#define SCHEDULER_STACK_START (SRAM_END-(5*TASK_STACK_SIZE))

#define SYSTICK_HZ 16000000
#define TICK_HZ 1000

#define SYST_CSR 0xE000E010
#define SYST_RVR 0xE000E014
#define SYST_CVR 0xE000E018

#define MAX_TASKS 5
#define dummy_xPSR 0x01000000

#define TASK_READY_STATE  0x00
#define TASK_BLOCKED_STATE  0XFF

#define INTERRUPT_DISABLE()  do{__asm volatile ("MOV R0,#0x1"); asm volatile("MSR PRIMASK,R0"); } while(0)

#define INTERRUPT_ENABLE()  do{__asm volatile ("MOV R0,#0x0"); asm volatile("MSR PRIMASK,R0"); } while(0)


void idle_task(void);
void enable_processor_faults();
void change_msp_to_psp();
void Task1(void);
void Task2(void);
void Task3(void);
void Task4(void);
void init_systick_timer(uint32_t tick_hz);
__attribute ((naked)) void init_scheduler_stack(uint32_t start_of_stack);
void init_task_stack();
void get_next_task_id();
void save_psp(uint32_t current_stack_psp);
void schedule();
#endif /* MAIN_H_ */
