#include "key.h"
Key_t Button = {0, 0, 0,0};

void Key_scan(void)
{

		Button.K1  = click_1() ;
		Button.K2  = click_2();
		Button.K3  = click_3();
}

uint8_t click_1(void)
{
	uint8_t key_num=0;
	if(DL_GPIO_readPins(KEY_PORT,KEY_K1_PIN)==0)
	{
		delay_ms(50);
		while(DL_GPIO_readPins(KEY_PORT,KEY_K1_PIN)==0);
		delay_ms(50);
		key_num=1;
	}
	return key_num;
}
uint8_t click_2(void)
{
	uint8_t key_num=0;
	if(DL_GPIO_readPins(KEY_PORT,KEY_K2_PIN)==0)
	{
		delay_ms(50);
		while(DL_GPIO_readPins(KEY_PORT,KEY_K2_PIN)==0);
		delay_ms(50);
		key_num=1;
	}
	return key_num;
}
uint8_t click_3(void)
{
	uint8_t key_num=0;
	if(DL_GPIO_readPins(KEY_PORT,KEY_K3_PIN)==0)
	{
		delay_ms(50);
		while(DL_GPIO_readPins(KEY_PORT,KEY_K3_PIN)==0);
		delay_ms(50);
		key_num=1;
	}
	return key_num;
}


