#ifndef __GRAY_DETECT_H
#define __GRAY_DETECT_H
#include "stdint.h"
extern volatile int gray_status[2],gray_status_backup[2][20] ;//�Ҷȴ�����״̬����ʷֵ
uint16_t Sensor_GetState(void);
void gray_check(void);

#endif
