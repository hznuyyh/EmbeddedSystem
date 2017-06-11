#ifndef _GPIO_LED_H_
#define _GPIO_LED_H_ 

/*****led1接口声明*****/
#define LED1_RCC_APB2Periph  RCC_APB2Periph_GPIOF
#define LED1_GPIO            GPIOF
#define LED1_GPIO_Pin        GPIO_Pin_6

/*****led2接口声明*****/
#define LED2_RCC_APB2Periph  RCC_APB2Periph_GPIOF
#define LED2_GPIO            GPIOF
#define LED2_GPIO_Pin        GPIO_Pin_7

/*****led3接口声明*****/
#define LED3_RCC_APB2Periph  RCC_APB2Periph_GPIOF
#define LED3_GPIO            GPIOF
#define LED3_GPIO_Pin        GPIO_Pin_8

/*****按键USER1接口声明*****/
#define KEY1_RCC_APB2Periph  RCC_APB2Periph_GPIOA
#define KEY1_GPIO            GPIOA
#define KEY1_GPIO_Pin        GPIO_Pin_8

/*****按键USER2接口声明*****/
#define KEY2_RCC_APB2Periph  RCC_APB2Periph_GPIOD
#define KEY2_GPIO            GPIOD
#define KEY2_GPIO_Pin        GPIO_Pin_3

/*****按键WAKEUP接口声明*****/
#define KEY3_RCC_APB2Periph  RCC_APB2Periph_GPIOA
#define KEY3_GPIO            GPIOA
#define KEY3_GPIO_Pin        GPIO_Pin_0

typedef enum
{
    false=0,
	true
}Bool;

typedef struct
{
    Bool Key1_state;	//按键1的状态标记
	Bool Key2_state;	//按键2的状态标记
	Bool Key3_state;	//按键3的状态标记
	u32  Counter1;      //临时计数
	u32  Counter2;      //临时计数
}Key_Info;

void GpioLed_Init(void);
void LED_Display(void);
void Key_Init(void);
void Key_Test(void);


#endif
