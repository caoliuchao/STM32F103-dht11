/********************************************************************
* @�ļ�  : task.c
* @����  : caochao
* @����  : 14-2-2017
* @ժҪ  : ���c�ļ�������������
* �޸��� :
*  ����  :
*
* �޸��� :
*  ����  :
*********************************************************************/
#include "stm32f10x.h"
#include "includes.h"
#include "task.h"

/*-----------------��ʼ�����ջ-------------------------------------*/
__align(8) OS_STK START_TASK_STK[START_STK_SIZE];   //���������ջ�ռ�

/*-----------------���ڴ�ӡ��ջ-------------------------------------*/
__align(8) OS_STK USART1_TASK_STK[USART1_STK_SIZE]; //���������ջ�ռ�	

/*-------------------DHT11�����ջ----------------------------------*/
__align(8) OS_STK DHT11_TASK_STK[DHT11_STK_SIZE];       //���������ջ�ռ�	

/*******************************************************************
*   ��������start_task(void *pdata)
*   ��  �ܣ���ʼ���񣬽�����������
*   ��  �룺
*          pdata ָ��
*   ��  ����
*          ��
*******************************************************************/
void start_task(void *pdata)
{
    uint8_t status;
    OS_CPU_SR cpu_sr = 0;
	
	OSStatInit();					//��ʼ��ͳ������.�������ʱ1��������	
 	OS_ENTER_CRITICAL();			//�����ٽ���(�޷����жϴ��)   
	
    OSTaskCreate(usart1_task,(void *)0,(OS_STK*)&USART1_TASK_STK[USART1_STK_SIZE-1],USART1_TASK_PRIO);  
    OSTaskCreate(dht11_task,(void *)0,(OS_STK*)&DHT11_TASK_STK[DHT11_STK_SIZE-1],DHT11_TASK_PRIO);
    
    status = OSTaskDelReq(OS_PRIO_SELF);	//����ɾ����ʼ����.
    if (status == OS_ERR_NONE)
    {
		status = OSTaskDel(OS_PRIO_SELF);
        if (status == OS_ERR_NONE)
        {
            printf("ɾ����ʼ����ɹ� \r\n");
        }
        else
        {
            printf("��ʼ����ɾ��ʧ�� \r\n");
        }
    }
    else
    {
        printf("����ʼ����ɾ��ʧ�� \r\n");
    }
    
    OS_EXIT_CRITICAL();	   //�˳��ٽ���(���Ա��жϴ��)    	
}

/*************************************************************************************
 *   ��������dht11_task(void *pdata)
 *   ��  �ܣ���ʪ�Ȳ�������
 *   ��  �룺
 *          pdata ָ��
 *   ��  ����
 *          ��
 ************************************************************************************/
void dht11_task(void *pdata)
{
   uint8_t  res;
   float    temp;
   float    humi;
    
   while (1)
   {
       res = DHT11_Read_Data(&temp,&humi);
       if (res == 0)
       {
           printf("��ǰ�����¶�Ϊ�� %0.1f��  \r\n",temp);
           printf("��ǰ����ʪ��Ϊ�� %0.1f    \r\n",humi);
       }
       else if(res == 1)
       {
           printf("DHT11�����ڣ�\r\n");
       }
       else
       {
           printf("�������ݸ�ʽ���ԣ�\r\n");
       }
       
       Delay1ms(1000);
   }       
}

/*********************************************************************
*   ��������usart1_task(void *pdata)
*   ��  �ܣ�usart1���ڴ�ӡ����
*   ��  �룺
*          pdata ָ��
*   ��  ����
*          ��
**********************************************************************/
void usart1_task(void *pdata)
{  
    while (1)
    {  	
        printf("CPU��ʹ����Ϊ��%d%%  \r\n",OSCPUUsage);  //��ӡ��CPU��ʹ����
		Delay1ms(1000);	
    }
}
				
/*****************************�ļ�����********************************/
                


