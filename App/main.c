#include "include.h"


/********************************************
------------------------------------
软件版本： IAR 7.2 or MDK 5.17
目标核心： MK60DN512VLL10
============================================
MT9V032接线定义：
------------------------------------ 
模块管脚            单片机管脚
SDA(51的RX)         E8
SCL(51的TX)         E9
场中断              C7
行中断				未使用，因此不接
像素中断            C2            
数据口              C8-C15 


============================================

分辨率是                160*120
摄像头参数设置可以到    SEEKFREE-->h_file-->SEEKFREE_MT9V032.h

 
*********************************************/  

/*!
*  @brief      main函数
*  @since      v5.0
*  @note       山外摄像头 LCD 测试实验
*/
void  main(void)
{
  
  ZZF_Init();
  LCD_Init();        //OLED 屏幕初始化
  enable_irq(PORTA_IRQn);//开图像采集中断；
  while(1)
  {
    if(mt9v032_finish_flag)
    {
      LCD_show_ZZF_image();
      
      mt9v032_finish_flag = 0;
      enable_irq(PORTC_IRQn);
    }
  }
}



