
#include <avr/io.h>
#define sbi(x,y) x |= _BV(y) //set bit
#define cbi(x,y) x &= ~(_BV(y)) //clear bit
#define tbi(x,y) x ^= _BV(y) //toggle bit
#define is_high(x,y) ((x & _BV(y)) == _BV(y))

int main(void)
{
    uint8_t i, j, k;
    sbi(DDRD, PD5);
    cbi(PORTD, PD5);

    while(1) //Infinite loop
    {
        for(j=0;j<100;j++)
        {
            for(k=0;k<255;k++)
            {
                for(i=0;i<100;i++)
                {
                    if(i<j) sbi(PORTD,PD5);
                    else cbi(PORTD,PD5);
                }
            }
        }
    }
    return 0;
}