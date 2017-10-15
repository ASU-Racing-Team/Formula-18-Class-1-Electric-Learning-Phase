#include <avr/io.h>
#include <util/delay.h>
 

 
int main (void)
{
 /* set pin 5 of PORTB for output*/
 DDRB |= (1<<5);
 
 while(1) {
  /* set pin 5 high to turn led on */
  PORTB |= (1<<5);
  _delay_ms(1000);
 
  /* set pin 5 low to turn led off */
  PORTB &= ~(1<<5);
  _delay_ms(1000);
 }
}