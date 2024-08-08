#ifndef __MPU6050_H
#define __MPU6050_H

#include "stdint.h"

typedef struct
{
    float pitch;
    float roll;
    float yaw;
    int8_t status;
	float init_yaw;
} struct_mpu6050_angle;
extern struct_mpu6050_angle gyro;

uint8_t get_gyro_data(struct_mpu6050_angle *gyro);
void gyro_yaw_handle(struct_mpu6050_angle *mpu6050);

#endif
