#include <stdint.h>
 
#define SRAM_START 0X20000000U
#define SRAM_SIZE (128*1024) 
#define SRAM_END (SRAM_START+SRAM_SIZE)

#define STACK_START SRAM_END

/* function prototypes of STM32F407x system exception and IRQ handlers */
void Default_Handler(void);
void Reset_Handler(void);
void NMI_Handler 					(void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler 			(void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler 					(void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler   				(void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler  				(void) __attribute__ ((weak, alias("Default_Handler")));
void WWDG_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void PVD_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void TAMP_STAMP_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));      
void RTC_WKUP_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));                               
void RCC_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void EXTI0_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI1_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI3_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI4_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void DMA1_Stream0_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream1_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream2_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream3_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream4_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream5_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream6_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void ADC_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void CAN1_TX_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void CAN1_RX0_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));        
void CAN1_RX1_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));        
void CAN1_SCE_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));        
void EXTI9_5_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void TIM1_BRK_TIM9_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));   
void TIM1_UP_TIM10_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));   
void TIM1_TRG_COM_TIM11_IRQHandler 	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void TIM2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void TIM3_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void TIM4_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void I2C1_EV_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C1_ER_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C2_EV_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C2_ER_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void SPI1_IRQHandler  				(void) __attribute__ ((weak, alias("Default_Handler")));           
void SPI2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void USART1_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler")));         
void USART2_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler")));        
void USART3_IRQHandler   			(void) __attribute__ ((weak, alias("Default_Handler")));        
void EXTI15_10_IRQHandler   		(void) __attribute__ ((weak, alias("Default_Handler")));     
void RTC_Alarm_IRQHandler    		(void) __attribute__ ((weak, alias("Default_Handler")));    
void OTG_FS_WKUP_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler"))); 
void TIM8_BRK_TIM12_IRQHandler   	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_UP_TIM13_IRQHandler    	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_TRG_COM_TIM14_IRQHandler 	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream7_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void FSMC_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void SDIO_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM5_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void SPI3_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void UART4_IRQHandler            	(void) __attribute__ ((weak, alias("Default_Handler")));
void UART5_IRQHandler            	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM6_DAC_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM7_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream0_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream1_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream2_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream3_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream4_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void ETH_IRQHandler              	(void) __attribute__ ((weak, alias("Default_Handler")));
void ETH_WKUP_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_TX_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_RX0_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_RX1_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_SCE_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_FS_IRQHandler           	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream5_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream6_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream7_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void USART6_IRQHandler           	(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_EP1_OUT_IRQHandler   	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_EP1_IN_IRQHandler    	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_WKUP_IRQHandler      	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_IRQHandler           	(void) __attribute__ ((weak, alias("Default_Handler")));
void DCMI_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void CRYP_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void HASH_RNG_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void FPU_IRQHandler              	(void) __attribute__ ((weak, alias("Default_Handler"))); 

__attribute__((section(".isr_vector"))) uint32_t vectors[]={
	STACK_START,
	 (uint32_t)Reset_Handler,                  // Reset handler
    (uint32_t)NMI_Handler,                    // NMI handler
    (uint32_t)HardFault_Handler,              // Hard Fault handler
    (uint32_t)MemManage_Handler,              // Memory Management Fault handler
    (uint32_t)BusFault_Handler,               // Bus Fault handler
    (uint32_t)UsageFault_Handler,             // Usage Fault handler
    0,                              // Reserved
    0,                              // Reserved
    0,                              // Reserved
    0,                              // Reserved
    (uint32_t)SVC_Handler,                    // SVCall handler
    (uint32_t)DebugMon_Handler,               // Debug Monitor handler
    0,                              // Reserved
    (uint32_t)PendSV_Handler,                 // PendSV handler
    (uint32_t)SysTick_Handler,                // SysTick handler
    // External Interrupts - Peripherals
    (uint32_t)WWDG_IRQHandler,                // 0 Window Watchdog
    (uint32_t)PVD_IRQHandler,                 // 1 PVD through EXTI Line detection
    (uint32_t)TAMP_STAMP_IRQHandler,          // 2 Tamper and TimeStamp
    (uint32_t)RTC_WKUP_IRQHandler,            // 3 RTC Wakeup through EXTI Line
    0,
    (uint32_t)RCC_IRQHandler,                 // 4 RCC
    (uint32_t)EXTI0_IRQHandler,               // 5 EXTI Line 0
    (uint32_t)EXTI1_IRQHandler,               // 6 EXTI Line 1
    (uint32_t)EXTI2_IRQHandler,               // 7 EXTI Line 2
    (uint32_t)EXTI3_IRQHandler,               // 8 EXTI Line 3
    (uint32_t)EXTI4_IRQHandler,               // 9 EXTI Line 4
    (uint32_t)DMA1_Stream0_IRQHandler,        // 10 DMA1 Stream 0
    (uint32_t)DMA1_Stream1_IRQHandler, 
    (uint32_t)DMA1_Stream2_IRQHandler,        // 12 DMA1 Stream 2
    (uint32_t)DMA1_Stream3_IRQHandler,        // 13 DMA1 Stream 3
    (uint32_t)DMA1_Stream4_IRQHandler,        // 14 DMA1 Stream 4
    (uint32_t)DMA1_Stream5_IRQHandler,        // 15 DMA1 Stream 5
    (uint32_t)DMA1_Stream6_IRQHandler,        // 16 DMA1 Stream 6
    (uint32_t)ADC_IRQHandler,                 // 17 ADC
    (uint32_t)CAN1_TX_IRQHandler,             // 18 CAN1 TX
    (uint32_t)CAN1_RX0_IRQHandler,            // 19 CAN1 RX0
    (uint32_t)CAN1_RX1_IRQHandler,            // 20 CAN1 RX1
    (uint32_t)CAN1_SCE_IRQHandler,            // 21 CAN1 SCE
    (uint32_t)EXTI9_5_IRQHandler,             // 22 EXTI Line 9-5
    (uint32_t)TIM1_BRK_TIM9_IRQHandler,       // 23 TIM1 Break and TIM9
    (uint32_t)TIM1_UP_TIM10_IRQHandler,       // 24 TIM1 Update and TIM10
    (uint32_t)TIM1_TRG_COM_TIM11_IRQHandler,  // 25 TIM1 Trigger and TIM11
    (uint32_t)TIM1_CC_IRQHandler,             // 26 TIM1 Capture Compare
    (uint32_t)TIM2_IRQHandler,                // 27 TIM2
    (uint32_t)TIM3_IRQHandler,                // 28 TIM3
    (uint32_t)TIM4_IRQHandler,                // 29 TIM4
    (uint32_t)I2C1_EV_IRQHandler,             // 30 I2C1 Event
    (uint32_t)I2C1_ER_IRQHandler,             // 31 I2C1 Error
    (uint32_t)I2C2_EV_IRQHandler,             // 32 I2C2 Event
    (uint32_t)I2C2_ER_IRQHandler,             // 33 I2C2 Error
    (uint32_t)SPI1_IRQHandler,                // 34 SPI1
    (uint32_t)SPI2_IRQHandler,                // 35 SPI2
    (uint32_t)USART1_IRQHandler,              // 36 USART1
    (uint32_t)USART2_IRQHandler,              // 37 USART2
    (uint32_t)USART3_IRQHandler,              // 38 USART3
    (uint32_t)EXTI15_10_IRQHandler,           // 39 EXTI Line 15-10
    (uint32_t)RTC_Alarm_IRQHandler,           // 40 RTC Alarm
    (uint32_t)OTG_FS_WKUP_IRQHandler,        // 41 USB OTG FS Wakeup
    (uint32_t)TIM8_BRK_TIM12_IRQHandler,      // 42 TIM8 Break and TIM12
    (uint32_t)TIM8_UP_TIM13_IRQHandler,       // 43 TIM8 Update and TIM13
    (uint32_t)TIM8_TRG_COM_TIM14_IRQHandler,  // 44 TIM8 Trigger and TIM14
    (uint32_t)TIM8_CC_IRQHandler,             // 45 TIM8 Capture Compare
    (uint32_t)DMA1_Stream7_IRQHandler,        // 46 DMA1 Stream 7
    (uint32_t)FSMC_IRQHandler,                // 47 FSMC
    (uint32_t)SDIO_IRQHandler,                // 48 SDIO
    (uint32_t)TIM5_IRQHandler,                // 49 TIM5
    (uint32_t)SPI3_IRQHandler,                // 50 SPI3
    (uint32_t)UART4_IRQHandler,               // 51 UART4
    (uint32_t)UART5_IRQHandler,               // 52 UART5
    (uint32_t)TIM6_DAC_IRQHandler,            // 53 TIM6 and DAC
    (uint32_t)TIM7_IRQHandler,                // 54 TIM7
    (uint32_t)DMA2_Stream0_IRQHandler,        // 55 DMA2 Stream 0
    (uint32_t)DMA2_Stream1_IRQHandler,        // 56 DMA2 Stream 1
    (uint32_t)DMA2_Stream2_IRQHandler,        // 57 DMA2 Stream 2
    (uint32_t)DMA2_Stream3_IRQHandler,        // 58 DMA2 Stream 3
    (uint32_t)DMA2_Stream4_IRQHandler,        // 59 DMA2 Stream 4
    (uint32_t)ETH_IRQHandler,                 // 60 Ethernet
    (uint32_t)ETH_WKUP_IRQHandler,            // 61 Ethernet Wakeup
    (uint32_t)CAN2_TX_IRQHandler,             // 62 CAN2 TX
    (uint32_t)CAN2_RX0_IRQHandler,            // 63 CAN2 RX0
    (uint32_t)CAN2_RX1_IRQHandler,            // 64 CAN2 RX1
    (uint32_t)CAN2_SCE_IRQHandler,            // 65 CAN2 SCE
    (uint32_t)OTG_FS_IRQHandler,              // 66 USB OTG FS
    (uint32_t)DMA2_Stream5_IRQHandler,        // 67 DMA2 Stream 5
    (uint32_t)DMA2_Stream6_IRQHandler,        // 68 DMA2 Stream 6
    (uint32_t)DMA2_Stream7_IRQHandler,        // 69 DMA2 Stream 7
    (uint32_t)USART6_IRQHandler,              // 70 USART6
    (uint32_t)I2C3_EV_IRQHandler,             // 71 I2C3 Event
    (uint32_t)I2C3_ER_IRQHandler,             // 72 I2C3 Error
    (uint32_t)OTG_HS_EP1_OUT_IRQHandler,      // 73 USB OTG HS EP1 Out
    (uint32_t)OTG_HS_EP1_IN_IRQHandler,       // 74 USB OTG HS EP1 In
    (uint32_t)OTG_HS_WKUP_IRQHandler,         // 75 USB OTG HS Wakeup
    (uint32_t)OTG_HS_IRQHandler,              // 76 USB OTG HS
    (uint32_t)DCMI_IRQHandler,                // 77 DCMI
    (uint32_t)CRYP_IRQHandler,                // 78 CRYP crypto
    (uint32_t)HASH_RNG_IRQHandler,            // 79 Hash and RNG
    (uint32_t)FPU_IRQHandler };
void Reset_Handler(){

}
void Default_Handler(){
	while(1);
}
