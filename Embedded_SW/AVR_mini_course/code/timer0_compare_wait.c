#include <avr/io.h>
#define sbi(x,y) x |= _BV(y)
#define cbi(x,y) x &= ~(_BV(y))
#define tbi(x,y) x ^= _BV(y)
#define is_high(x,y) (x & _BV(y) == _BV(y))

int main(void){
    // initialize
    while(1){
        if(is_high(TIFR0, OCF0A)){
            
        }
    }
}