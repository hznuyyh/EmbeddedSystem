/******************************************************************
**	  Gpio配置文件
**
********************************************************************/
#include "stm32f10x.h"
#include "Gpio_Led.h"

Key_Info key_info;

/********************************************************************************************
*函数名称：void GpioLed_Init(void)
*
*入口参数：无
*
*出口参数：无
*
*功能说明：led灯初始化配置
*******************************************************************************************/
void GpioLed_Init(void)
{
  	GPIO_InitTypeDef GPIO_InitStructure;
  
	RCC_APB2PeriphClockCmd(LED1_RCC_APB2Periph , ENABLE);// 使能APB2外设LED1时钟
	RCC_APB2PeriphClockCmd(LED2_RCC_APB2Periph , ENABLE);// 使能APB2外设LED2时钟
	RCC_APB2PeriphClockCmd(LED3_RCC_APB2Periph , ENABLE);// 使能APB2外设LED3时钟

  	GPIO_InitStructure.GPIO_Pin	= LED1_GPIO_Pin;         //选择led1
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //管脚频率为50MHZ
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	 //模式为推挽输出
  	GPIO_Init(LED1_GPIO, &GPIO_InitStructure);           //初始化led1寄存器

  	GPIO_InitStructure.GPIO_Pin	= LED2_GPIO_Pin;         //选择led2
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //管脚频率为50MHZ
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	 //模式为推挽输出
  	GPIO_Init(LED2_GPIO, &GPIO_InitStructure);           //初始化led2寄存器

	GPIO_InitStructure.GPIO_Pin	= LED3_GPIO_Pin;         //选择led3
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 	 //管脚频率为50MHZ
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	 //模式为推挽输出
  	GPIO_Init(LED3_GPIO, &GPIO_InitStructure);           //初始化led3寄存器
}

/********************************************************************************************
*函数名称：static void Delay(u32 counter)
*
*入口参数：u32 counter：计数个数
*
*出口参数：无
*
*功能说明：延时函数
*******************************************************************************************/
static void Delay(u32 counter)
{
	while(counter--);
}

/********************************************************************************************
*函数名称：void LED_Disply(void)
*
*入口参数：无
*
*出口参数：无
*
*功能说明：LED闪烁
*******************************************************************************************/
void LED_Display(void)
{
    GPIO_SetBits(LED1_GPIO,LED1_GPIO_Pin);
	Delay(0xfffff);
	GPIO_ResetBits(LED1_GPIO,LED1_GPIO_Pin);

	GPIO_SetBits(LED2_GPIO,LED2_GPIO_Pin);
	Delay(0xfffff);
	GPIO_ResetBits(LED2_GPIO,LED2_GPIO_Pin);

	GPIO_SetBits(LED3_GPIO,LED3_GPIO_Pin);
	Delay(0xfffff);
	GPIO_ResetBits(LED3_GPIO,LED3_GPIO_Pin);
}

/********************************************************************************************
*函数名称：void Key_Init(void)
*
*入口参数：无
*
*出口参数：无
*
*功能说明：按键初始化配置
*******************************************************************************************/
void Key_Init(void)
{
  	GPIO_InitTypeDef GPIO_InitStructure;
  
	RCC_APB2PeriphClockCmd(KEY1_RCC_APB2Periph , ENABLE);// 使能APB2外设KEY1时钟
	RCC_APB2PeriphClockCmd(KEY2_RCC_APB2Periph , ENABLE);// 使能APB2外设KEY2时钟
	RCC_APB2PeriphClockCmd(KEY3_RCC_APB2Periph , ENABLE);// 使能APB2外设KEY3时钟

  	GPIO_InitStructure.GPIO_Pin	= KEY1_GPIO_Pin;         //选择KEY1
  	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //管脚频率为50MHZ
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//模式为输入浮空
  	GPIO_Init(KEY1_GPIO, &GPIO_InitStructure);           //初始化KEY1寄存器

  	GPIO_InitStructure.GPIO_Pin	= KEY2_GPIO_Pin;         //选择KEY2
  	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //管脚频率为50MHZ
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//模式为输入浮空
  	GPIO_Init(KEY2_GPIO, &GPIO_InitStructure);           //初始化KEY2寄存器

	GPIO_InitStructure.GPIO_Pin	= KEY3_GPIO_Pin;         //选择KEY3
  	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 	 //管脚频率为50MHZ
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//模式为输入浮空
  	GPIO_Init(KEY3_GPIO, &GPIO_InitStructure);           //初始化KEY3寄存器
}

/********************************************************************************************
*函数名称：void Key_Test(void)
*
*入口参数：无
*
*出口参数：无
*
*功能说明：key测试
*******************************************************************************************/
void Key_Test(void)
{
    /***************按键1的测试********************/
	if(GPIO_ReadInputDataBit(KEY1_GPIO,KEY1_GPIO_Pin) == Bit_RESET)
	{
	    GPIO_ResetBits(LED1_GPIO,LED1_GPIO_Pin);    
	}
	else if(GPIO_ReadInputDataBit(KEY1_GPIO,KEY1_GPIO_Pin) == Bit_SET)
	{
	    GPIO_SetBits(LED1_GPIO,LED1_GPIO_Pin);    
	}
	/***************按键2的测试********************/
	if(GPIO_ReadInputDataBit(KEY2_GPIO,KEY2_GPIO_Pin) == Bit_RESET)
	{
	    Delay(0xfffff);
		if(GPIO_ReadInputDataBit(KEY2_GPIO,KEY2_GPIO_Pin) == Bit_RESET)
		{
		    if(key_info.Key2_state == true)
			    key_info.Key2_state = false;
			else
				key_info.Key2_state = true;
		}		
	}

	if(key_info.Key2_state == true)
	    GPIO_ResetBits(LED2_GPIO,LED2_GPIO_Pin);
	else 
		GPIO_SetBits(LED2_GPIO,LED2_GPIO_Pin);

    /***************按键3的测试********************/
	if(GPIO_ReadInputDataBit(KEY3_GPIO,KEY3_GPIO_Pin) == Bit_RESET)
	{
	    Delay(0xffff);
		if(GPIO_ReadInputDataBit(KEY3_GPIO,KEY3_GPIO_Pin) == Bit_RESET)
		{
		    if(key_info.Key3_state == true)
			    key_info.Key3_state = false;
			else
				key_info.Key3_state = true;
		}		
	}

	key_info.Counter2 += 0xfff;
	if(key_info.Counter2 > 0x2fffff)
    key_info.Counter2 = 0;

	if(key_info.Key3_state == true)
	{
	    key_info.Counter1 += 1;
		if(key_info.Counter1 > 0x2ff)
		    key_info.Counter1 = 0;
		
		if(key_info.Counter2 > key_info.Counter1 * 0xfff)
		    GPIO_SetBits(LED3_GPIO,LED3_GPIO_Pin);
		else
		    GPIO_ResetBits(LED3_GPIO,LED3_GPIO_Pin);
	}
	else
	    GPIO_SetBits(LED3_GPIO,LED3_GPIO_Pin);
}






