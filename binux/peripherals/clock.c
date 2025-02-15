#include "clock.h"

int CPUFrequency = DEFAULT_FREQUENCY;

 void sys_Init(void){
        rcc_clock_setup_pll(&rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_180MHZ]);
        CPUFrequency = 180000000;
        sys_systickInit();
}

void sys_systickInit(void){
        systick_set_frequency(SYSTICK_FREQ, CPUFrequency);
        systick_counter_enable();
        systick_interrupt_enable();
}

volatile uint64_t sys_ticks = 0; 
void systick_handler(void){
        sys_ticks++;
}

 uint64_t sys_getTicks(void){
        return sys_ticks;
}