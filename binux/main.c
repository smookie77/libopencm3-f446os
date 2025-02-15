#include "main.h"

#define LED_PORT        (GPIOB)
#define LED_PIN         (GPIO2)


int main(void){
    sys_Init();
    GPIO_setOut(LED_PIN, LED_PORT);
    
    uint64_t start_time = sys_getTicks();
    while(1){
        if(sys_getTicks() - start_time >= 1000){
            GPIO_toggleState(LED_PIN, LED_PORT);
            start_time = sys_getTicks();
        }

    }
    
}