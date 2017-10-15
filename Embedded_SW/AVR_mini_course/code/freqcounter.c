#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define sbi(x,y) x |= _BV(y)
#define cbi(x,y) x &= ~(_BV(y))
#define tbi(x,y) x ^= _BV(y)

uint8_t counter = 0;
uint8_t counter_last = 0;
uint8_t diff = 0;

ISR(INT0_vect){
   diff = counter - counter_last;
   counter_last = counter;
}
ISR(TIMER0_OVF_vect){
   counter++;
   if(diff > 2){
        sbi(PORTB, PB0);
   }else{
        cbi(PORTB, PB1);
   }
   if(diff > 10){
        sbi(PORTB, PB1);
   }else{
        cbi(PORTB, PB1);
   }
   if(diff > 20){
        sbi(PORTB, PB2);
   }else{
        cbi(PORTB, PB2);
   }
   if(diff > 30){
        sbi(PORTB, PB3);
   }else{
        cbi(PORTB, PB3);
   }
   if(diff > 40){
        sbi(PORTB, PB4);
   }else{
        cbi(PORTB, PB4);
   }
   
 }
int main()
 { 
   sbi(EICRA, ISC00);
   sbi(EICRA, ISC01);
   sbi(EIMSK, INT0);

   sbi(TCCR0B, CS00);
   sbi(TCCR0B, CS02);
   cbi(TCCR0B, CS01);
   sbi(TIMSK0, TOIE0);
    
   sbi(DDRB, PB0);
   sbi(DDRB, PB1);
   sbi(DDRB, PB2);
   sbi(DDRB, PB3);
   sbi(DDRB, PB5);

   sei();
   while (1);
   return 0;
 }