/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     80000000



/* Defines for PWM_0 */
#define PWM_0_INST                                                         TIMA0
#define PWM_0_INST_IRQHandler                                   TIMA0_IRQHandler
#define PWM_0_INST_INT_IRQN                                     (TIMA0_INT_IRQn)
#define PWM_0_INST_CLK_FREQ                                   26666666.666666668
/* GPIO defines for channel 0 */
#define GPIO_PWM_0_C0_PORT                                                 GPIOB
#define GPIO_PWM_0_C0_PIN                                         DL_GPIO_PIN_14
#define GPIO_PWM_0_C0_IOMUX                                      (IOMUX_PINCM31)
#define GPIO_PWM_0_C0_IOMUX_FUNC                     IOMUX_PINCM31_PF_TIMA0_CCP0
#define GPIO_PWM_0_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_0_C1_PORT                                                 GPIOA
#define GPIO_PWM_0_C1_PIN                                          DL_GPIO_PIN_3
#define GPIO_PWM_0_C1_IOMUX                                       (IOMUX_PINCM8)
#define GPIO_PWM_0_C1_IOMUX_FUNC                      IOMUX_PINCM8_PF_TIMA0_CCP1
#define GPIO_PWM_0_C1_IDX                                    DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG0)
#define TIMER_0_INST_IRQHandler                                 TIMG0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                           (124U)
/* Defines for TIMER_GYRO */
#define TIMER_GYRO_INST                                                  (TIMA1)
#define TIMER_GYRO_INST_IRQHandler                              TIMA1_IRQHandler
#define TIMER_GYRO_INST_INT_IRQN                                (TIMA1_INT_IRQn)
#define TIMER_GYRO_INST_LOAD_VALUE                                      (19999U)




/* Defines for I2C_MPU6050 */
#define I2C_MPU6050_INST                                                    I2C1
#define I2C_MPU6050_INST_IRQHandler                              I2C1_IRQHandler
#define I2C_MPU6050_INST_INT_IRQN                                  I2C1_INT_IRQn
#define I2C_MPU6050_BUS_SPEED_HZ                                          100000
#define GPIO_I2C_MPU6050_SDA_PORT                                          GPIOA
#define GPIO_I2C_MPU6050_SDA_PIN                                  DL_GPIO_PIN_30
#define GPIO_I2C_MPU6050_IOMUX_SDA                                (IOMUX_PINCM5)
#define GPIO_I2C_MPU6050_IOMUX_SDA_FUNC                 IOMUX_PINCM5_PF_I2C1_SDA
#define GPIO_I2C_MPU6050_SCL_PORT                                          GPIOA
#define GPIO_I2C_MPU6050_SCL_PIN                                  DL_GPIO_PIN_29
#define GPIO_I2C_MPU6050_IOMUX_SCL                                (IOMUX_PINCM4)
#define GPIO_I2C_MPU6050_IOMUX_SCL_FUNC                 IOMUX_PINCM4_PF_I2C1_SCL


/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_11
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM22)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_0_BAUD_RATE                                                (115200)
#define UART_0_IBRD_40_MHZ_115200_BAUD                                      (21)
#define UART_0_FBRD_40_MHZ_115200_BAUD                                      (45)





/* Port definition for Pin Group RGB_Red */
#define RGB_Red_PORT                                                     (GPIOB)

/* Defines for PIN_26: GPIOB.26 with pinCMx 57 on package pin 28 */
#define RGB_Red_PIN_26_PIN                                      (DL_GPIO_PIN_26)
#define RGB_Red_PIN_26_IOMUX                                     (IOMUX_PINCM57)
/* Port definition for Pin Group AIN1 */
#define AIN1_PORT                                                        (GPIOA)

/* Defines for PIN_12: GPIOA.12 with pinCMx 34 on package pin 5 */
#define AIN1_PIN_12_PIN                                         (DL_GPIO_PIN_12)
#define AIN1_PIN_12_IOMUX                                        (IOMUX_PINCM34)
/* Port definition for Pin Group AIN2 */
#define AIN2_PORT                                                        (GPIOA)

/* Defines for PIN_13: GPIOA.13 with pinCMx 35 on package pin 6 */
#define AIN2_PIN_13_PIN                                         (DL_GPIO_PIN_13)
#define AIN2_PIN_13_IOMUX                                        (IOMUX_PINCM35)
/* Port definition for Pin Group BIN1 */
#define BIN1_PORT                                                        (GPIOB)

/* Defines for Pin_Bin1: GPIOB.16 with pinCMx 33 on package pin 4 */
#define BIN1_Pin_Bin1_PIN                                       (DL_GPIO_PIN_16)
#define BIN1_Pin_Bin1_IOMUX                                      (IOMUX_PINCM33)
/* Port definition for Pin Group BIN2 */
#define BIN2_PORT                                                        (GPIOB)

/* Defines for Pin_Bin2: GPIOB.0 with pinCMx 12 on package pin 47 */
#define BIN2_Pin_Bin2_PIN                                        (DL_GPIO_PIN_0)
#define BIN2_Pin_Bin2_IOMUX                                      (IOMUX_PINCM12)
/* Port definition for Pin Group PORTA */
#define PORTA_PORT                                                       (GPIOA)

/* Defines for beep: GPIOA.27 with pinCMx 60 on package pin 31 */
#define PORTA_beep_PIN                                          (DL_GPIO_PIN_27)
#define PORTA_beep_IOMUX                                         (IOMUX_PINCM60)
/* Port definition for Pin Group LED1 */
#define LED1_PORT                                                        (GPIOA)

/* Defines for PIN_0: GPIOA.0 with pinCMx 1 on package pin 33 */
#define LED1_PIN_0_PIN                                           (DL_GPIO_PIN_0)
#define LED1_PIN_0_IOMUX                                          (IOMUX_PINCM1)
/* Port definition for Pin Group KEY */
#define KEY_PORT                                                         (GPIOB)

/* Defines for K1: GPIOB.21 with pinCMx 49 on package pin 20 */
#define KEY_K1_PIN                                              (DL_GPIO_PIN_21)
#define KEY_K1_IOMUX                                             (IOMUX_PINCM49)
/* Defines for K2: GPIOB.23 with pinCMx 51 on package pin 22 */
#define KEY_K2_PIN                                              (DL_GPIO_PIN_23)
#define KEY_K2_IOMUX                                             (IOMUX_PINCM51)
/* Defines for K3: GPIOB.24 with pinCMx 52 on package pin 23 */
#define KEY_K3_PIN                                              (DL_GPIO_PIN_24)
#define KEY_K3_IOMUX                                             (IOMUX_PINCM52)
/* Port definition for Pin Group ENCODERA */
#define ENCODERA_PORT                                                    (GPIOA)

/* Defines for E1A: GPIOA.15 with pinCMx 37 on package pin 8 */
// groups represented: ["ENCODERB","ENCODERA"]
// pins affected: ["E2A","E2B","E1A","E1B"]
#define GPIO_MULTIPLE_GPIOA_INT_IRQN                            (GPIOA_INT_IRQn)
#define GPIO_MULTIPLE_GPIOA_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define ENCODERA_E1A_IIDX                                   (DL_GPIO_IIDX_DIO15)
#define ENCODERA_E1A_PIN                                        (DL_GPIO_PIN_15)
#define ENCODERA_E1A_IOMUX                                       (IOMUX_PINCM37)
/* Defines for E1B: GPIOA.16 with pinCMx 38 on package pin 9 */
#define ENCODERA_E1B_IIDX                                   (DL_GPIO_IIDX_DIO16)
#define ENCODERA_E1B_PIN                                        (DL_GPIO_PIN_16)
#define ENCODERA_E1B_IOMUX                                       (IOMUX_PINCM38)
/* Port definition for Pin Group ENCODERB */
#define ENCODERB_PORT                                                    (GPIOA)

/* Defines for E2A: GPIOA.17 with pinCMx 39 on package pin 10 */
#define ENCODERB_E2A_IIDX                                   (DL_GPIO_IIDX_DIO17)
#define ENCODERB_E2A_PIN                                        (DL_GPIO_PIN_17)
#define ENCODERB_E2A_IOMUX                                       (IOMUX_PINCM39)
/* Defines for E2B: GPIOA.22 with pinCMx 47 on package pin 18 */
#define ENCODERB_E2B_IIDX                                   (DL_GPIO_IIDX_DIO22)
#define ENCODERB_E2B_PIN                                        (DL_GPIO_PIN_22)
#define ENCODERB_E2B_IOMUX                                       (IOMUX_PINCM47)
/* Port definition for Pin Group GPIO_GRAY */
#define GPIO_GRAY_PORT                                                   (GPIOB)

/* Defines for G_BIT0: GPIOB.2 with pinCMx 15 on package pin 50 */
#define GPIO_GRAY_G_BIT0_PIN                                     (DL_GPIO_PIN_2)
#define GPIO_GRAY_G_BIT0_IOMUX                                   (IOMUX_PINCM15)
/* Defines for G_BIT1: GPIOB.3 with pinCMx 16 on package pin 51 */
#define GPIO_GRAY_G_BIT1_PIN                                     (DL_GPIO_PIN_3)
#define GPIO_GRAY_G_BIT1_IOMUX                                   (IOMUX_PINCM16)
/* Defines for G_BIT2: GPIOB.4 with pinCMx 17 on package pin 52 */
#define GPIO_GRAY_G_BIT2_PIN                                     (DL_GPIO_PIN_4)
#define GPIO_GRAY_G_BIT2_IOMUX                                   (IOMUX_PINCM17)
/* Defines for G_BIT3: GPIOB.5 with pinCMx 18 on package pin 53 */
#define GPIO_GRAY_G_BIT3_PIN                                     (DL_GPIO_PIN_5)
#define GPIO_GRAY_G_BIT3_IOMUX                                   (IOMUX_PINCM18)
/* Defines for G_BIT4: GPIOB.6 with pinCMx 23 on package pin 58 */
#define GPIO_GRAY_G_BIT4_PIN                                     (DL_GPIO_PIN_6)
#define GPIO_GRAY_G_BIT4_IOMUX                                   (IOMUX_PINCM23)
/* Defines for G_BIT5: GPIOB.7 with pinCMx 24 on package pin 59 */
#define GPIO_GRAY_G_BIT5_PIN                                     (DL_GPIO_PIN_7)
#define GPIO_GRAY_G_BIT5_IOMUX                                   (IOMUX_PINCM24)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_0_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_TIMER_GYRO_init(void);
void SYSCFG_DL_I2C_MPU6050_init(void);
void SYSCFG_DL_UART_0_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
