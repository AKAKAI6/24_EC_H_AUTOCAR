#include "stdio.h"
#include "bsp_mpu6050.h"
#include "inv_mpu.h"
#include "mpu6050.h"
#include "task.h"

volatile uint32_t task_10ms_count = 0;


void TIMER_GYRO_INST_IRQHandler(void)
{
    switch (DL_TimerA_getPendingInterrupt(TIMER_GYRO_INST))
    {
    case DL_TIMER_IIDX_ZERO:
        task_10ms_count++;
        
        // 20ms 读取一次陀螺仪数据 50hz
        if (task_10ms_count % 2 == 0)
        {
            gyro.status = get_gyro_data(&gyro);
			
        }
		if( task_10ms_count > 1000)
			task_10ms_count  = 0 ;
        break;
    default:
        break;
    }
}
