/*****************************************************************************************
**	  中断配置文件
**
*******************************************************************************************/
#include "stm32f10x.h"
#include <stdio.h>
#include "Nvic.h"

/********************************************************************************************
*函数名称：void NVIC_Configuration(void)
*
*入口参数：无
*
*出口参数：无
*
*功能说明：中断参数配置
*******************************************************************************************/
void NVIC_Configuration(void)
{
//    NVIC_InitTypeDef NVIC_InitStructure;

#ifdef  VECT_TAB_RAM
    /* Set the Vector Table base location at 0x20000000 */
    NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0);
#else  /* VECT_TAB_FLASH  */
    /* Set the Vector Table base location at 0x08000000 */
    NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
#endif

//    NVIC_InitStructure.NVIC_IRQChannel = SysTick_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
}
