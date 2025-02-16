#include "serial.h"


// If you want more serial ports just copy and paste this one and change its .usart_handle
Serial_t serial1 = {
    .usart_handle = USART1, 
    .baudrate = DEFAULT_BAUDRATE,
    .databits = DEFAULT_DATABITS,
    .flowcontrol = DEFAULT_FLOW_CTRL,
    .mode = DEFAULT_MODE,
    .parity = DEFAULT_PARITY,
    .stopbits = DEFAULT_STOPBITS
};

/**
 * @brief enables the rcc clock of the specific serial port
 * @param serial_addr the usart/uart base address, e.g. USART1, UART4...
 */
void serial_enableClock(uint32_t serial_addr){
        switch(serial_addr){
                case USART1: rcc_periph_clock_enable(RCC_USART1); break;
                case USART2: rcc_periph_clock_enable(RCC_USART2); break;
                case USART3: rcc_periph_clock_enable(RCC_USART3); break;
                case UART4:  rcc_periph_clock_enable(RCC_UART4);  break;
                case UART5:  rcc_periph_clock_enable(RCC_UART5);  break;
                case USART6: rcc_periph_clock_enable(RCC_USART6); break;
        }
}


/**
 * @brief sets up the serial peripheral and its settings
 * @param serial pointer for the Serial_t struct, see peripherals/serial.c
 */
void serial_init(Serial_t *serial){
        serial_enableClock(serial->usart_handle);
        usart_disable(serial->usart_handle);
        
        usart_set_baudrate(serial->usart_handle, serial->baudrate);
        usart_set_databits(serial->usart_handle, serial->databits);
        usart_set_flow_control(serial->usart_handle, serial->flowcontrol);
        usart_set_mode(serial->usart_handle, serial->mode);
        usart_set_parity(serial->usart_handle, serial->parity);
        usart_set_stopbits(serial->usart_handle, serial->stopbits);

        GPIO_setMode(GPIO9 | GPIO10, GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE);
        gpio_set_af(GPIOA, GPIO_AF7, GPIO9 | GPIO10);

        usart_enable(serial->usart_handle);
}

void serial_print(Serial_t *serial, char *msg){
        for(int i = 0; *(msg+i) != '\0'; i++){
                usart_send_blocking(serial->usart_handle, *(msg+i));
        }

}

int _write(int file, char *ptr, int len) {
        serial_print(DEFAULT_SERIAL, ptr);
        return len;
}