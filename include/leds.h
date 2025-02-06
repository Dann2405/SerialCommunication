#ifndef LEDS
#define LEDS

// bibliotecas
#include <stdio.h>
#include "pico/stdlib.h"


const uint LED_R = 13; // Led vermelho conectado ao GPIO 13
const uint LED_G = 11; // Led Verde conectado ao GPIO 11
const uint LED_B = 12; // Led azul conectado ao GPIO 12

bool led_state = false;

void leds_init()
{
    //inicializando os LEDs
    gpio_init(LED_R);
    gpio_init(LED_G);
    gpio_init(LED_B);

    // definindo os LEDs como saida
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_set_dir(LED_B, GPIO_OUT);
}

#endif