#include <avr/io.h>
#include <util/delay.h>

#define led1 128 // 0b10000000
#define led2 64  // 0b01000000
#define buttons 3 // 0b00000011


int main(){

  short button_input = 0;
  
  DDRD = DDRD | led1 | led2;
  PORTD = PORTD | led1 | led2 | buttons;
 
  while(1){
    button_input = PIND & buttons;

    if(button_input != 3){
      if(button_input == 0){
        PORTD ^= led1; //Third button pressed
      }
      else{
        PORTD ^= led2; //one of the other was pressed
      }
    _delay_ms(150);
    }
  }
  
  return 0;
}
