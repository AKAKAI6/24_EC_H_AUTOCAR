#ifndef _KEY_H
#define _KEY_H
#include "ti_msp_dl_config.h"
#include "board.h"

#define KEY_ON 0
#define KEY_OFF 1
typedef struct
{
	uint8_t K1;
	
	uint8_t K2;
	
	uint8_t K3;
	
}Key_t;

uint8_t click_1(void);
uint8_t click_2(void);
uint8_t click_3(void);

extern Key_t Button;
void Key_scan(void);

#endif
