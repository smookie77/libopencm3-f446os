#include "main.h"

#define LED_PORT        (GPIOB)
#define LED_PIN         (GPIO2)


int main(void){
    sys_Init();
    GPIO_setOut(LED_PIN, LED_PORT);
    serial_init(DEFAULT_SERIAL);
    
    

    uint64_t start_time = sys_getTicks();
    while(1){
            GPIO_toggleState(LED_PIN, LED_PORT);
            printf("Hello World\n\0");
            serial_print(DEFAULT_SERIAL, "Hello World\n");
            delay_ms(500);
    }
    
}