#include "button.h"
#include "main.h"

void init_button(){
   sbi(DDRD, PD1);
}
uint8_t button_pressed(){
   if(is_high(PIND, PD0)){
      return 0;
   }else{
      return 1;
   }
}
