#include "fsm.h"
#include "motor.h"
#include "Corse.h"
#include "mpu6050.h"
#include "Gray_detect.h"
#include "led.h"
Issue_Enum Issue_s;
Mode_T Mode_s;
uint8_t select_flag = 0;
uint8_t rgb_flag = 0 ;
float imu_m_iss1 = 0.0f ;
uint8_t Issue_flag = 0 ;
uint8_t Issue2_stop = 0 ;
uint8_t Issue3_imuflag = 110; 
uint8_t Issue4_imuflag = 115 ;
uint8_t Issue5_imuflag = 115 ;

uint8_t Issue_first = 1 ;
void RGB_BEEP(uint8_t ena)
{
	static uint8_t flag_1 = 1;
	uint8_t flag_2 =ena;
	flag_1++;
	if(flag_1 > 20)
	{
		flag_1 = 0 ;
		flag_2 = 0 ;
		Issue_flag=0 ;
	}
	if(flag_2 )
	{
		DL_GPIO_setPins(GPIOB, RGB_Red_PIN_26_PIN);		// RGB红灯
		DL_GPIO_setPins(PORTA_PORT, PORTA_beep_PIN);	
		
	}
	else if(flag_2 == 0)
	{
		DL_GPIO_clearPins(PORTA_PORT, PORTA_beep_PIN);
		DL_GPIO_clearPins(GPIOB, RGB_Red_PIN_26_PIN);		// RGB红灯
	}
	
}



void Issue_Select(Key_t key_1)
{
	
	if(key_1.K1 == 1)
	{
		select_flag++;
		key_1.K1 = 0;
		LED_Toggle();
	}
	
	if(select_flag > 5)
	{
		select_flag = 1;
	}
	switch(select_flag)
	{
		case 1 :
			Issue_s = ISSUE_1;
			break;
		case 2 :
			Issue_s = ISSUE_2;
			break;
		case 3 :
			Issue_s = ISSUE_3;
			break;
		case 4 :
			Issue_s = ISSUE_4;
			break;
		case 5 :
			Issue_s = ISSUE_5;//提速版
			break;
		default :
			break;
	}
}
void Mode_Process(Mode_T mode)
{
	switch(mode.mode)
	{
		case GRAY_M :
			switch(Issue_s)
			{
				case ISSUE_2:
					Motor_L.pwm = -800-gray_status[0]*60;//900       //第二问
					Motor_R.pwm = -800+gray_status[0]*60;				//第二问
					break;
				case ISSUE_3:
					Motor_L.pwm = -800-gray_status[0]*97;//1500       //第三问
					Motor_R.pwm = -800+gray_status[0]*97;				//第三问		
					break;
				case ISSUE_4:
					Motor_L.pwm = -850-gray_status[0]*105;//1500       //第三问， 850完赛版
					Motor_R.pwm = -850+gray_status[0]*105;				//第三问		
					break;
				case ISSUE_5:
					Motor_L.pwm = -900-gray_status[0]*110;//1500       //第三问， 850完赛版
					Motor_R.pwm = -900+gray_status[0]*110;	
					break;//第三问	
				default:
					break;
			
			}
			Set_PWM(Motor_L.pwm, Motor_R.pwm);
			break;
		case IMU_M :
			

			switch(Issue_s)
				{
					case ISSUE_1:
							Motor_L.pwm = -900+(int)PID_Calc(&Corse_pid_issue2, gyro.yaw, imu_m_iss1+gyro.init_yaw);//1500
							Motor_R.pwm = -900-(int)PID_Calc(&Corse_pid_issue2, gyro.yaw , imu_m_iss1+gyro.init_yaw);	
						break;
					case ISSUE_2:
							Motor_L.pwm = -900+(int)PID_Calc(&Corse_pid_issue2, gyro.yaw, imu_m_iss1+gyro.init_yaw);//1500
							Motor_R.pwm = -900-(int)PID_Calc(&Corse_pid_issue2, gyro.yaw , imu_m_iss1+gyro.init_yaw);	
						break;
					case ISSUE_3:
							Motor_L.pwm = -800+(int)PID_Calc(&Corse_pid_issue3, gyro.yaw, imu_m_iss1+gyro.init_yaw);//1500
							Motor_R.pwm = -800-(int)PID_Calc(&Corse_pid_issue3, gyro.yaw , imu_m_iss1+gyro.init_yaw);	
						break;
					case ISSUE_4:
							Motor_L.pwm = -850+(int)PID_Calc(&Corse_pid_issue4, gyro.yaw, imu_m_iss1+gyro.init_yaw);//850完赛版
							Motor_R.pwm = -850-(int)PID_Calc(&Corse_pid_issue4, gyro.yaw , imu_m_iss1+gyro.init_yaw);	
//							if( ABS(imu_m_iss1+gyro.init_yaw -  gyro.yaw) == 0.3f)
//								Motor_L.pwm = Motor_R.pwm = -850;
						break;
					case ISSUE_5:
							Motor_L.pwm = -1100+(int)PID_Calc(&Corse_pid_issue5, gyro.yaw, imu_m_iss1+gyro.init_yaw);//850完赛版, -1000提速版
							Motor_R.pwm = -1100-(int)PID_Calc(&Corse_pid_issue5, gyro.yaw , imu_m_iss1+gyro.init_yaw);	
//							if( ABS(imu_m_iss1+gyro.init_yaw -  gyro.yaw) == 0.3f)
//								Motor_L.pwm = Motor_R.pwm = -1000;
						break;
					default:
						break;
				
				}
		
			Set_PWM(Motor_L.pwm, Motor_R.pwm);
		
			break;
		case STOP:
			Set_PWM(0,  0);		
			break;		
		case STOP_ISSUE1:
			Set_PWM(0,  0);		
			if( Issue_first)		
			{
				DL_GPIO_setPins(GPIOB, RGB_Red_PIN_26_PIN);		// RGB红灯
				DL_GPIO_setPins(PORTA_PORT, PORTA_beep_PIN);
				delay_ms(100);
				DL_GPIO_clearPins(PORTA_PORT, PORTA_beep_PIN);
				DL_GPIO_clearPins(GPIOB, RGB_Red_PIN_26_PIN);		// RGB红灯
				Issue_first = 0 ;
				
			}
			break;
			
		default :
			break;
	}
}

void Issue_process(Issue_Enum issue)
{
	switch(issue)
	{
		case ISSUE_1 :
			Mode_s.mode = IMU_M;
		
			imu_m_iss1 = 0.0f;
			
			if(Mode_s.stop_flag >= 5)
			{
				Mode_s.mode = STOP_ISSUE1;//停止并亮灯
				
			}
			Mode_Process(Mode_s);
			break;
		case ISSUE_2 :
			if(Mode_s.gray_flag )
			{
				rgb_flag = 1 ;
				Mode_s.mode = GRAY_M;
				Mode_s.gray_flag = 0 ;
				imu_m_iss1 = -174.3f;//-180.0f, issue2
					
			}
			
			else if(Mode_s.imu_flag > 75 )//75，ISUUE2, 200, ISSUE3
			{
				
				Mode_s.mode = IMU_M;
				Mode_s.imu_flag = 0 ;
			}
			
			if(Mode_s.mode != Mode_s.last_mode && rgb_flag)	
				{	
					Issue_flag = 1;//亮灯
					Issue2_stop++;
					
				}
			if(Issue2_stop == 4)
				{
					Mode_s.mode = STOP;//停止
					
					Issue_flag = 1 ;//亮灯
					Issue2_stop = 0 ;
				}					
			Mode_s.last_mode = Mode_s.mode;
			Mode_Process(Mode_s);
			break;
		case ISSUE_3 :		
			if(Mode_s.gray_flag )
			{
				rgb_flag = 1 ;
				Mode_s.mode = GRAY_M;
				Mode_s.gray_flag = 0 ;
				imu_m_iss1 = -108.5f;//107.28
			}
			else if(Mode_s.imu_flag > Issue3_imuflag )//，ISUUE2, 115, ISSUE3
			{
				Mode_s.mode = IMU_M;
				Mode_s.imu_flag = 0 ;
			}
			
			if(Mode_s.mode != Mode_s.last_mode && rgb_flag)	
				{	
					Issue_flag = 1;//亮灯
					Issue2_stop++;
				}
			if(Issue2_stop == 3)
				Issue3_imuflag = 95;
			if(Issue2_stop == 4)
				{
					Mode_s.mode = STOP;//停止
					
					Issue_flag = 1 ;//亮灯
					Issue2_stop = 0 ;
				}
			
			Mode_s.last_mode = Mode_s.mode;
			Mode_Process(Mode_s);			
			break;
		case ISSUE_4 :
			if(Mode_s.gray_flag )
			{
				rgb_flag = 1 ;
				Mode_s.mode = GRAY_M;
				imu_m_iss1 = -108.5f;//稳完108.8
				
				Mode_s.gray_flag = 0 ;
			}
			else if(Mode_s.imu_flag > Issue4_imuflag )//150稳完
			{
				
				Mode_s.mode = IMU_M;				
				Mode_s.imu_flag = 0 ;
				
			}
			
			if(Mode_s.mode != Mode_s.last_mode && rgb_flag)	
				{	
					Issue_flag = 1;//亮灯
					Issue2_stop++;
					
				}
			if(Issue2_stop == 3 || Issue2_stop == 7 || Issue2_stop == 11|| Issue2_stop == 15)
				imu_m_iss1 = 0.0f;	
			
			if(Issue2_stop == 15)
				Issue4_imuflag = 85;
			else if(Issue2_stop == 1)
				Issue4_imuflag = 90;
			else if(Issue2_stop == 2)
				Issue4_imuflag = 115 ;
			if(Issue2_stop == 16)
				{
					Mode_s.mode = STOP;//停止
					
					Issue_flag = 1 ;//亮灯
					
					Issue2_stop = 0 ;
				}					
			Mode_s.last_mode = Mode_s.mode;
			Mode_Process(Mode_s);
			break;
		case 5:
			if(Mode_s.gray_flag )
			{
				rgb_flag = 1 ;
				Mode_s.mode = GRAY_M;
				imu_m_iss1 = -106.7f;//稳完108.8
				
				Mode_s.gray_flag = 0 ;
			}
			else if(Mode_s.imu_flag > Issue5_imuflag )//150稳完
			{
				
				Mode_s.mode = IMU_M;				
				Mode_s.imu_flag = 0 ;
				
			}
			
			if(Mode_s.mode != Mode_s.last_mode && rgb_flag)	
				{	
					Issue_flag = 1;//亮灯
					Issue2_stop++;
					
				}
			if(Issue2_stop == 3 || Issue2_stop == 7  || Issue2_stop == 15)
					imu_m_iss1 = 1.0f;
			else if(Issue2_stop == 11)
				imu_m_iss1 = 0.0f;
			if(Issue2_stop == 15)
				Issue5_imuflag = 105;
			if(Issue2_stop == 16)
				{
					Mode_s.mode = STOP;//停止
					
					Issue_flag = 1 ;//亮灯
					
					Issue2_stop = 0 ;
				}					
			Mode_s.last_mode = Mode_s.mode;
			Mode_Process(Mode_s);
			break;
		default :
			break;
	}
}
