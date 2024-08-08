#include "Gray_detect.h"
#include "ti_msp_dl_config.h"
#include "fsm.h"
uint8_t sensor_val[9];//灰度返回值
uint16_t gray_state = 0;//当前灰度状态
volatile int gray_status[2]={0},gray_status_backup[2][20] = {0};//灰度传感器状态与历史值
uint32_t gray_status_worse=0;	//灰度管异常状态计数器
 
//白高黑低
uint16_t Sensor_GetState(void)
{
	uint16_t State = 0X0000;
	
	sensor_val[0] = DL_GPIO_readPins(GPIO_GRAY_PORT,GPIO_GRAY_G_BIT0_PIN);//1,左边
	sensor_val[1] = DL_GPIO_readPins(GPIO_GRAY_PORT,GPIO_GRAY_G_BIT1_PIN);//2
	sensor_val[2] = DL_GPIO_readPins(GPIO_GRAY_PORT,GPIO_GRAY_G_BIT2_PIN);//4
	sensor_val[3] = DL_GPIO_readPins(GPIO_GRAY_PORT,GPIO_GRAY_G_BIT3_PIN);//5
	sensor_val[4] = DL_GPIO_readPins(GPIO_GRAY_PORT,GPIO_GRAY_G_BIT4_PIN);//7
	sensor_val[5] = DL_GPIO_readPins(GPIO_GRAY_PORT,GPIO_GRAY_G_BIT5_PIN);//8， 右边
	
	for(int i = 0 ;i<6;i++)
	{
		if(sensor_val[i] > 0)
		{
			sensor_val[i] = 1;
		}
	}
	State |= (sensor_val[5] << 5);
	State |= (sensor_val[4] << 4);
	State |= (sensor_val[3] << 3);
	State |= (sensor_val[2] << 2);
	State |= (sensor_val[1] << 1);
	State |= (sensor_val[0] << 0);
	
	
	return State;
}
 
void gray_check(void)
{
	gray_state = Sensor_GetState();
	
	//记录上一次传感器量
	for(uint16_t i=19;i>0;i--)
	{
	    gray_status_backup[0][i]=gray_status_backup[0][i-1];
	}
	
	gray_status_backup[0][0]=gray_status[0];
	
	
	//灰度检测
	switch(gray_state)
	{
		
		case 0x33:gray_status[0] = 0;	Mode_s.stop_flag++;break;  //110011
		case 0x37:gray_status[0] = 1;Mode_s.stop_flag++;	break;  //110111
	    case 0x3B:gray_status[0] = -1;Mode_s.stop_flag++;	break;   //111011
		case 0x27:gray_status[0] = 2;Mode_s.stop_flag++;break;	  //100111
		case 0x39:gray_status[0] = -2;Mode_s.stop_flag++;	break;   //111001
		case 0x2F:gray_status[0] = 3;Mode_s.stop_flag++;break;		//101111
		case 0x3D:gray_status[0] = -3;Mode_s.stop_flag++;break;		//111101
		case 0x0F:gray_status[0] = 4;Mode_s.stop_flag++;break;      //001111
		case 0x38:gray_status[0] = -4;Mode_s.stop_flag++;break;	//111100
		case 0x1F:gray_status[0] = 5;Mode_s.stop_flag++;break;	//011111
		case 0x3E:gray_status[0] = -5;Mode_s.stop_flag++;break;	//111110
		
		case 0xff:gray_status[0] = gray_status_backup[0][0];gray_status_worse++;break; //111111
			
		default://其它特殊情况单独判断
		{
			gray_status[0]=gray_status_backup[0][0];
			gray_status_worse++;
		}
	}	
	if(Mode_s.mode == IMU_M)
	{
		if(gray_state != 0x3f)
			{
				Mode_s.gray_flag = 1;
				
			}
			
		
	}
	if(Mode_s.mode == GRAY_M)
	{
		switch(gray_state)//停止线检测
		{
			
			case 0x3f:
			{
				Mode_s.imu_flag  ++ ;
			}
			break;
		}	
	}
	
	if(Mode_s.stop_flag > 1000)
		Mode_s.stop_flag =0 ;
}
