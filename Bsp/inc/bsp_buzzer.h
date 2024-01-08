#ifndef __BUZZER_H_
#define __BUZZER_H_
#include "main.h"

#define BUZZER_PIN      GPIO_PIN_1
#define BUZZER_GPIO     GPIOB

extern IWDG_HandleTypeDef IWDG_Handler;


void Buzzer_KeySound(void);
void Buzzer_KeySound_Off(void);

void Buzzer_Fan_Error_Sound(void);
void Buzzer_Ptc_Error_Sound(void);





#endif 
