#include "main.h"

uint8_t counter = 0;
uint8_t current_displayed_number = 0;
uint8_t button_samples[5];
uint8_t counting = 1;
uint8_t seg1 = 1;
uint8_t counter2 = 0;
uint8_t i = 0;

int main() {
    
    init_timer0();
    init_sevenseg();
    init_button();
    enable_seg2();
    enable_seg1();
    sei();
    while(1);
        
    return 0;
}
ISR(TIMER0_OVF_vect){
   
       // Task 1
   if((PIND&1)==0){
      if(counting == 1)
	 counting = 0;
      else
	 counting = 1;
   }
   // Task 2
   if(counter == 200){
      if(current_displayed_number<100){
	    current_displayed_number++;
      }else{
	    current_displayed_number = 0;
      }
      counter = 0;
   }
   if(counting){
      if(counter2 == 2){
	 if(seg1 == 1){
	    disable_seg1();
	    write_to_seg(current_displayed_number/10);
	    enable_seg2();
	    seg1 = 0;
	 }else{
	    disable_seg2();
	    write_to_seg(current_displayed_number%10);
	    enable_seg1();
	    seg1 = 1;
	 }
	 counter2 = 0;
      }
   }	
   counter2++;
   counter++;
}