//
// Created by tsj-lt on 2020/9/8.
//

#ifndef YY2004_NEW_ADC_H
#define YY2004_NEW_ADC_H

#include "main.h"
#include "gpio.h"
#include "kalman.h"

typedef struct{

    uint32_t Battery_v;     //电池电压采集值
    uint32_t water_ch1_v;   //通道1水压/水位电压采集值
    uint32_t water_ch2_v;   //通道2水压/水位电压采集值
    uint8_t ADCRead;

}ADC_Value;

void MX_ADC1_Init(void);
void App_Task_ADC_5_7(KFP KFP_AD[],ADC_Value AD);

#endif //YY2004_NEW_ADC_H
