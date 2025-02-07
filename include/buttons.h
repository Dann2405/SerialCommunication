#ifndef BUTTONS
#define BUTTONS

const uint BUTTON_A = 5; // Botão A conectado ao GPIO 5
const uint BUTTON_B = 6; // Botão B conectado ao GPIO 6

volatile bool debounce_active = false; // vai controlar se o botão pode ser prssionado novamente
struct repeating_timer debounce_timer; // cria um temporizador para debounce (timer programavel)
volatile uint last_pressed_button = 0; // Último botão pressionado

void button_init()
{
    // Inicializa os botões A e B
    gpio_init(BUTTON_A);
    gpio_init(BUTTON_B);

    // Define os botões como entrada
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_set_dir(BUTTON_B, GPIO_IN);

    // Define os botões como pull up
    gpio_pull_up(BUTTON_A);
    gpio_pull_up(BUTTON_B);
}

// Protótipos das funções
void gpio_irq_handler(uint gpio, uint32_t events);
bool debounce_timer_callback(struct repeating_timer *t);
// Interação com o Botão A
// • Pressionar o botão A deve alternar o estado do LED RGB Verde (ligado/desligado).

// Interação com o Botão B
// • Pressionar o botão B deve alternar o estado do LED RGB Azul (ligado/desligado).

// Interrupção de GPIO para capturar a pressão do botão (com debounce)
void gpio_irq_handler(uint gpio, uint32_t events)
{
    // verificar se o debounce não está ativo para permitir a leitura do botão
    if (!debounce_active)
    {
        debounce_active = true;                                                     // ativa o debounce
        last_pressed_button = gpio;                                                 // Salva qual botão foi pressionado
        add_repeating_timer_ms(50, debounce_timer_callback, NULL, &debounce_timer); // inicia um timer de 50 ms para o debounce
    }
}

// Callback de debounce
bool debounce_timer_callback(struct repeating_timer *t)
{

    if (gpio_get(last_pressed_button) == 0) // Vai pegar o ultimo botão pressionado e definir ele como low
    {
        if (last_pressed_button == BUTTON_A) // Ao pressionar o botão A, ele vai ligar ou desligar
        {
            led_state_verde = !led_state_verde; // Se o led_state = false, ao pressionar o botão, led_state = true. Se led_state = true ao pressionar o botão, led_state = false.
            led_verde_on();
            // se o led for ligado ou desligar uma mensagem será exibida no serial monitor
            if(led_state_verde == true)
            {
                printf("\nBOTAO A PRESSIONADO. \nESTADO DO LED VERDE: LIGADO!\n");
            }
            else if (led_state_verde == false)
            {
                printf("\nBOTAO A PRESSIONADO. \nESTADO DO LED VERDE: DESLIGADO!\n");
            }
        }
    }
    else if (last_pressed_button == BUTTON_B) // Ao pressionar o botão B, ele vai ligar ou desligar
    {
        led_state_azul = !led_state_azul;
        led_blue_on();
        // se o led for ligado ou desligar uma mensagem será exibida no serial monitor
        if(led_state_azul == true)
        {
            printf("\nBOTAO B PRESSIONADO. \nESTADO DO LED AZUL: LIGADO!\n");
        }
        else if(led_state_azul == false)
        {
            printf("\nBOTAO B PRESSIONADO. \nESTADO DO LED AZUL: DESLIGADO!\n");
        }
    }

    debounce_active = false;
    return false;
}

#endif