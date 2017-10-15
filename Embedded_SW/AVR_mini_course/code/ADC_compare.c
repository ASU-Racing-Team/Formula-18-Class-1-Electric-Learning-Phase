#include<avr/io.h>
#define COMPARE_VALUE 125
#define sbi(x,y) x |= _BV(y) 
#define cbi(x,y) x &=~_BV(y)

int main(void)
{
    DDRB |= _BV(PB0) | _BV(PB1);
    PORTB &= ~(_BV(PB0)|_BV(PB1));
    DDRA=0x00; //PORTA set as input (since we want to take inputs for the ADC)
    PORTA=0xff; //Enable the pull-ups on PORTA
    ADMUX |= _BV(ADLAR); // left align for 8 bit mode only
    ADMUX |= 0b0101; // choose pin PC5
    ADCSRA = _BV(ADEN) | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0); //Enable the ADC with prescaler=128
    ADCSRA |=_BV(ADSC); //Set the bit to start the conversion
    
    while(1)
    {
        while(ADCSRA &_BV(ADSC)) {} //Waits for ADC conversion to complete

        if(ADCH>=COMPARE_VALUE)
        {
			sbi(PORTB,PB1);
			cbi(PORTB,PB0);
        }
        else if (ADCH<COMPARE_VALUE)
        {
			sbi(PORTB,PB0);
            cbi(PORTB,PB1);
        }
        ADCSRA |=_BV(ADSC); //Set the bit to start conversion again
    }
    return 0;
}