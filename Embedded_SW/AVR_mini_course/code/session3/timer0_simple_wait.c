#include <avr/io.h>
#include <stdint.h>
#define sbi(x,y) x |= _BV(y)
#define cbi(x,y) x &= ~(_BV(y))
#define tbi(x,y) x ^= _BV(y)
#define is_high(x,y) (x & _BV(y) == _BV(y))
// wifi Tarek
// password ytha2018
uint8_t counter = 0;
int main()
 { 
   // Timer 0 Initialization
    sbi(TCCR0B, CS00);
    sbi(TCCR0B, CS02);
    cbi(TCCR0B, CS01);
   // Gpio pin PD5 initilization
    sbi(DDRD, PD5);
    cbi(PORTD, PD5);
   while (1){
	 if(is_high(TIFR0, TOV0)){
	       counter++;
	       cbi(TIFR0, TOV0); 
	 }
	 if(counter == 6){
	       tbi(PORTD, PD5);
	       counter = 0;
	    }
      }
   return 0;
 }