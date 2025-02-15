#include "gpio.h"

/**
 * @brief Sets wether pins are an Output or an input with an option for pull up and pull down resistors 
 * @param pins The number of a pin or multiple pins, e.g. GPIO4, GPIO4|GPIO5
 * @param port The id of the port, e.g GPIOA, GPIOB...
 * @param mode Sets if the pin/pins are output(GPIO_MODE_OUTPUT), input(GPIO_MODE_INPUT), analog(GPIO_MODE_ANALOG) or alternate function(GPIO_MODE_AF) 
 */
void GPIO_setMode(int pins, int port, int mode, int pupd){

        switch(port){
                case GPIOA: rcc_periph_clock_enable(RCC_GPIOA); break;
                case GPIOB: rcc_periph_clock_enable(RCC_GPIOB); break;
                case GPIOC: rcc_periph_clock_enable(RCC_GPIOC); break;
                case GPIOD: rcc_periph_clock_enable(RCC_GPIOD); break;
                case GPIOE: rcc_periph_clock_enable(RCC_GPIOE); break;
                case GPIOF: rcc_periph_clock_enable(RCC_GPIOF); break;
                case GPIOG: rcc_periph_clock_enable(RCC_GPIOG); break;
                case GPIOH: rcc_periph_clock_enable(RCC_GPIOH); break;
                case GPIOI: rcc_periph_clock_enable(RCC_GPIOI); break;
                case GPIOJ: rcc_periph_clock_enable(RCC_GPIOJ); break;
                case GPIOK: rcc_periph_clock_enable(RCC_GPIOK); break;
        }

        gpio_mode_setup(port, mode, pupd, pins);
}


void GPIO_setOut(int pins, int port){
        GPIO_setMode(pins, port, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE);
}


void GPIO_setIN_pd(int pins, int port){
        GPIO_setMode(pins, port, GPIO_MODE_INPUT, GPIO_PUPD_PULLDOWN);
}


void GPIO_setIN_pu(int pins, int port){
        GPIO_setMode(pins, port, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP);
}


void GPIO_setState(int pins, int port, int state){
        if(state == 0){
                gpio_clear(port, pins);
        }
        else{
                gpio_set(port, pins);
        }
}


void GPIO_toggleState(int pins, int port){
        gpio_toggle(port, pins);
}


int GPIO_getState(int pins, int port){
        return gpio_get(port, pins);
}

