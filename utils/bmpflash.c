#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1

int main (int argc, char *argv[]) {
    #ifdef DEBUG
    printf("argc = %d\n", argc);
    char *path = *(argv+1);
    printf("argv = %s\n", path);
    #endif

    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    // Allocate enough space for the command and the argument
    char command[512];
    snprintf(command, sizeof(command), 
             "arm-none-eabi-gdb -ex \"target extended-remote /dev/ttyACM0\" -ex \"monitor swd_scan\" -ex \"attach 1\" -ex \"load\" -ex \"monitor reset\" -ex \"quit\" %s", 
             path);

    system(command);
    return 0;
}
