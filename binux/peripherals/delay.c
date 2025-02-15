#include "delay.h"

void delay_cc(int clockCycles){
        for(int i = 0; i < clockCycles/4; i++){
                __asm__("nop");
        }
}
void delay_ms(int ms){
        delay_cc(CPUFrequency/1000*ms);
}
void delay_s(int s){
        delay_cc(CPUFrequency*s);
}