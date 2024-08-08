#include "motor.h"

PidTypeDef ML_pid = {1.0f, 0.0f, 0.0f, 3600.0f, 0.0f}, 
		   MR_pid = {1.0f, 0.0f, 0.0f, 3600.0f, 0.0f};
			
Motor_t Motor_R, Motor_L;
void Set_PWM(int pwma,int pwmb)
{
	
	if(pwma>0) 
	{
		if(ABS(pwma) > 1500)
			pwma = 1500;
		DL_GPIO_setPins(AIN1_PORT,AIN1_PIN_12_PIN);
		DL_GPIO_clearPins(AIN2_PORT,AIN2_PIN_13_PIN);
		DL_Timer_setCaptureCompareValue(PWM_0_INST,ABS(pwma),GPIO_PWM_0_C0_IDX);
	}
	else
	{
		if(ABS(pwma) > 1500)
			pwma = -1500;
		DL_GPIO_setPins(AIN2_PORT,AIN2_PIN_13_PIN);
		DL_GPIO_clearPins(AIN1_PORT,AIN1_PIN_12_PIN);
		DL_Timer_setCaptureCompareValue(PWM_0_INST,ABS(pwma),GPIO_PWM_0_C0_IDX);
	}
	if(pwmb>0)
	{
		if(ABS(pwmb) > 1500)
			pwma = 1500;
		DL_GPIO_setPins(BIN1_PORT,BIN1_Pin_Bin1_PIN);
		DL_GPIO_clearPins(BIN2_PORT,BIN2_Pin_Bin2_PIN);
		DL_Timer_setCaptureCompareValue(PWM_0_INST,ABS(pwmb),GPIO_PWM_0_C1_IDX);
	}
    else
	{
		if(ABS(pwmb) > 1500)
			pwma = -1500;
		DL_GPIO_setPins(BIN2_PORT,BIN2_Pin_Bin2_PIN);
		DL_GPIO_clearPins(BIN1_PORT,BIN1_Pin_Bin1_PIN);
		DL_Timer_setCaptureCompareValue(PWM_0_INST,ABS(pwmb),GPIO_PWM_0_C1_IDX);
	}		

}



