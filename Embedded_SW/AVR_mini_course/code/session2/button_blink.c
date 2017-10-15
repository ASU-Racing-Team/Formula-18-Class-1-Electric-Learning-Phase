#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#define sbi(x,y) x |= _BV(y) //set bit
#define cbi(x,y) x &= ~(_BV(y)) //clear bit
#define tbi(x,y) x ^= _BV(y) //toggle bit
#define is_high(x,y) ((x & _BV(y)) == _BV(y)) //check if the input pin is high
#define is_low(x,y) ((x & _BV(y)) == 0) //check if the input pin is low
// Macro 
int main(void) {
    sbi(DDRD, PD5); // PB0 as Input
    cbi(PORTD, PD5);
    cbi(DDRD, PD3); //PB1 as INPUT
    while(1) { //Infinite loop
        _delay_ms(100);
        if(is_high(PIND,PD3)){
            tbi(PORTD, PD5);
        }
    }

    return 0;
}

