#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

// pio.h
#include "ws2812.pio.h"
void ws2812_init(); // prototipo da inicialização do ws281.pio

// Cabeçalhos .h da pasta include
#include "include/matrixWS2812.h"
#include "include/leds.h"
#include "include/buttons.h"