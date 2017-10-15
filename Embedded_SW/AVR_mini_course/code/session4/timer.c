#include "timer.h"
#include "main.h"
void init_timer0(){
    cbi(TCCR0B, CS00);
    sbi(TCCR0B, CS01);
    cbi(TCCR0B, CS02);
    sbi(TIMSK0, TOIE0);
}
