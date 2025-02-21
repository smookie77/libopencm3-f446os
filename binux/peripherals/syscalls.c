#include "serial.h"
int _write(int file, char *ptr, int len) {
        serial_print(DEFAULT_SERIAL, ptr, len);
        return len;
}

// #pragma weak _write

// int _read(int file, char *ptr, int len) {

//         return 0;
// }

