#ifndef __BSP_H_
#define __BSP_H_
#include "main.h"

extern uint8_t (*power_state)(void);
extern uint8_t (*wifi_state)(void);
extern uint8_t (*model_state)(void);
extern uint8_t (*ptc_state)(void);
extern uint8_t (*plasma_state)(void);
extern uint8_t (*bug_state)(void);


void Power_Fun_Handler(uint8_t(*power_handler)(void));
void Wifi_Fun_Handler(uint8_t (*wifi_handler)(void));
void Ai_Fun_Handler(uint8_t(*ai_handler)(void));
void Ptc_Fun_Handler(uint8_t (*ptc_handler)(void));
void Plasma_Fun_Handler(uint8_t (*plasma_handler)(void));
void Bug_Fun_Handler(uint8_t(*bug_handler)(void));



void ctl_Init(void);





#endif 
