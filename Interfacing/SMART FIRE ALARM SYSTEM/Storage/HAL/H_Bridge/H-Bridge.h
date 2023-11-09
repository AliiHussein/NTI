/*
 * H_Bridge.h
 *
 * Created: 11/5/2023 9:54:52 AM
 *  Author: Mahmoud Nassef
 */ 


#ifndef H_BRIDGE_H_
#define H_BRIDGE_H_

#define PWM    3
#define DIR    5
#define ENABLE 6  

void Motor_Init(void);

void Rotate_Forward(float32 pwm);

void Rotate_Backward(float32 pwm);

void Motor_Stop(void);





#endif /* H-BRIDGE_H_ */