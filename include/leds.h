#ifndef LEDS
#define LEDS

const uint LED_R = 13; // Led vermelho conectado ao GPIO 13
const uint LED_G = 11; // Led Verde conectado ao GPIO 11
const uint LED_B = 12; // Led azul conectado ao GPIO 12

volatile bool led_state_verde = 0;
volatile bool led_state_azul = 0;
volatile bool led_state_vermelho = 0;

void leds_init()
{
    // inicializando os LEDs
    gpio_init(LED_R);
    gpio_init(LED_G);
    gpio_init(LED_B);

    // definindo os LEDs como saida
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_set_dir(LED_B, GPIO_OUT);
}

void led_verde_on()
{
    gpio_put(LED_G, led_state_verde);
}

void led_blue_on()
{
    gpio_put(LED_B, led_state_azul);
}
void led_vermelho_on()
{
    gpio_put(LED_R, led_state_vermelho);
}

#endif