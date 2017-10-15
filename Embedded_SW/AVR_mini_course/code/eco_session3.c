#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define sbi(x,y) x |= _BV(y)
#define cbi(x,y) x &= ~(_BV(y))
#define tbi(x,y) x ^= _BV(y)
#define is_high(x,y) ((x & _BV(y)) == _BV(y))

uint8_t crank_counter = 0;

void init_timer0();
void init_crank_sensor();
void init_cam_sensor();
uint8_t cam_is_high();
uint8_t crank_is_high();


int main()
 { 
   
   while (1);
   return 0;
 }
 
 void init_crank_sensor(){
    // make PD0 Input
    cbi(DDRD, PD0);
    // enable the pull up resistance
    sbi(PORTD, PD0);
 }
 void init_cam_sensor(){
     // make PD1 input
      cbi(DDRD, PD0);
     // enable the pull resistance
      sbi(PORTD, PD0);
 }
 uint8_t cam_is_high(){
      if(is_high(PIND, PD0)){
	 return 1;
      }else{
	 return 0;
	 }
 }
 uint8_t crank_is_high(){
      if(is_high(PIND, PD1)){
	 return 1;
      }else{
	 return 0;
      }
}   
 void init_timer0(){
      sbi(TCCR0B, CS00);
      sbi(TCCR0B, CS01);
      cbi(TCCR0B, CS02);
      cbi(TCCR0A, WGM00);
      sbi(TCCR0A, WGM01);
      cbi(TCCR0B, WGM02);
      OCR0A = 128;
      sbi(TIMSK0, OCIE0A);
}