PROJECT = binux
BUILD_DIR = bin

SHARED_DIR = peripherals
CFILES =main.c
CFILES +=peripherals/gpio.c
CFILES +=peripherals/delay.c
CFILES +=peripherals/clock.c
CFILES +=peripherals/serial.c
CFILES +=peripherals/syscalls.c


# TODO - you will need to edit these two lines!
DEVICE=stm32f446ret6
OOCD_FILE = board/stm32f4discovery.cfg

# You shouldn't have to edit anything below here.
VPATH += $(SHARED_DIR)
INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR))
OPENCM3_DIR=../libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ../rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
