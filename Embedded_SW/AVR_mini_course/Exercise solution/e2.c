#include <stdio.h>
#include <stdint.h>
int main(void){
    uint16_t in;
    scanf("%d",&in);
    uint8_t in12 = (in & (1<<12))>>12;
    if(in12 == 1){
        in = in ^ (1<<6);
        in = in | 1;
        in = in &(~(1<<15));
    }else{
        in = in ^ ((~0) & (~(1<<7)));
    }
    printf("%d", in);
}

// when input is 36666 output is 28741
// when input is 40762 output is 8059