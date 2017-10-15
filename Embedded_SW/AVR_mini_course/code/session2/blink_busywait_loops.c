#include <avr/io.h>

void main(void)
{
    DDRD |= (1<<5); //PD5 as OUTPUT
    PORTD &= ~(1<<5); //PD5 LOW

    uint16_t i;
    while(1){ //Infinite loop
        for(i=0;i<65535;i++); //delay
        for(i=0;i<65535;i++); //delay
        PORTD ^= (1<<5);   //here the toggling takes place
    }
}