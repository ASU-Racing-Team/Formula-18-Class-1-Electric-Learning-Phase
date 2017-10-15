#include "gpio.h"
#include "main.h"
void init_gpio(){
   sbi(DDRD, PD0);
    cbi(PORTD, PD0);
    sbi(DDRD, PD1);
    cbi(PORTD, PD1);
    sbi(DDRD, PD2);
    cbi(PORTD, PD2);
   }