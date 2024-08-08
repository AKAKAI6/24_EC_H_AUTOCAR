#include "ultrasonic.h"

volatile uint8_t overflowFlag;

uint32_t getUltrasonicDist(void)
{
    uint32_t cnt, dist;
    DL_GPIO_setPins(GPIO_Ultrasonic_PIN_Trig_PORT, GPIO_Ultrasonic_PIN_Trig_PIN);
    delay_cycles(CPUCLK_FREQ / 50000); // 80000000/50000=1600Hz
    DL_GPIO_clearPins(GPIO_Ultrasonic_PIN_Trig_PORT, GPIO_Ultrasonic_PIN_Trig_PIN);

    while (!DL_GPIO_readPins(GPIO_Ultrasonic_PIN_Echo_PORT, GPIO_Ultrasonic_PIN_Echo_PIN))
        ;

    overflowFlag = 0;
    DL_TimerA_setTimerCount(TIMER_Ultrasonic_INST, 0);
    DL_TimerA_startCounter(TIMER_Ultrasonic_INST);

    while (DL_GPIO_readPins(GPIO_Ultrasonic_PIN_Echo_PORT, GPIO_Ultrasonic_PIN_Echo_PIN) && !overflowFlag)
        ;

    DL_TimerA_stopCounter(TIMER_Ultrasonic_INST);

    if (overflowFlag)
    {
        dist = 0;
    }
    else
    {
        cnt = DL_TimerA_getTimerCount(TIMER_Ultrasonic_INST);
        dist = cnt * 0.017f;
    }
    return dist;
}

void TIMER_Ultrasonic_INST_IRQHandler(void) // one-shot mode 25ms load
{
    switch (DL_TimerA_getPendingInterrupt(TIMER_Ultrasonic_INST))
    {
    case DL_TIMER_IIDX_LOAD:
        overflowFlag = 1;
        break;
    default:
        break;
    }
}