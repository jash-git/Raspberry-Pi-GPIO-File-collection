/*
修改 cmdline.txt文件
>cd /boot/
>sudo vim cmdline.txt


删除【】之间的部分
dwc_otg.lpm_enable=0 【console=ttyAMA0,115200】 kgdboc=ttyAMA0,115200 console=tty1 root=/dev/mmcblk0p2 rootfstype=ext4 elevator=deadline rootwait


修改 inittab文件
>cd /etc/
>sudo vim inittab

注释掉最后一行内容:，在前面加上 # 号
#T0:23:respawn:/sbin/getty -L ttyAMA0 115200 vt100


sudo reboot 重启
*/
#include<reg52.h>
#include"serial.h"

/**********function****************/
bit isOpenPressed(void);
bit isClosePressed(void);
void delay(unsigned int t);
/*********************************/

sbit closeButton = P2^0;   //与关闭按键相连的引脚
sbit openButton  = P2^1;   //与打开按键相连的引脚

void main(void)
{

      closeButton = 1;      //拉高
      openButton  = 1;      //拉高
      
      EA =1;              //打开总中断
      serial_init(9600);  //初始化51串口
              
      while(1)
      {
          if(isClosePressed())     //如果关闭按钮按下
          {
                  serial_write(0);  //发送数据 0给树莓派
                delay(10);
          }
    
          else if(isOpenPressed()) //如果打开按钮按下
          {
                  serial_write(1);     //发送数据 1给树莓派
                delay(10);
          }
      }
}


bit isOpenPressed(void)
{
       bit press =0;

       if(0==openButton)
       {
               delay(5);
            if(0==openButton)
            {
                 while(!openButton)
                 ;
                 press = 1;
            }
       }
        
       return press;    
}

bit isClosePressed(void)
{
       bit press =0;

       if(0==closeButton)
       {
               delay(5);
            if(0==closeButton)
            {
                 while(!closeButton)
                 ;
                  press = 1;
            }
       }
        
       return press;    
}


void delay(unsigned int t)
{
    unsigned int  i    ;
    unsigned char j;
    for(i = t;i>0;i--)
        for(j=120;j>0;j--)
            ;
}