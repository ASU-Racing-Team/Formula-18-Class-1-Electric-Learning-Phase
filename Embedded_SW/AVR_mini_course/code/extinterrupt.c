#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#define sbi(x,y) x |= _BV(y)
#define cbi(x,y) x &= ~(_BV(y))
#define tbi(x,y) x ^= _BV(y)

ISR(INT0_vect){
   tbi(PORTD, PD0);
}
int main()
 { 
   sbi(EICRA, ISC00);
   sbi(EICRA, ISC01);
   
   sbi(EIMSK, INT0);
   sbi(DDRD, PD0);
    sei();
   while (1);
   return 0;
 }