#include <avr/io.h>

int main(void) {
  DDRC = 0b00111111;
  PORTC &= ~0b00111111;

  DDRB = 0b00000011;
  PORTB &= ~0b00000011;

  uint8_t counter = 0;
  while(1) {
    PORTC = counter;
    PORTB = counter >> 6; //Shift the counter so MSB is on PB0 and PB1

    ++counter;
  }
}
