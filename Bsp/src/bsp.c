#include  "bsp.h"

/*
*********************************************************************************************************
*	函 数 名: bsp_Idle
*	功能说明: 空闲时执行的函数。一般主程序在for和while循环程序体中需要插入 CPU_IDLE() 宏来调用本函数。
*			 本函数缺省为空操作。用户可以添加喂狗、设置CPU进入休眠模式的功能。
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void bsp_Idle(void)
{
	/* --- 喂狗 */
    if(run_t.gTimer_food_dog >4){
	  run_t.gTimer_food_dog=0;
      IWDG_Feed();
     

	}
		
	/* --- 让CPU进入休眠，由Systick定时中断唤醒或者其他中断唤醒 */
	
    /* 例如 emWin 图形库，可以插入图形库需要的轮询函数 */
	//GUI_Exec();
	
	/* 例如 uIP 协议，可以插入uip轮询函数 */
	//TOUCH_CapScan();
	
  

}


void Power_On_From_Display_Hanlder(void)
{

    switch(run_t.power_on_from_display_flag){

	case 1:
      Buzzer_KeySound();
	  run_t.power_on_from_display_flag =2;

	break;


	case 2:
	  SendWifiData_To_Cmd(0x54); //0x52= 'R'
	
	 
	  run_t.rx_command_tag=POWER_ON;
	  run_t.power_on_from_display_flag =3;

    
    break;

	case 3:


	 
	  Update_DHT11_Value();
	  PTC_SetHigh();

	
	run_t.power_on_from_display_flag =0;
	break;

	default:

	break;

    }

}

void Power_Off_From_Display_Hanlder(void)
{

    switch(run_t.power_off_from_display_flag){

	case 1:
      Buzzer_KeySound();
	  run_t.power_off_from_display_flag =2;

	break;

	case 2:
	  SendWifiData_To_Cmd(0x53); //0x52= 'R'

	  run_t.rx_command_tag=POWER_OFF;
	   run_t.power_off_from_display_flag =3;

	break;

	case 3:
		  
		  PTC_SetLow();
       run_t.power_off_from_display_flag =0xff;
	break;

	default:

	break;

    }

}
