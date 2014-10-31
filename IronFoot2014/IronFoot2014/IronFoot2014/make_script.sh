avr-gcc -mmcu=atmega640 -c IronFoot2014.c
avr-gcc -mmcu=atmega640 -o IronFoot2014.elf IronFoot2014.o helper.c adc_helper.c
avr-objcopy -j .text -j .data -O ihex IronFoot2014.elf IronFoot2014.hex


