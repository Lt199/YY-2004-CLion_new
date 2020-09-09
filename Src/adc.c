//
// Created by tsj-lt on 2020/9/8.

/***************************************************************************************
;* 任务名称: App_Task_ADC_5_7
;*
;* 功能描述: ADC扫描采集
;*
;* 参    数: None
;*
;* 返 回 值: None
;*
;* 作　  者: tsj-LT

;* 日  　期: 2020年9月8日
;*----------------------------------------------------------------------------------------
;*****************************************************************************************/

#include "adc.h"
#include "kalman.h"

ADC_HandleTypeDef hadc1;

void App_Task_ADC_5_7(KFP KFP_AD[],ADC_Value AD)
{
    uint8_t i,j;
        if(AD.ADCRead == 0)          //只有程序读取值后才会重新采集
        {
            Water_24V(ON);
            ADC_Battery(ON);
            MX_GPIO_Init();
            HAL_Delay(10);
            HAL_ADCEx_Calibration_Start(&hadc1);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0,GPIO_PIN_RESET);
            for(j=0;j<20;j++)				//采集20次并滤波输出一次数据
                for(i=0;i<3;i++)
                {
                    HAL_ADC_Start(&hadc1);
                    HAL_ADC_PollForConversion(&hadc1,50);

                    AD.Battery_v = kalmanFilter(&KFP_AD[0],(float)HAL_ADC_GetValue(&hadc1));	//kalman滤波
                    AD.water_ch1_v = kalmanFilter(&KFP_AD[1],(float)HAL_ADC_GetValue(&hadc1));	//kalman滤波
                    AD.water_ch2_v = kalmanFilter(&KFP_AD[2],(float)HAL_ADC_GetValue(&hadc1));	//kalman滤波

                }
            Water_24V(OFF);
            ADC_Battery(OFF);
            MX_GPIO_DEInit();
            AD.ADCRead = 1;              //若ADCRead = 1，则不会重新读取ADC
        }
        else ;
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
void MX_ADC1_Init(void)
{

    /* USER CODE BEGIN ADC1_Init 0 */

    /* USER CODE END ADC1_Init 0 */

    ADC_ChannelConfTypeDef sConfig = {0};
    ADC_AnalogWDGConfTypeDef AnalogWDGConfig = {0};

    /* USER CODE BEGIN ADC1_Init 1 */

    /* USER CODE END ADC1_Init 1 */
    /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
    */
    hadc1.Instance = ADC1;
    hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
    hadc1.Init.Resolution = ADC_RESOLUTION_12B;
    hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
    hadc1.Init.ScanConvMode = ADC_SCAN_SEQ_FIXED;
    hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
    hadc1.Init.LowPowerAutoWait = DISABLE;
    hadc1.Init.LowPowerAutoPowerOff = DISABLE;
    hadc1.Init.ContinuousConvMode = DISABLE;
    hadc1.Init.NbrOfConversion = 1;
    hadc1.Init.DiscontinuousConvMode = ENABLE;
    hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
    hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
    hadc1.Init.DMAContinuousRequests = DISABLE;
    hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
    hadc1.Init.SamplingTimeCommon1 = ADC_SAMPLETIME_1CYCLE_5;
    hadc1.Init.OversamplingMode = DISABLE;
    hadc1.Init.TriggerFrequencyMode = ADC_TRIGGER_FREQ_HIGH;
    if (HAL_ADC_Init(&hadc1) != HAL_OK)
    {
        Error_Handler();
    }
    /** Configure Regular Channel
    */
    sConfig.Channel = ADC_CHANNEL_5;
    sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
    if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
    {
        Error_Handler();
    }
    /** Configure Regular Channel
    */
    sConfig.Channel = ADC_CHANNEL_6;
    sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
    if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
    {
        Error_Handler();
    }
    /** Configure Regular Channel
    */
    sConfig.Channel = ADC_CHANNEL_7;
    sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
    if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
    {
        Error_Handler();
    }
    /** Configure Analog WatchDog 2
    */
    AnalogWDGConfig.WatchdogMode = ADC_ANALOGWATCHDOG_SINGLE_REG;
    if (HAL_ADC_AnalogWDGConfig(&hadc1, &AnalogWDGConfig) != HAL_OK)
    {
        Error_Handler();
    }
    /* USER CODE BEGIN ADC1_Init 2 */

    /* USER CODE END ADC1_Init 2 */

}
//

