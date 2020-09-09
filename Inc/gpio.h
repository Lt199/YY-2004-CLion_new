//
// Created by tsj-lt on 2020/9/8.
//

#ifndef YY2004_NEW_GPIO_H
#define YY2004_NEW_GPIO_H

void MX_GPIO_Init(void);
void MX_GPIO_DEInit(void);
void Water_24V(uint8_t i);
void NB_3V8(uint8_t i);
void ADC_Battery(uint8_t i);
void Relay(uint8_t i);

#define ON   1
#define OFF  2

#define Port_24v GPIOB
#define Pin_24v GPIO_PIN_0

#define Port_3v8 GPIOB
#define Pin_3v8 GPIO_PIN_7

#define Port_Battery GPIOA
#define Pin_Battery GPIO_PIN_0

#define Port_Relay GPIOA
#define Pin_Relay GPIO_PIN_1

#define Port_NB GPIOA
#define Pin_NB GPIO_PIN_4



#endif //YY2004_NEW_GPIO_H




