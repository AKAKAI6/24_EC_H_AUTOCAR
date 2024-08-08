#ifndef _MOTOR_H
#define _MOTOR_H
#include "ti_msp_dl_config.h"
#include "board.h"
#include "Corse.h"

typedef struct
{
	int pwm;
	int speed;
}Motor_t;
extern Motor_t Motor_R, Motor_L;
extern PidTypeDef ML_pid, MR_pid;

int Velocity_A(int TargetVelocity, int CurrentVelocity);
int Velocity_B(int TargetVelocity, int CurrentVelocity);
void Set_PWM(int pwma,int pwmb);
#endif