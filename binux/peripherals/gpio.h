#ifndef GPIO_H_
#define GPIO_H_

#include "libopencm3/stm32/gpio.h"
#include "libopencm3/stm32/rcc.h"

#define HIGH 1
#define LOW 0



void    GPIO_setMode(int pins, int port, int mode, int pupd); 
//Sets a pin as an output
void    GPIO_setOut(int pins, int port);
//Sets a pin as an input with a pull down resistor
void    GPIO_setIN_pd(int pins, int port);
//Sets a pin as an input with a pull up resistor
void    GPIO_setIN_pu(int pins, int port);
//Sets an output pin to HIGH or LOW state
void    GPIO_setState(int pins, int port, int state);
//Toggles the state of an output pin, if it was HIGH after the function it's going to be low
void    GPIO_toggleState(int pins, int port);
//Returns value of input pin
int     GPIO_getState(int pins, int port);

#endif //GPIO_H_