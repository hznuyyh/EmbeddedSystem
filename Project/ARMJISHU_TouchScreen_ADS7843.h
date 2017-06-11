/******************** (C) COPYRIGHT 2009 www.armjishu.com ************************
* File Name          : ARMJISHU_TouchScreen_ADS7843.h
* Author             : www.armjishu.com Team
* Version            : V3.0.1
* Date               : 03/20/2010
* Description        : 
*******************************************************************************/
#include "stm32f10x.h"
#include "stm32f10x_spi.h"


/* SPI_1 pins definition for test */
#define SPI1_PORT   GPIOB
#define SPI1_SCK    GPIO_Pin_13
#define SPI1_MISO   GPIO_Pin_14  ////////lihao  SPI3
#define SPI1_MOSI   GPIO_Pin_15
#define RCC_SPI1    RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO


/* ARMJISHU_TouchScreen_ADS7843 */

#define RCC_ADS7843_CS                         RCC_APB2Periph_GPIOB
#define GPIO_ADS7843_CS_PORT                   GPIOB 
#define GPIO_ADS7843_CS                        GPIO_Pin_12   

#define RCC_ADS7843_INT                        RCC_APB2Periph_GPIOG
#define GPIO_ADS7843_INT_PORT                  GPIOG  
#define GPIO_ADS7843_INT                       GPIO_Pin_7  
#define GPIO_ADS7843_EXTI_LINE                 EXTI_Line7
#define GPIO_ADS7843_EXTI_PORT_SOURCE          GPIO_PortSourceGPIOG
#define GPIO_ADS7843_EXTI_PIN_SOURCE           GPIO_PinSource7
#define GPIO_ADS7843_EXTI_IRQn                 EXTI9_5_IRQn 

#define GPIO_ADS7843_INT_VALID   !GPIO_ReadInputDataBit(GPIO_ADS7843_INT_PORT, GPIO_ADS7843_INT)

/* Select ADS7843: ChipSelect pin low  */
#define ADS7843_CS_LOW()     GPIO_ResetBits(GPIO_ADS7843_CS_PORT, RCC_ADS7843_CS)
/* Deselect ADS7843: ChipSelect pin high */
#define ADS7843_CS_HIGH()    GPIO_SetBits(GPIO_ADS7843_CS_PORT, RCC_ADS7843_CS)

/* pin low  */
#define SPI1_SCK_LOW()     GPIO_ResetBits(SPI1_PORT, SPI1_SCK)
/* pin high */
#define SPI1_SCK_HIGH()    GPIO_SetBits(SPI1_PORT, SPI1_SCK)

/* pin read  */
#define SPI1_MISO_READ()     GPIO_ReadInputDataBit(SPI1_PORT, SPI1_MISO)

/* pin low  */
#define SPI1_MOSI_LOW()     GPIO_ResetBits(SPI1_PORT, SPI1_MOSI)
/* pin high */
#define SPI1_MOSI_HIGH()    GPIO_SetBits(SPI1_PORT, SPI1_MOSI)

void ADS7843_Init(void);
static void ADS7843_INT_EXIT_Init(void);
static void ADS7843_INT_config(void);
static void ADS7843_InterruptConfig(void);
void ADS7843_CS_config(void);
void ADS7843_Init(void);
void SPI1_Config(void);
void SPI1_Init_For_Byte(void);
void SPI1_SendByte(u8 byte);
u8 SPI1_RecvByte(void);
void SPI1_SendWord(u16 word);
u16 SPI1_RecvWord(void);

void ARMJISHU_TouchScreen_ADS7843(void);


/*=====================================================================*/
/*=====================================================================*/
/*=====================================================================*/
/*=====================================================================*/
/*=====================================================================*/
/*=====================================================================*/
/*=====================================================================*/
/*=====================================================================*/
/*=====================================================================*/
/*=====================================================================*/

