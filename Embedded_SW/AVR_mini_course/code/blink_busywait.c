#include <avr/io.h>
#define sbi(x,y) x |= _BV(y)
#define cbi(x,y) x &= ~(_BV(y))
#define tbi(x,y) x ^= _BV(y)
#define is_high(x,y) (x & _BV(y) == _BV(y))

/* _BV(a) is a macro which returns the value corresponding to 2 to the power 'a'. Thus _BV(PX3) would be 0x08 or 0b00001000 */

void main(void)
{
    sbi(DDRD, PD5); //PD5 as OUTPUT
    cbi(PORTD, PD5); //PD5 LOW

    uint16_t i;
    while(1){ //Infinite loop
        for(i=0;i<65535;i++); //delay
        for(i=0;i<65535;i++); //delay
        tbi(PORTD,PD5);   //here the toggling takes place
    }
}