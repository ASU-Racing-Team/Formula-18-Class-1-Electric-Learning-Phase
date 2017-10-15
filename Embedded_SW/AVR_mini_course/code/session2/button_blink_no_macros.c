#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

int main()
 { 
   DDRD |= _BV(PD3);
   DDRD &= ~_BV(PD2);
   PORTD |= _BV(PD2);
   while (1){
      _delay_ms(100);
      if((PIND & _BV(PD2)) != 0){
	 PORTD ^=_BV(PD3);
      }else{
	 PORTD &= ~_BV(PD3);
      }
   }
   return 0;
 }