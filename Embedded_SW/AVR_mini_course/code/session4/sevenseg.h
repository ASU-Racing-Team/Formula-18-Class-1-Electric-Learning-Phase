#pragma once
#include <avr/io.h>
#include "main.h"
void init_sevenseg();
void enable_seg1();
void disable_seg1();
void enable_seg2();
void disable_seg2();
void write_to_seg(uint8_t num);


