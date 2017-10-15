
#include <avr/interrupt.h>
#include <stdint.h>
#include "timer.h"
#include "gpio.h"
#define sbi(x,y) x |= _BV(y)
#define cbi(x,y) x &= ~(_BV(y))
#define tbi(x,y) x ^= _BV(y)
#define is_high(x,y) (x & _BV(y) == _BV(y))

void init_gpio(){
   sbi(DDRD, PD0);
    cbi(PORTD, PD0);
    sbi(DDRD, PD1);
    cbi(PORTD, PD1);
    sbi(DDRD, PD2);
    cbi(PORTD, PD2);
   }

void init_timer0(){
    sbi(TCCR0B, CS00);
    sbi(TCCR0B, CS02);
    cbi(TCCR0B, CS01);
    OCR0A = 50;
    OCR0B = 120;
    //sbi(TIFR0, TOV0);
    sbi(TIMSK0, TOIE0);
    sbi(TIMSK0, OCIE0A);
    sbi(TIMSK0, OCIE0B);
}

uint8_t counter0 = 0;
uint8_t counter1 = 0;
uint8_t counter2 = 0;


int main()
 { 
   // Timer 0 Initialization
    sei();
    init_timer0();
   // Gpio pin PD5 initilization
    init_gpio();
   while (1);
   return 0;
 }
 ISR(TIMER0_OVF_vect){
   counter0++;
   if(counter0 == 6){
      tbi(PORTD, PD0);
      counter0 = 0;
    }
 }
 ISR(TIMER0_COMPA_vect){
    counter1++;
   if(counter1 == 6){
      tbi(PORTD, PD1);
      counter1 = 0;
    }
 }
 ISR(TIMER0_COMPB_vect){
    counter2++;
   if(counter2 == 6){
      tbi(PORTD, PD2);
      counter2 = 0;
    }
 } 