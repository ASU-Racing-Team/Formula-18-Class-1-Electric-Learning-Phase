#include "sevenseg.h"
#include "main.h"

void init_sevenseg(){
      DDRB = _BV(PB0) |
             _BV(PB1) |
             _BV(PB2) |
             _BV(PB3) |
             _BV(PB4) |
             _BV(PB5) |
             _BV(PB6);
      DDRD |= _BV(PD6) | _BV(PD7);
      PORTB = 0;
}
void enable_seg1(){
    cbi(PORTD,PD6);
}
void disable_seg1(){
    sbi(PORTD,PD6);
}
void enable_seg2(){
    cbi(PORTD,PD7);
}
void disable_seg2(){
    sbi(PORTD,PD7);
}
void write_to_seg(uint8_t num){
    switch(num){
        case 0:
            PORTB = 0b00111111;
            break;
        case 1:
            PORTB = 0b00000110;
            break;
        case 2:
            PORTB = 0b01011011;
            break;
        case 3:
            PORTB = 0b01001111;
            break;
        case 4:
            PORTB = 0b01100110;
            break;
        case 5:
            PORTB = 0b01101101;
            break;
        case 6:
            PORTB = 0b01111101;
            break;
        case 7:
            PORTB = 0b00000111;
            break;
        case 8:
            PORTB = 0b01111111;
            break;
        case 9:
            PORTB = 0b01101111;
            break;
    }
}
