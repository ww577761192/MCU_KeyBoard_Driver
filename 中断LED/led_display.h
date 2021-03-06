/****************************************Copyright (c)****************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:              led_display.h
** Latest modified Date:    2019-03-14
** Latest Version:          
** Descriptions:            相关函数及数据的声明
**--------------------------------------------------------------------------------------------------------
** Created by:             张桂荧
** Created date:            2019-03-14
** Version:                 
** Descriptions:            函数声明和数据声明
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include"led_display_cfg.h"

#ifdef __cplusplus
extern "C"{
#endif

//函数注释
/*********************************************************************************************************
** Function name:           led_display_scan
** Descriptions:            LED数码管扫描
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/	
extern void led_display_scan();

/*********************************************************************************************************
** Function name:           led_display_puts
** Descriptions:            LED数码管字符输入
** input parameters:        char *str
** output parameters:     	none
** Returned value:          成功:0
														失败:-1
*********************************************************************************************************/	
extern char led_display_puts(char* str);

/*********************************************************************************************************
** Function name:           led_display_clear
** Descriptions:            LED数码管清0
** input parameters:        none
** output parameters:     	none
** Returned value:          成功:0
														失败:-1
*********************************************************************************************************/	
extern char led_display_clear();

/*********************************************************************************************************
** Function name:           delay
** Descriptions:            软件延时
** input parameters:        none
** output parameters:     	none
** Returned value:          none
*********************************************************************************************************/	
extern void delay(unsigned int num);

extern void delay100us(unsigned int num);

extern void timer_init_with_time(int us);
	
extern unsigned char led_show_buf[6];

extern unsigned char show_table[][2];

	
#ifdef __cplusplus
}
#endif

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
