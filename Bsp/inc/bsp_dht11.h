#ifndef __BSP_DHT11_H__
#define	__BSP_DHT11_H__

/* ����ͷ�ļ� ----------------------------------------------------------------*/
#include "main.h"
/* ���Ͷ��� ------------------------------------------------------------------*/
/************************ DHT11 �������Ͷ���******************************/
typedef struct
{
	uint8_t  humi_high8bit;		//ԭʼ���ݣ�ʪ�ȸ�8λ
	uint8_t  humi_low8bit;	 	//ԭʼ���ݣ�ʪ�ȵ�8λ
	uint8_t  temp_high8bit;	 	//ԭʼ���ݣ��¶ȸ�8λ
	uint8_t  temp_low8bit;	 	//ԭʼ���ݣ��¶ȸ�8λ
	uint8_t  check_sum;	 	    //У���
  float    humidity;        //ʵ��ʪ��
  float    temperature;     //ʵ���¶�  
} DHT11_Data_TypeDef;

/* �궨�� -------------------------------------------------------------------*/
/***********************   DHT11 �������Ŷ���  **************************/
#define DHT11_Dout_GPIO_CLK_ENABLE()              __HAL_RCC_GPIOB_CLK_ENABLE()
#define DHT11_Dout_PORT                           GPIOB
#define DHT11_Dout_PIN                            GPIO_PIN_13

/***********************   DHT11 �����궨��  ****************************/
#define DHT11_Dout_LOW()                          HAL_GPIO_WritePin(DHT11_Dout_PORT,DHT11_Dout_PIN,GPIO_PIN_RESET) 
#define DHT11_Dout_HIGH()                         HAL_GPIO_WritePin(DHT11_Dout_PORT,DHT11_Dout_PIN,GPIO_PIN_SET)
#define DHT11_Data_IN()	                          HAL_GPIO_ReadPin(DHT11_Dout_PORT,DHT11_Dout_PIN)

/* ��չ���� ------------------------------------------------------------------*/
/* �������� ------------------------------------------------------------------*/
void DHT11_Init( void );
uint8_t DHT11_Read_TempAndHumidity(DHT11_Data_TypeDef * DHT11_Data);
void Update_DHT11_Value(void);
void MqttData_Publis_ReadTempHum(uint8_t tmp,uint8_t hum);

#endif /* __ONEWIRE_DHT11_H__ */

