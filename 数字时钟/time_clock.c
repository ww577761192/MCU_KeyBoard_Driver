/****************************************Copyright (c)****************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:              time_clock.c
** Latest modified Date:    2019-03-21
** Latest Version:          
** Descriptions:            数码管显示时间
**--------------------------------------------------------------------------------------------------------
** Created by:             	张桂荧
** Created date:            2019-03-21
** Version:                 
** Descriptions:            宏定义与引脚配置，头文件相关
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/

#include"time_clock.h"
#include"C:\Users\CreaQi\OneDrive\文档\课程\单片机\uVision_Project\键盘\key_board.h"

code char* arrhour[24]={"0","1","2","3","4","5","6","7","8","9","10",\
"11","12","13","14","15","16","17","18","19","20","21","22","23"};
code char* arrminute[60]={	"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", \
										"10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", \
										"21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31",\ 
										"32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", \
										"43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", \
										"54", "55", "56", "57", "58", "59"};
code char* arrsecond[60]={	"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", \
										"10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",\ 
										"21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", \
										"32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42",\ 
										"43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", \
										"54", "55", "56", "57", "58", "59"};


int count=0;

/*********************************************************************************************************
** Function name:           display_time
** Descriptions:            通过计数来模拟时间，并在数码管上展示
** input parameters:        char h, char m, char s
** output parameters:     	none
** Returned value:          none
*********************************************************************************************************/										
void display_time(char h, char m, char s){
	char buf[9],k;
	concat(buf,arrhour[h],arrminute[m],arrsecond[s]);
	//concat(buf,"12","30","25");	
	led_display_puts(buf);
			//运行一次大约执行31条指令（不考虑进入if）
			//有的指令周期为1，有的为2，我们取平均值1.5
			//1.5*31=46.5,   46.5*21500约等于10^6，也就是1s
			while(1){				
				led_display_scan();	
				k = get_key();
				key_shake_eliminate();
				if(k==-2) break;				
				count++;
				if(count==7){
					count=0;										
					s++;
					if(s==60){
						s=0;
						m++;
						if(m==60){
							h++;
							if(h==24)
							h=0;						
						}
					}
				concat(buf,arrhour[h],arrminute[m],arrsecond[s]);
				led_display_puts(buf);
			}
		}

}

/*void display_time1(char *bf){
	char buf[9],k;
	//concat(buf,arrhour[h],arrminute[m],arrsecond[s]);
	//concat(buf,"12","30","25");	
	led_display_puts(bf);
			//运行一次大约执行31条指令（不考虑进入if）
			//有的指令周期为1，有的为2，我们取平均值1.5
			//1.5*31=46.5,   46.5*21500约等于10^6，也就是1s
			while(1){				
				led_display_scan();	
				k = get_key();
				key_shake_eliminate();
				if(k==-2) break;				
				count++;
				if(count==7){
					count=0;										
					s++;
					if(s==60){
						s=0;
						m++;
						if(m==60){
							h++;
							if(h==24)
							h=0;						
						}
					}
				concat(buf,arrhour[h],arrminute[m],arrsecond[s]);
				led_display_puts(buf);
			}
		}
}*/


/*********************************************************************************************************
** Function name:           concat
** Descriptions:            将小时，分钟，秒数三个字符串拼接到buf字符串
** input parameters:        char *h,char *m, char *s
** output parameters:     	buf
** Returned value:          none
*********************************************************************************************************/
void concat(char buf[9],char *h,char *m, char *s){
	buf[0] = *h;
	buf[1] = h[1];
	buf[2]='.';
	buf[3] = *m;
	buf[4] = m[1];
	buf[5]='.';
	buf[6] = *s;
	buf[7] = s[1];
	buf[8] = '\0';
}

void set_time(){
	

}
										
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

