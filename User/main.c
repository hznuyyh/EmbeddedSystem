/****************************************Copyright (c)***************************************
**--------------------------------------File Info--------------------------------------------
** File name:           main.c
**
**-------------------------------------------------------------------------------------------
** Modified by:         
** Modified date:       
** Version:             
** Descriptions:        
**-------------------------------------------------------------------------------------------
********************************************************************************************/
#include "stm32f10x.h"
#include <stdio.h>
#include "SystemClock.h"
#include "Nvic.h"
#include "Systick.h"
#include "lcd.h"
#include "Config.h"
#include <math.h>
#include<stdlib.h>
#include <time.h>

#include "TouchScreen_ADS7843.h"
#define BEEPON GPIO_SetBits(GPIOE, GPIO_Pin_2)
#define BEEPOFF	GPIO_ResetBits(GPIOE, GPIO_Pin_2)


int x = 20;
int y = 20;
int x2 = 200;
int y2 = 270;
double times = 600;
int temp = 0;
int i = 0;
int score = 0;
int j = 0;
int count = 0;
long int srand_seed = 16389625397;
int touch_x,touch_y;
extern struct touchScreen touchPoint;
/***   主函数   ***/
int main(void)
{  	
    
	RCC_Configuration();	                   //系统时钟初始化
	STM3210E_LCD_Init();	                   //LCD屏初始化
	LCD_Clear(White);		                   //清屏
	ADS7843_Init();	//触摸屏初始化
	//DrawRectangle(x,y,x2,y2);
	loop:GameStart();
	Delay(200);
	while(1){
	   if(touchPoint.flag){
			touch_x = touchPoint.x;
			touch_y = touchPoint.y;
			if(touch_x >= 75 && touch_x <= 95 && touch_y >= 120 && touch_y <= 166){
				BEEPON;
				touchPoint.flag = 0;
				Delay(200);
				BEEPOFF;
				goto start;
			}
			if(touch_x >= 115 && touch_x <= 135 && touch_y >= 120 && touch_y <=166){
				BEEPON;
				touchPoint.flag = 0;
				Delay(200);
				BEEPOFF;
				goto help;
			}
	   }
	   else;
	}
	start:
		LCD_Clear(White);
		DrawRectangle(x,y,x2,y2);
		ShowLineChinese(36,3,210,50,Black,White);
		while(1){
			if(touchPoint.flag){
				touchPoint.flag = 0;
				touch_x = touchPoint.x;
				touch_y = touchPoint.y;
			}
			else{
				touch_x = 0 ;
				touch_y = 0;
			}						
			//ShowNumber(i,1,20,20,Black,White);
			RunTime(times,210,260);
			DrawMouse(i);
			if(isClicked(i,touch_x,touch_y)){
				BEEPON;
				score++;
				getScore(score);
				Delay(2);
				BEEPOFF;
			}
			else{
			 	getScore(score);
			}
			j++;
			count++;
			if(count==7){
				times--;
				count = 0;
			}
			if(times == 0){
			   goto end;
			}		
			if(j>=50){
				ClearMouse(i);
				j=0;
				srand(srand_seed++);
 	 			i = rand()%9;
			 }
			 Delay(10);
		}
	 //游戏开始
	 help:
		LCD_Clear(White);
		GameHelp();
		while(1){
			if(touchPoint.flag){
			touchPoint.flag = 0;
			goto loop;
			}
		} 
		//游戏帮助
	end:
		LCD_Clear(White);
		GameEnd(score);	
	//游戏结束
}


