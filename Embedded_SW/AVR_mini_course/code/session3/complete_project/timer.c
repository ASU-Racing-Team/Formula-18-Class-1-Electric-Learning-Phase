#include "timer.h"
#include "main.h"
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
