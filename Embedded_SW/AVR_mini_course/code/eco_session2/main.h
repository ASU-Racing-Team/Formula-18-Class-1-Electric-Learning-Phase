#pragma once
#include <avr/interrupt.h>
#include <stdint.h>
#include "timer0.h"
#include "led.h"

#define sbi(x,y) x |= _BV(y)
#define cbi(x,y) x &= ~(_BV(y))
#define tbi(x,y) x ^= _BV(y)
#define is_high(x,y) (x & _BV(y) == _BV(y))