
#include "main.h"

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