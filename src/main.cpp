#include "mbed.h"

Serial screen(USBTX,USBRX,9600);
PwmOut led(PA_9);
char action;

int main(){
  while(1){
    screen.printf("Brighter(+) or Dimmer(-)\n");
    action = screen.getc();
    if(action == '+'){
      led = led+0.05;
    }
    if(action == '-'){
      led = led-0.05;
    }
    else{
      printf("Invalid character!\n");
    }
  }
}