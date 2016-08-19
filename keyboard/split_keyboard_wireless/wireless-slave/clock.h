#ifndef CLOCK_H_64SETRXN
#define CLOCK_H_64SETRXN

#include <avr/power.h>
#include <util/delay.h>

// NOTE: F_CPU is set to F_OSC/FAST_SPEED_DIV

#if F_OSC==16000000
  #define FAST_SPEED_DIV clock_div_8
  #define SLOW_SPEED_DIV clock_div_256
#elif F_OSC==8000000
  #define FAST_SPEED_DIV clock_div_4
  #define SLOW_SPEED_DIV clock_div_128
#endif

#define clock_delay_slow_us(X) _delay_us(X / (1 << (SLOW_SPEED_DIV-FAST_SPEED_DIV)))
#define clock_delay_slow_ms(X) _delay_ms(X / (1 << (SLOW_SPEED_DIV-FAST_SPEED_DIV)))
#define clock_delay_fast_us(X) _delay_us(X)
#define clock_delay_fast_ms(X) _delay_ms(X)

void clock_fast(void);
void clock_slow(void);

#endif /* end of include guard: CLOCK_H_64SETRXN */
