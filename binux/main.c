#include "main.h"
#define REINTERPRET_32(x) ((uint32_t)((x) & 0xFFFFFFFF))

#define LED_PORT        (GPIOB)
#define LED_PIN         (GPIO2)


int main(void){
    sys_Init();
    GPIO_setOut(LED_PIN, LED_PORT);
    serial_init(DEFAULT_SERIAL);

    uint64_t start_time = sys_getTicks();
    uint64_t blink_time = sys_getTicks();

    while(1){
        if(sys_getTicks() - blink_time >= 1000){    
            GPIO_toggleState(LED_PIN, LED_PORT);
            printf("Hello World! TICKS = %ld \n", REINTERPRET_32(sys_getTicks())); // This code will work only for ~50 days
            printf("This program has been runing for %ld seconds\n", REINTERPRET_32(sys_getTicks() - start_time)/SYSTICK_FREQ);
            printf("This program has been runing for %ld minutes\n", REINTERPRET_32((sys_getTicks() - start_time)/SYSTICK_FREQ / 60));
            printf("This program has been runing for %ld days\n", REINTERPRET_32((sys_getTicks() - start_time)/SYSTICK_FREQ / 86400));
            blink_time = sys_getTicks();
        }
        
    }
    
}