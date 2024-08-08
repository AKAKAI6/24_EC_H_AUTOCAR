#include "mpu6050.h"
#include "inv_mpu.h"
#include "ti_msp_dl_config.h"
#include "stdio.h"

struct_mpu6050_angle gyro;

uint8_t get_gyro_data(struct_mpu6050_angle *gyro)
{
    return (mpu_dmp_get_data(&gyro->pitch, &gyro->roll, &gyro->yaw));
}

void gyro_yaw_handle(struct_mpu6050_angle *mpu6050)
{
	mpu6050->yaw = mpu6050->yaw - mpu6050->init_yaw;
	if(mpu6050->yaw > 180.0f)
		mpu6050->yaw -= 360.0f; 
	else if(mpu6050->yaw < -180.0f)
		mpu6050->yaw +=  360.0f;
}
