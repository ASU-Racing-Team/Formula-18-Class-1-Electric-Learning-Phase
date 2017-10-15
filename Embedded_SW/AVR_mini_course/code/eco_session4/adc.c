#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#define sbi(x,y) x |= _BV(y)
#define cbi(x,y) x &= ~(_BV(y))
uint8_t adc0_value;
ISR(ADC_vect){
    adc0_value = ADCH;
    sbi(ADCSRA, ADSC);-
}
ISR(TIMER0_OVF_vect){
    if(adc0_value > ((3/5)*256)){
        sbi(PORTD, PD0);
    }else{
        cbi(PORTD, PD0);
    }
}
int main(){ 
    // Init ADC
    // enable adc
    sbi(ADCSRA, ADEN);
    // set left align
    sbi(ADMUX, ADLAR);
    // set prescaler bits to 111 (128)
    sbi(ADCSRA, ADPS0);
    sbi(ADCSRA, ADPS1);
    sbi(ADCSRA, ADPS2);
    // set adc read pin to ADC0
    cbi(ADMUX, MUX0);
    cbi(ADMUX, MUX1);
    cbi(ADMUX, MUX2);
    cbi(ADMUX, MUX3);
    // enable adc interrupt
    sbi(ADCSRA, ADIE);
    // init led
    // set pin PD0 as output
    sbi(DDRD, PD0);
    // turn off the led
    cbi(PORTD, PD0);
    // timer0 init with interrupt
    sbi(TCCR0B, CS00);
    sbi(TCCR0B, CS02);
    cbi(TCCR0B, CS01);
    sbi(TIMSK0, TOIE0);
    // start bootstrap conversion
    sbi(ADCSRA, ADSC);
    // enable global interrupts
    sei();
   while (1);
   return 0;
 }