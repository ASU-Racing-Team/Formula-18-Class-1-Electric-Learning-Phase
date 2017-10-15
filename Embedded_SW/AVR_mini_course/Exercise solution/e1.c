#include <stdio.h>
#include <stdint.h>
int main(void){
    uint32_t sum = 0;
    for(uint32_t i = 1; i <= 10000; i ++){
        if(i%3 == 0 || i%5 == 0){
            sum += i;
        }
    }
    printf("%d\n",sum);
}
// prints 23341668