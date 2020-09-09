//
// Created by tsj-lt on 2020/9/8.
#include "main.h"
#include "gpio.h"

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7|GPIO_PIN_0, GPIO_PIN_SET);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_SET);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

    /*Configure GPIO pins : PB7 PB0 */
    GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /*Configure GPIO pins : PA0 PA1 PA4 */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pins : PA5 PA6 PA7 */
    GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pin : PB3 */
    GPIO_InitStruct.Pin = GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
void MX_GPIO_DEInit(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7|GPIO_PIN_0, GPIO_PIN_SET);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_SET);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

    /*Configure GPIO pins : PB7 PB0 */
    GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /*Configure GPIO pins : PA0 PA1 PA4 */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pins : PA5 PA6 PA7 */
    GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pin : PB3 */
    GPIO_InitStruct.Pin = GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* GPIO Ports Clock DISable */
    __HAL_RCC_GPIOB_CLK_DISABLE();
    __HAL_RCC_GPIOA_CLK_DISABLE();
}

/**
  * @brief 24V电源控制
  * @param None
  * @retval None
  */
void Water_24V(uint8_t i)
{
    if (i == ON)
        HAL_GPIO_WritePin(Port_24v, Pin_24v, GPIO_PIN_RESET);
    else if(i == OFF)
        HAL_GPIO_WritePin(Port_24v, Pin_24v, GPIO_PIN_SET);
}

/**
  * @brief 3.8V电源控制
  * @param None
  * @retval None
  */
void NB_3V8(uint8_t i)
{
    if (i == ON)
        HAL_GPIO_WritePin(Port_3v8, Pin_3v8, GPIO_PIN_RESET);
    else if(i == OFF)
        HAL_GPIO_WritePin(Port_3v8, Pin_3v8, GPIO_PIN_SET);
}

/**
  * @brief NB-IOT(L630)使能控制
  * @param None
  * @retval None
  */
void NB(uint8_t i)
{
    if (i == ON)
    {
        HAL_GPIO_WritePin(Port_3v8, Pin_3v8, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(Port_NB, Pin_NB, GPIO_PIN_SET);
    }
    else if(i == OFF)
    {
        HAL_GPIO_WritePin(Port_3v8, Pin_3v8, GPIO_PIN_SET);
        HAL_GPIO_WritePin(Port_NB, Pin_NB, GPIO_PIN_RESET);
    }
}

/**
  * @brief 电池电压采集使能控制
  * @param None
  * @retval None
  */
void ADC_Battery(uint8_t i)
{
    if (i == ON)
        HAL_GPIO_WritePin(Port_Battery, Pin_Battery, GPIO_PIN_RESET);
    else if(i == OFF)
        HAL_GPIO_WritePin(Port_Battery, Pin_Battery, GPIO_PIN_SET);
}

/**
  * @brief 电池电压采集使能控制
  * @param None
  * @retval None
  */
void Relay(uint8_t i)
{
    if (i == ON)
        HAL_GPIO_WritePin(Port_Relay, Pin_Relay, GPIO_PIN_RESET);
    else if(i == OFF)
        HAL_GPIO_WritePin(Port_Relay, Pin_Relay, GPIO_PIN_SET);
}

//

