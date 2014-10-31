avr-gcc -mmcu=atmega328 -c Microsumo2014.c
avr-gcc -mmcu=atmega328 -o Microsumo2014.elf Microsumo2014.o helper.c
avr-objcopy -j .text -j .data -O ihex Microsumo2014.elf Microsumo2014.hex


