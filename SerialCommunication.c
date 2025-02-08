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
    displayssd1306_init(); // Inicializa o display
    config_display(); // Configura o display
    imagem_inicial(); // Exibe a imagem inicial no display

    while (true)
    {
        sleep_ms(100);
        usb_read();
        //uart_read();
    }
}