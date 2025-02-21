#ifndef CLOCK_H_
#define CLOCK_H_

#include "libopencm3/stm32/rcc.h"
#include "libopencm3/cm3/systick.h"
#include "libopencm3/cm3/vector.h"
#include "libopencm3/cm3/nvic.h"

#define SYSTICK_FREQ 1000
#define DEFAULT_FREQUENCY 8000000
extern int CPUFrequency;
void sys_Init(void); //Initializes the clock plls so the system runs at full speed
void sys_systickInit(void);
void systick_handler(void);
uint64_t sys_getTicks(void);

#endif //CLOCK_H_