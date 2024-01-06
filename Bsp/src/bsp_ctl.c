#include "bsp_ctl.h"
#include "bsp.h"

uint8_t (*power_state)(void);

uint8_t (*wifi_state)(void);
uint8_t (*model_state)(void);
uint8_t (*ptc_state)(void);
uint8_t (*plasma_state)(void);
uint8_t (*bug_state)(void);

static uint8_t power_default_fun(void);

static uint8_t wifi_default_fun(void);
static uint8_t model_default_fun(void);
static uint8_t ptc_default_fun(void);
static uint8_t  plasma_default_fun(void);
static uint8_t  bug_default_fun(void);
/*********************************************************************
 *  *
    *Function Name: ctl_Init(void)
    *Function: 
    *Input Ref: NO
    *Return Ref:  NO
    * 
**********************************************************************/
void ctl_Init(void)
{
	Power_Fun_Handler(power_default_fun);
	Wifi_Fun_Handler(wifi_default_fun);
	Ai_Fun_Handler(model_default_fun);
	Ptc_Fun_Handler(ptc_default_fun);
	Plasma_Fun_Handler(ptc_default_fun);
	Bug_Fun_Handler(ptc_default_fun);

}

/*********************************************************************
 *  *
    *Function Name: ctl_Init(void)
    *Function: 
    *Input Ref: NO
    *Return Ref:  NO
    * 
**********************************************************************/
static uint8_t power_default_fun(void)
{

  
   	 if(run_t.gPower_On==POWER_ON) return POWER_ON;
	 else return POWER_OFF;
	 

}

static uint8_t wifi_default_fun(void)
{
     if(run_t.wifi_gPower_On==1) return 1;
	 else 
	 	return 0;

}
static uint8_t model_default_fun(void)
{
     if(run_t.gModel ==1)return 1;
	 else if(run_t.gModel ==2)return 2;
	 else 
	 	return 0;


}
static uint8_t ptc_default_fun(void)
{
     if(run_t.gDry==1)return 1;
	 else 
	 	return 0;

}
static uint8_t  plasma_default_fun(void)
{
    if(run_t.gPlasma==1)return 1;
	else 
	 	return 0; 
}
static uint8_t bug_default_fun(void)
{
   if(run_t.gUlransonic==1)return 1;
	 else 
	 	return 0;


}



/*********************************************************************
 *  *
    *Function Name: ctl_Init(void)
    *Function: 
    *Input Ref: NO
    *Return Ref:  NO
    * 
**********************************************************************/
void Power_Fun_Handler(uint8_t(*power_handler)(void))
{
   power_state = power_handler;

}

void Wifi_Fun_Handler(uint8_t (*wifi_handler)(void))
{
		wifi_state = wifi_handler;
}
void Ai_Fun_Handler(uint8_t(*ai_handler)(void))
{
	model_state = ai_handler;
}
void Ptc_Fun_Handler(uint8_t (*ptc_handler)(void))
{
	ptc_state = ptc_handler;
}
void Plasma_Fun_Handler(uint8_t (*plasma_handler)(void))
{
	plasma_state = plasma_handler;
}
void Bug_Fun_Handler(uint8_t(*bug_handler)(void))
{

	bug_state = bug_handler;

}


