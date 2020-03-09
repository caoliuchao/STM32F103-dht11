/**************************************************************************
 * @�ļ�  : main.c
 * @����  : caochao
 * @����  : 8-5-2019
 * @ժҪ  : ���C�ļ�ʱʵ����ϵͳ�ĳ�ʼ����ucosII������
 *
 * �޸��� :
 *  ����  :
**************************************************************************/
#include "stm32f10x.h"
#include <stdio.h>
#include "includes.h"
#include "task.h"

/**************************************************************************
* ������:  main
* ��  ��:  �����������
* ��  ��:   
*         �� 
* ��  ��:   
*         ��
**************************************************************************/
int main(void)
{     
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC��ռ����λ
    USART1_Configuration(); //��ʼ��usart1
		
    Systick_Init();                 //����UCOSIIϵͳ���� 
    
	OSInit();                       //UCOSII�ĳ�ʼ��
 	OSTaskCreate(start_task,(void *)0,(OS_STK *)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO );//������ʼ����
	OSStart();                      //����UCOSII
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    
    /* Infinite loop */
    while (1)
    {
		printf("Wrong parameters value: file %s on line %d\r\n", file, line);
    }
}
#endif

/**
  * @}
  */

/*******************************�ļ�����***************************************/


