#include <avr/io.h>
#include <avr/interrupt.h>

#define sbi(x,y) x |= _BV(y)
#define cbi(x,y) x &= ~(_BV(y))
#define tbi(x,y) x ^= _BV(y)

ISR(INT0_vect){
    tbi(PORTD, PD0);
}

int main(void){
    // init INT0
    sbi(EICRA, ISC00);
    sbi(EICRA, ISC01);
    sbi(EIMSK, INT0);
    // init LED
    sbi(DDRD, PD0);
    cbi(PORTD, PD0);
    while(1);
    return 0;
}