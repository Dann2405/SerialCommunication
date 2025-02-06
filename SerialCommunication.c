#include "include/bibliotecas.h"

int main()
{
    stdio_init_all();
    ws2812_init();

    set_number0(200, 0, 0);

    while (true) {
        sleep_ms(500);
        printf("Hello, world!\n");
    }
}

void ws2812_init()
{
    PIO pio = pio0;                                      // Configuração do PIO 0
    int sm = 0;                                          // Define o estado da máquina de estado do PIO (SM)
    uint offset = pio_add_program(pio, &ws2812_program); // Vai carregar o programa do PIO para controlar os LEDs WS2812

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW); // Vai inicializar o programa de controle do WS2812 no PIO
}