#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

#define sbi(x,y) x |= _BV(y)
#define cbi(x,y) x &= ~(_BV(y))
#define tbi(x,y) x ^= _BV(y)
#define is_high(x,y) (x & _BV(y) == _BV(y))

uint8_t counter = 0;
int main()
 { 
   // Timer 0 Initialization
    sbi(TCCR0B, CS00);
    sbi(TCCR0B, CS02);
    cbi(TCCR0B, CS01);
    sbi(TIMSK0, TOIE0);
   // Gpio pin PD5 initilization
    sbi(DDRD, PD5);
    cbi(PORTD, PD5);
    sei();
   while (1);
   return 0;
 }
// 11100011 & 00010000 = 00000000
// 11110011 & 00010000 = 00010000
// blink led every 100ms
// this fn happens every 25ms
ISR(TIMER0_OVF_vect){
   counter++;
   if(counter == 3){
      tbi(PORTD, PD5);
      counter = 0;
    }
 }