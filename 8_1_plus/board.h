#ifndef	__BOARD_H__
#define __BOARD_H__

#include "ti_msp_dl_config.h"
#define ABS(a)      (a>0 ? a:(-a))

#define left_motor_encoder_dir_default 0
#define right_motor_encoder_dir_default 0
#define left_motion_dir_default 0
#define right_motion_dir_default 0
#define tire_radius_cm_default 2.40f      // 轮胎半径，单位为cm
#define pulse_cnt_per_circle_default 728 // 实际轮子转动一周的脉冲数量 530 1080 40750
#define servo_median_value1_default 1500  // 舵机机械中值
#define servo_median_value2_default 1500  // 舵机机械中值
#define rangefinder_type_default 0

extern volatile int32_t Get_Encoder_countA,encoderA_cnt,PWMA,Get_Encoder_countB,encoderB_cnt,PWMB;


void delay_us(unsigned long __us);
void delay_ms(unsigned long ms);
void delay_1us(unsigned long __us);
void delay_1ms(unsigned long ms);

void uart0_send_char(char ch);
void uart0_send_string(char* str);



#endif
