#ifndef _GPIO_H
#define _GPIO_H

#include <avr/io.h>

#define gpio_input 0
#define gpio_output 1
#define gpio_high 2
#define gpio_low 3

static volatile char *pc[] = {&PORTD,&PORTB,&PORTC,&DDRD,&DDRB,&DDRC,&PIND,&PINB,&PINC};

typedef enum
{
  pd0 = 0,pd1,pd2,pd3,pd4,pd5,pd6,pd7,pb0,pb1,pb2,pb3,pb4,pb5,pb6,pb7,pc1,pc2,pc3,pc4,pc5,pc6,pc7,a0 =16,a1,a2,a3,a4,a5
 
 }ATMEGA328_gpio_pins;

#define gpio_place_input(pin)  (*(pc [ 3 + ( pin >> 3) ]) &=~   ( 1 << (pin & 0x07)))
#define gpio_place_output(pin) (*(pc [ 3  + ( pin >> 3) ]) |=   ( 1 << (pin & 0x07)))
#define gpio_place_invert(pin) (*(pc [ 3  + ( pin >> 3) ]) ^=   ( 1 << (pin & 0x07)))

#define gpio_place_high(pin)   (*(pc [ 0  + ( pin >> 3) ]) |=   ( 1 << (pin & 0x07)))
#define gpio_place_low(pin)    (*(pc [ 0  + ( pin >> 3) ]) &=~  ( 1 << (pin & 0x07)))
#define gpio_place_change(pin) (*(pc [ 0  + ( pin >> 3) ]) ^=   ( 1 << (pin & 0x07)))

#define gpio_get(pin)          (*(pc [ 6  + ( pin >> 3) ]) &    ( 1 << (pin & 0x07)) ? gpio_high : gpio_low)

static inline void gpio_pin_direction(int pin , int logic)
{
  if(logic == gpio_input) gpio_place_input(pin);
  else if(logic == gpio_output) gpio_place_output(pin);
  else gpio_place_invert(pin);
}

static inline void gpio_pin_sbit(int pin , int logic)
{
  if(logic == gpio_high) gpio_place_high(pin);
  else if (logic == gpio_low) gpio_place_low(pin);
  else gpio_place_change(pin);
}

#endif
  
