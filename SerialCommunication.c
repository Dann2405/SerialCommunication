#include "include/bibliotecas.h"

int main()
{
    stdio_init_all();
    ws2812_init();
    leds_init();
    button_init();

    // Configuração da interrupção com callback para botão A E B
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    my_uart_init(); // Inicializa a UART

    while (true)
    {
        sleep_ms(150);
        uart_read();    // Inicializa a leitura da UART
    }
}