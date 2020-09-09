//
// Created by tsj-lt on 2020/9/8.
#include "LPcon.h"
#include "main.h"
/***************************************************************************************
;* 函数名称: WKUP_EnterStandby
;*
;* 功能描述: 进入待机模式函数
;*
;* 参    数: None
;*
;* 返 回 值: None
;*
;* 作　  者: tsj-LT

;* 日  　期: 2020年9月8日
;*----------------------------------------------------------------------------------------
;*****************************************************************************************/
void WKUP_EnterStandby(void)
{
    __HAL_RCC_APB2_FORCE_RESET();
    __HAL_RCC_PWR_CLK_ENABLE();

    __HAL_PWR_CLEAR_FLAG(PWR_FLAG_SB);          	//清唤醒标志
    __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WUF);				//清唤醒标志
    //HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);  	//按键唤醒暂时不用
    HAL_PWR_EnterSTANDBYMode();						//进入休眠
}
//

