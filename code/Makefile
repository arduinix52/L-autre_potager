# "AVRNano" (aka arduino nano) makefile
# !! DOESN'T USE THE WIRING LIB !!

# Configuration
# Name defaults to current dir name
NAME = $(subst -,_,$(notdir $(CURDIR)))
MCU   = atmega328p
F_CPU = 16000000UL
BAUD  = 115200UL
PORT = /dev/ttyS9

# Programmer // NEED TO DEFINE UDEV
PTYPE = arduino
PFLAGS = -P $(PORT) -b 115200

CC = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
AVRSIZE = avr-size
AVRDUDE = avrdude

# Source files, object files...
SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)

# Compilation options
CPPFLAGS = -DF_CPU=$(F_CPU) -DBAUD=$(BAUD)
CFLAGS = -Os -g -std=gnu99 -Wall

all:			$(NAME).hex

%.elf:			$(OBJ)
				$(CC) $(LDFLAGS) -mmcu=$(MCU) $^ $(LDLIBS) -o $@

%.o:			%.c
				$(CC) $(CFLAGS) $(CPPFLAGS) -mmcu=$(MCU) -c -o $@ $<;

%.hex:			%.elf
				$(OBJCOPY) -j .text -j .data -O ihex $< $@

disassemble:	$(NAME).elf
				$(OBJDUMP) -S $(NAME).elf > $(NAME).lst

size:			$(NAME).elf
				$(AVRSIZE) -C --mcu=$(MCU) $(MAME).elf

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME).*

flash:			$(NAME).hex
				$(AVRDUDE) -c $(PTYPE) -p $(MCU) $(PFLAGS) -U flash:w:$<

flash_eeprom:	$(NAME).elf
				$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $(NAME).elf $(NAME).eeprom
				$(AVRDUDE) -c $(PTYPE) -p $(MCU) $(PFLAGS) -U eeprom:w:$<


.PHONY: all disassemble eeprom size clean fclean flash flash_eeprom
