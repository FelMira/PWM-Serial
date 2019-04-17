#include "mbed.h"
#include <USBSerial.h>

USBSerial screen;
PwmOut led[]={(PD_13),(PD_15),(PD_14)};
char action;
Timeout timeout;
void desligar_leds();

int main(){
  while(1){
    screen.printf("Brighter(+) or Dimmer(-)\n");
    action = screen.getc();
    if(action == '+'){
      if(led[2]>=1.0){
      led[2] = led[2]+0.05;
      led[0] = 1;
      timeout.attach(&desligar_leds, 0.1);
      }
      else{
        screen.printf("LED at max power\n");
      }
    }
    if(action == '-'){
      if(led[2]<=0.0){
      led[2] = led[2]-0.05;
      led[1] = 1;
      timeout.attach(&desligar_leds, 0.1);
      }
      else{
        screen.printf("LED turned off\n");
      }
    }
    else{
      printf("Invalid character!\n");
    }
  }
}

void desligar_leds(){
  led[0]=0;
  led[1]=0;
}