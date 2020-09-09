//
// Created by tsj-lt on 2020/9/8.
//

#ifndef YY2004_NEW_KALMAN_H
#define YY2004_NEW_KALMAN_H


//kalman滤波结构体类型定义
typedef struct
{
    float LastP;		//上次估算协方差 初始化值为0.02
    float Now_P;		//当前估算协方差 初始化值为0
    float out;			//卡尔曼滤波器输出 初始化值为0
    float Kg;				//卡尔曼增益 初始化值为0
    float Q;				//过程噪声协方差 初始化值为0.001
    float R;				//观测噪声协方差 初始化值为0.543
}KFP;//Kalman Filter parameter

float kalmanFilter(KFP *kfp,float input);




/**
 *卡尔曼滤波器
 *@param KFP *kfp 卡尔曼结构体参数
 *   float input 需要滤波的参数的测量值（即传感器的采集值）
 *@return 滤波后的参数（最优值）
 */


#endif //YY2004_NEW_KALMAN_H


