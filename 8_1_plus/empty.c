#include "board.h"
#include "stdio.h"
#include "key.h"
#include "led.h"
#include "motor.h"
#include "encoder.h"
#include "bsp_mpu6050.h"
#include "inv_mpu.h"
#include "mpu6050.h"
#include "Corse.h"
#include "math.h"
#include "Gray_detect.h"
#include "fsm.h"
volatile uint32_t _5ms_count = 0;
uint8_t Yaw_initflag = 1 ;

int status;
uint8_t Imu_flag = 1;
uint8_t Start_flag = 0;

void my_init(void)
{
	

	SYSCFG_DL_init();

	DL_Timer_startCounter(PWM_0_INST); // ����PWM���
	//
	NVIC_ClearPendingIRQ(GPIO_MULTIPLE_GPIOA_INT_IRQN);
	NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);			  // ����жϱ�־λ
	NVIC_ClearPendingIRQ(TIMER_0_INST_INT_IRQN);		  // �����ʱ���жϱ�־λ
	NVIC_ClearPendingIRQ(TIMER_GYRO_INST_INT_IRQN);		  // ��������Ƕ�ʱ���жϱ�־λ
	NVIC_ClearPendingIRQ(I2C_MPU6050_INST_INT_IRQN);	  // ���IIC�жϱ�־λ
	//	//ʹ���ж�
	NVIC_EnableIRQ(GPIO_MULTIPLE_GPIOA_INT_IRQN);
	NVIC_EnableIRQ(UART_0_INST_INT_IRQN);			// ��������0�ж�
	
	
	NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);			// ������ʱ���ж�
	NVIC_EnableIRQ(TIMER_GYRO_INST_INT_IRQN);		// ���������Ƕ�ʱ���ж�
	NVIC_EnableIRQ(I2C_MPU6050_INST_INT_IRQN);		// ����IIC�ж�
	
	
	MPU6050_Init();
	Mode_s.imu_flag = 1000;
	LED_OFF();
	
}
extern uint8_t Issue_flag ;
int main(void)
{
	my_init();

	uint8_t ret = 1;

	float pitch = 0, roll = 0, yaw = 0;

	
	while (Imu_flag)
	{
		Imu_flag = mpu_dmp_init();
		delay_ms(200);
		
	}
	
	while (1)
	{
		Key_scan();//�������
		
		Issue_Select(Button);//��Ŀѡ��
		
		
	}
}
float Test_speed = 0.0f;
void TIMER_0_INST_IRQHandler(void)
{
	if (DL_TimerA_getPendingInterrupt(TIMER_0_INST))
	{
		if (DL_TIMER_IIDX_ZERO)
		{
			_5ms_count++;
			
			
			Sensor_GetState();//�Ҷȼ��
			gray_check();//�Ҷȼ���
			
			if (_5ms_count % 2 == 0)
			{
				if(Yaw_initflag)
					status++;
				if(Imu_flag == 0 && Start_flag)
				{
					
					Issue_process(Issue_s);//��Ŀִ��
				}
			}
			else if(_5ms_count % 3 == 0)
			{
				if(Issue_flag )
				{
					RGB_BEEP(1);
				}
			}
			if(_5ms_count > 1000)
			{
				_5ms_count = 0 ;
			
			}
			if(status > 2000 && Yaw_initflag) 
			{
				Yaw_initflag = 0 ;
				Start_flag = 1 ;
				status = 0 ;
				gyro.init_yaw  = gyro.yaw ;
			}
			
		}
	}
}
