#include <avr/io.h>
#include <avr/interrupt.h>

int main(void) {
  DDRC = 0b00111111;
  PORTC &= ~0b00111111;

  DDRB = 0b00000011;
  PORTB &= ~0b00000011;

  TCCR2A = 1<<WGM21; //Use CTC mode
  TCCR2B = 1<<CS20; //System clock
  TIFR2 = 1<<OCF2A; //Clear OCF2

  TIMSK2 = 1<<OCIE2A; //Enable compare interrupt
  OCR2A = 142; //Set output compare value
  sei();

  while(1) {
    //Everything happens in interrupts
  }
}

ISR(TIMER2_COMPA_vect)
{
  static uint8_t counter = 0;

  PORTC = counter;        //Set PORTC
  PORTB = counter >> 6;   //Set PORTB

  counter++;

}
