#ifndef BIBLIOTECAS_H
#define BIBLIOTECAS_H

// Cabeçalho responsavel por incluir todas as bibliotecas necessárias para o projeto, feito para facilitar a inclusão de bibliotecas e uma melhor organização do código

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/uart.h"

// pio.h
#include "ws2812.pio.h"
void ws2812_init(); // prototipo da inicialização do ws281.pio

// Cabeçalhos .h da pasta include
#include "include/matrixWS2812.h"
#include "include/leds.h"
#include "include/ssd1306/font.h"
#include "include/ssd1306/ssd1306.h"
#include "include/ssd1306/configDisplay.h"
#include "include/buttons.h"
#include "include/UARTconfig.h"

// inicialização do ws2812.pio
void ws2812_init()
{
    PIO pio = pio0;                                      // Configuração do PIO 0
    int sm = 0;                                          // Define o estado da máquina de estado do PIO (SM)
    uint offset = pio_add_program(pio, &ws2812_program); // Vai carregar o programa do PIO para controlar os LEDs WS2812

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW); // Vai inicializar o programa de controle do WS2812 no PIO
}

#endif