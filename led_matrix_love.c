#include <avr/io.h>
#include <util/delay.h>

#define SHIFT_REGISTER DDRB
#define SHIFT_PORT PORTB
#define DATA (1<<PB3)   //MOSI (SI)
#define LATCH (1<<PB2)    //SS   (RCK)
#define CLOCK (1<<PB5)    //SCK  (SCK)

int main(void)
{
  //Setup IO
  SHIFT_REGISTER |= (DATA | LATCH | CLOCK); //Set control pins as outputs
  SHIFT_PORT &= ~(DATA | LATCH | CLOCK);    //Set control pins low

  //Setup SPI
  SPCR = (1<<SPE) | (1<<MSTR);  //Start SPI as Master
 
  //Pull LATCH low (Important: this is necessary to start the SPI transfer!)
  SHIFT_PORT &= ~LATCH;

  //Shift in some data
  SPDR = 0b01010111;

  //Wait for SPI process to finish
  while(!(SPSR & (1<<SPIF)));

  //Toggle latch to copy data to the storage register
  SHIFT_PORT |= LATCH;
  SHIFT_PORT &= ~LATCH;

  _delay_ms(1400);

  SPDR = 0b10000001;
  while(!(SPSR & (1<<SPIF)));

  SHIFT_PORT |= LATCH;
  SHIFT_PORT &= ~LATCH;

  _delay_ms(1400);

  /*SPDR = 0b11111101;

  while(!(SPSR & (1 << SPIF)));
  
  SHIFT_PORT |= LATCH;
  SHIFT_PORT &= ~LATCH;

  _delay_ms(1400);
*/


}
