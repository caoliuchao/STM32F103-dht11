/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "usart.h"
#include "includes.h"

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
	
  //__set_FAULTMASK(1); //关闭所有中断
  //NVIC_SystemReset(); //产生系统复位
  while (1)
  {
      
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
      
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
      
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
    
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
    
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
/*void PendSV_Handler(void)
{
}*/

/**********************************************************************
*   函数名：SysTick_Handler(void)
*   功  能：系统滴答时钟中断
*   输  入：
*           无
*   输  出：
*           无
**********************************************************************/
//SYSTEM_SUPPORT_OS为1,说明使用ucosII了
/*systick中断服务函数,使用ucos时用到*/
void SysTick_Handler(void)
{
#if SYSTEM_SUPPORT_OS	 	
	OSIntEnter();    
#endif

    OSTimeTick();       //调用ucos的时钟服务程序 
	
#if SYSTEM_SUPPORT_OS	 
	OSIntExit();  	    //触发任务切换软中断								 
#endif	    
}

/**********************************************************************************
 *   函数名：EXTI4_IRQHandler
 *   功  能：外部中断服务函数
 *   输  入：
 *          无
 *   输  出：
 *          无
 *********************************************************************************/
void EXTI4_IRQHandler(void)
{
#if SYSTEM_SUPPORT_OS	 	
	OSIntEnter();    
#endif
    
    if(EXTI_GetITStatus(EXTI_Line4) == SET)
    {
        /* Clear the  EXTI line 4 pending bit */
        EXTI_ClearITPendingBit(EXTI_Line4);
    } 
    
#if SYSTEM_SUPPORT_OS	 
	OSIntExit();  											 
#endif	
}

/*********************************************************************
 *   函数名：TIM2_IRQHandlerr
 *   功  能：定时器中断服务函数
 *   输  入：
 *          无
 *   输  出：
 *          无
 ********************************************************************/
void TIM2_IRQHandler(void)   // Timer2 Interrupt Handler
{
#if SYSTEM_SUPPORT_OS	 	
	OSIntEnter();    
#endif
   
    if (TIM_GetITStatus(TIM2,TIM_IT_Update) == SET)
    {
        //(void) irmp_ISR(); // call irmp ISR
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update); 
    }
    
#if SYSTEM_SUPPORT_OS	 
	OSIntExit();  											 
#endif	
}
     
/********************************************************************
 *   函数名：TIM4_IRQHandlerr
 *   功  能：定时器中断服务函数
 *   输  入：
 *          无
 *   输  出：
 *          无
 *******************************************************************/
void TIM4_IRQHandler(void)   // Timer4 Interrupt Handler
{
#if SYSTEM_SUPPORT_OS	 	
	OSIntEnter();    
#endif
   if (TIM_GetITStatus(TIM4,TIM_IT_Update) == SET)   
   {  
       //(void) irsnd_ISR(); // call irmp ISR
       TIM_ClearITPendingBit(TIM4, TIM_IT_Update); 
   }
    
#if SYSTEM_SUPPORT_OS	 
	OSIntExit();  											 
#endif	
}
/***************************文件结束********************************/

