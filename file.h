/*
 * file.h
 *
 *  Created on: Jan 10, 2026
 *      Author: Zeshahan
 */

#ifndef FILE_H_
#define FILE_H_

#include "stm32f030x6.h"
#include <stdint.h>
#include <stdbool.h>

/* PINS */
#define LED1        (1U << 1)  //PA1
#define LED2        (1U << 2)  //PA2
#define RELAY_LOAD  (1U << 3)  //PA3
#define RELAY_STAT  (1U << 4)  //PA4
#define PIR_PWR     (1U << 5)  //PA5
#define PIR_PIN     (1U << 10) //PA10
#define PIR_ADC     (1U << 1)  //PB1_____ADC_READ

/* GPIO control (STM32F0) */
#define PIN_SET(p)    (GPIOA->ODR |=  (p))
#define PIN_CLR(p)    (GPIOA->BRR  =  (p))

#define RELAY_ON(p)   PIN_SET(p)
#define RELAY_OFF(p)  PIN_CLR(p)

/* Timing */
#define PIR_WARMUP_MS      2000
#define MOTION_HOLD_MS     5000
#define FAULT_BLINK_MS     500
#define PIR_NO_LOW_TIMEOUT 20000

/* ADC thresholds */
#define OPEN_TH      100
#define SHORT_TH     3800

typedef enum {
    NO_FAULT          =0,
    OPEN_FAULT        =1,
    SHORT_FAULT       =2,
	HIGH_STUCK_FAULT  =3
} FaultType;

/* Globals */
extern volatile uint32_t msTicks;
extern FaultType faultType;
extern uint8_t pir_ready ;   // startup PIR filter


/* function Prototypes */
void GPIO_Init(void);
void TIM3_Init(void);
void ADC_Init(void);

uint32_t millis(void);
uint16_t ADC_Read(void);

#endif
