#include "board.h"
#include "stdio.h"

#define RE_0_BUFF_LEN_MAX	128
volatile int32_t Get_Encoder_countA,encoderA_cnt,PWMA,Get_Encoder_countB,encoderB_cnt,PWMB;
volatile uint8_t  recv0_buff[RE_0_BUFF_LEN_MAX] = {0};
volatile uint16_t recv0_length = 0;
volatile uint8_t  recv0_flag = 0;

void delay_us(unsigned long us)
{
	while (us--)
		delay_cycles(CPUCLK_FREQ / 1000000);
}

void delay_ms(unsigned long ms)
{
	while (ms--)
		delay_cycles(CPUCLK_FREQ / 1000);
}

void delay_1us(unsigned long __us)
{
	delay_us(__us);
}

void delay_1ms(unsigned long ms)
{
	delay_ms(ms);
}

//���ڷ��͵����ַ�
void uart0_send_char(char ch)
{
	//������0æ��ʱ��ȴ�����æ��ʱ���ٷ��ʹ��������ַ�
	while( DL_UART_isBusy(UART_0_INST) == true );
	//���͵����ַ�
	DL_UART_Main_transmitData(UART_0_INST, ch);

}
//���ڷ����ַ���
void uart0_send_string(char* str)
{
	//��ǰ�ַ�����ַ���ڽ�β ���� �ַ����׵�ַ��Ϊ��
	while(*str!=0&&str!=0)
	{
		//�����ַ����׵�ַ�е��ַ��������ڷ������֮���׵�ַ����
		uart0_send_char(*str++);
	}
}


#if !defined(__MICROLIB)
//��ʹ��΢��Ļ�����Ҫ�������ĺ���
#if (__ARMCLIB_VERSION <= 6000000)
//�����������AC5  �Ͷ�����������ṹ��
struct __FILE
{
	int handle;
};
#endif

FILE __stdout;

//����_sys_exit()�Ա���ʹ�ð�����ģʽ
void _sys_exit(int x)
{
	x = x;
}
#endif


//printf�����ض���
int fputc(int ch, FILE *stream)
{
	//������0æ��ʱ��ȴ�����æ��ʱ���ٷ��ʹ��������ַ�
	while( DL_UART_isBusy(UART_0_INST) == true );
	
	DL_UART_Main_transmitData(UART_0_INST, ch);
	
	return ch;
}

//���ڵ��жϷ�����
void UART_0_INST_IRQHandler(void)
{
	uint8_t receivedData = 0;
	
	//��������˴����ж�
	switch( DL_UART_getPendingInterrupt(UART_0_INST) )
	{
		case DL_UART_IIDX_RX://����ǽ����ж�
			
			// ���շ��͹��������ݱ���
			receivedData = DL_UART_Main_receiveData(UART_0_INST);

			// ��黺�����Ƿ�����
			if (recv0_length < RE_0_BUFF_LEN_MAX - 1)
			{
				recv0_buff[recv0_length++] = receivedData;

				// ������������ٷ��ͳ�ȥ������ش�����ע�͵�
				uart0_send_char(receivedData);
			}
			else
			{
				recv0_length = 0;
			}

			// ��ǽ��ձ�־
			recv0_flag = 1;
		
			break;
		
		default://�����Ĵ����ж�
			break;
	}
}
