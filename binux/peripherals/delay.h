#ifndef DELAY_H_
#define DELAY_H_

#include "libopencm3/cm3/systick.h"
#include "clock.h"

// extern int CPUFrequency;
void delay_cc(int clockCycles);
void delay_ms(int ms);
void delay_s(int s);

#endif //DELAY_H_