#include <avr/io.h>
#include <avr/interrupts.h>
#include <stdint.h>

uint8_t adc0_value = 0;
uint8_t adc1_value = 0;
uint8_t adc2_value = 0;
uint8_t adc3_value = 0;

uint8_t current_pin = 0;

void avr_init(void);

ISR(ADC_vect)
{
    
    switch(current_pin){
        case 0:
            adc0_value = ADCH; // update global variable
            ADMUX &= 0xf0;
            ADMUX |= 1;
            current_pin = 1;
            break;
        case 1:
            adc1_value = ADCH; // update global variable
            ADMUX &= 0xf0;
            ADMUX |= 2;
            current_pin = 2;
            break;
        case 2:
            adc2_value = ADCH; // update global variable
            ADMUX &= 0xf0;
            ADMUX |= 3;
            current_pin = 3;
            break;
        case 3:
            adc3_value = ADCH; // update global variable
            ADMUX &= 0xf0;
            ADMUX |= 0;
            current_pin = 0;
            break;
    }
    ADCSRA |= _BV(ADSC); // start new conversion
}
ISR(TIMER0_OVF_vect){
   if(adc0_value > 100){

   }
   if(adc1_value > 200){

   }
   if(adc2_value > 300){

   }
   if(adc3_value > 400){
       
   }
 }
int main(void)
{
    avr_init();
    sei();
    ADCSRA |= _BV(ADSC); // start the initial conversion to generate the first interrupt
    while(1);
}

void avr_init()
{
    sbi(DDRB, PB0); //PORTB output
    cbi(PORTB, PB0);
    sbi(ADCSRA, ADEN);

    sbi(ADCSRA, ADPS2);
    sbi(ADCSRA, ADPS1);

    sbi(ADCSRA, ADIE);

    ADCSRA = _BV(ADEN)| _BV(ADPS2) | _BV(ADPS1) | _BV(ADIE); //Prescaler 64 with 16Mhz to get sampling freq 19.2kHz
    ADMUX = _BV(ADLAR); // Left align for 8 but mode

    sbi(TCCR0B, CS00);
    sbi(TCCR0B, CS02);
    cbi(TCCR0B, CS01);
    sbi(TIMSK0, TOIE0);
}