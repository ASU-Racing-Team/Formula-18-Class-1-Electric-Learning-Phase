#include "led.h"
#include "main.h"

void init_leds(){
    sbi(DDRD, PD0);
    cbi(PORTD, PD0);
    sbi(DDRD, PD1);
    cbi(PORTD, PD1);
    sbi(DDRD, PD2);
    cbi(PORTD, PD2);
}
void led0_turn_on(){
   sbi(PORTD, PD0);
}
void led1_turn_on(){
   sbi(PORTD, PD1);
}
void led2_turn_on(){
   sbi(PORTD, PD2);
}
void led0_turn_off(){
   cbi(PORTD, PD0);
}
void led1_turn_off(){
   cbi(PORTD, PD1);
}
void led2_turn_off(){
   cbi(PORTD, PD2);
}
void led0_toggle(){
   tbi(PORTD, PD0);
}
void led1_toggle(){
   tbi(PORTD, PD1);
}
void led2_toggle(){
   tbi(PORTD, PD2);
}