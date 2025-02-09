#include "include/bibliotecas.h"

int main()
{
    stdio_init_all(); // Inicializa a comunicação serial
    ws2812_init(); // Inicializa os LEDs WS2812
    leds_init(); // Inicializa os LEDs RGB
    button_init(); // Inicializa os botões A e B

    // Configuração da interrupção com callback para botão A E B
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    my_uart_init(); // Inicializa a UART
    displayssd1306_init(); // Inicializa o display
    config_display(); // Configura o display
    imagem_inicial(); // Exibe a imagem inicial no display

    // Recomendo utilizar o usb_read() pois usa menos do processador do que o uart_read(). 
    // Isso por que o uart_read() tem um scanf que consome muito processamento por conta do polling
    while (true)
    {
        sleep_ms(100);
        usb_read(); // Lê os dados recebidos via USB
        //uart_read(); // Lê os dados recebidos via UART
    }
}