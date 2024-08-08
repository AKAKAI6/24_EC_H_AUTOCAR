#ifndef _FSM_H
#define _FSM_H

#include "stdint.h"
#include "Key.h"
#define STATUS_MAX (10)
typedef enum
{
	ISSUE_1 = 1,
	ISSUE_2 = 2,
	ISSUE_3 = 3,
	ISSUE_4 = 4,
	ISSUE_5 = 5,
}Issue_Enum;

typedef enum
{
	IMU_M = 1,
	GRAY_M = 0,
	STOP = 2,
	STOP_ISSUE1 = 3,
}Mode_Enum;

typedef struct
{
	uint8_t confirm;
	uint8_t stop_flag;
	uint8_t imu_flag;
	uint8_t gray_flag;
	Mode_Enum mode;
	Mode_Enum last_mode;
}Mode_T;

extern Issue_Enum Issue_s;
extern Mode_T Mode_s;

void Issue_Select(Key_t key_1);

void Mode_Process(Mode_T mode);
void Issue_process(Issue_Enum issue);
void RGB_BEEP(uint8_t ena);


#endif
