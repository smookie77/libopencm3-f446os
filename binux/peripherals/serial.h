#ifndef SERIAL_H_
#define SERIAL_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "gpio.h"

#include "libopencm3/stm32/f4/usart.h"
#include "libopencm3/stm32/f4/rcc.h"

typedef struct{
        uint32_t usart_handle;
        uint32_t baudrate;
        uint8_t databits;
        uint8_t flowcontrol;
        uint8_t mode;
        uint8_t parity;
        uint8_t stopbits;
} Serial_t;

extern Serial_t serial1;

#define DEFAULT_SERIAL (&serial1)

#define DEFAULT_BAUDRATE        115200
#define DEFAULT_DATABITS        8
#define DEFAULT_FLOW_CTRL       USART_FLOWCONTROL_NONE
#define DEFAULT_MODE            USART_MODE_TX_RX
#define DEFAULT_PARITY          USART_PARITY_NONE
#define DEFAULT_STOPBITS        1

void serial_enableClock(uint32_t serial_addr);
void serial_init(Serial_t *serial);
void serial_print(Serial_t *serial, char *msg, int len);
// void serial_println(Serial_t serial_handle);
// char* serial_scan(Serial_t serial_handle);

#endif //SERIAL_H_