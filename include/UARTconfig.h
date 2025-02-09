#ifndef UARTCONFIG_H
#define UARTCONFIG_H

// Cabeçalhos responsavel por definir as funções de comunicação via UART e USB

#define UART_ID uart0    // Seleciona a UART0
#define BAUD_RATE 115200 // Define a taxa de transmissão
#define UART_TX_PIN 0    // Pino GPIO usado para TX
#define UART_RX_PIN 1    // Pino GPIO usado para RX

char command[10];               // Variável para armazenar o comando recebido
bool prompt_exibido = false;    // flag para indicar se o prompt foi exibido
uint32_t last_command_time = 0; // vai armazenar o tempo do último comando recebido
bool command_received = false; // flag para indicar se um comando foi recebido

// inicializa a UART
void my_uart_init()
{
    uart_init(UART_ID, BAUD_RATE);                  // Inicializa o UART com a taxa de transmissão definida
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART); // configura o pino TX
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART); // configura o pino RX
}

// função para processar o comando recebido via UART
void process_command(const char *command)
{
    switch (command[0])
    {
    case '0':
        set_number0(led_r, led_g, led_b);
        numero_zero(); // Atualiza o display
        break;
    case '1':
        set_number1(led_r, led_g, led_b);
        numeros_um(); // Atualiza o display
        break;
    case '2':
        set_number2(led_r, led_g, led_b);
        numero_dois(); // Atualiza o display
        break;
    case '3':
        set_number3(led_r, led_g, led_b);
        numero_tres(); // Atualiza o display
        break;
    case '4':
        set_number4(led_r, led_g, led_b);
        numero_quatro(); // Atualiza o display
        break;
    case '5':
        set_number5(led_r, led_g, led_b);
        numero_cinco();// Atualiza o display
        break;
    case '6':
        set_number6(led_r, led_g, led_b);
        numero_seis(); // Atualiza o display
        break;
    case '7':
        set_number7(led_r, led_g, led_b);
        numero_sete(); // Atualiza o display
        break;
    case '8':
        set_number8(led_r, led_g, led_b);
        numero_oito();// Atualiza o display
        break;
    case '9':
        set_number9(led_r, led_g, led_b);
        numero_nove(); // Atualiza o display
        break;
    case 'g':
    case 'G':
        led_state_verde = !led_state_verde; // Se o led_state = false, ao pressionar o botão, led_state = true. Se led_state = true ao pressionar o botão, led_state = false.
        if(led_state_verde == 1)
        {
            led_verde_on(); // Liga o led
            led_verde_ON_display(); // Atualiza o display
        }
        else
        {
            led_verde_on(); // Desliga o led
            led_verde_OFF_display(); // Atualiza o display
        }
        break;
    case 'b':
    case 'B':
        led_state_azul = !led_state_azul; // Se o led_state = false, ao pressionar o botão, led_state = true. Se led_state = true ao pressionar o botão, led_state = false.
        if (led_state_azul == 1)
        {
            led_blue_on();// Liga o led
            led_azul_ON_display(); // Atualiza o display
        }
        else
        {
            led_blue_on(); // Desliga o led
            led_azul_OFF_display(); // Atualiza o display
        }
        break;
    case 'r':
    case 'R': // Se o comando recebido for 'r' ou 'R'
        led_state_vermelho = !led_state_vermelho;
        if (led_state_vermelho == 1)
        {
            led_vermelho_on(); // Liga o led
            led_vermelho_ON_display(); // Atualiza o display
        }
        else
        {
            led_vermelho_on(); // Desliga o led
            led_vermelho_OFF_display(); // Atualiza o display
        }
        break;
    case 'D':
    case 'd':
        imagem_inicial(); // Atualiza o display
        break;
    default:
        printf("\nComando inválido\n");
        comando_invalido(); // Atualiza o display
        break;
        printf("\nComando recebido: %s\n", command);
    }
}

// função para ler dados via UART
void uart_read()
{
    // Lê o comando via UART
    if (uart_is_readable(UART_ID))
    {
        int index = 0; // Índice para armazenar o caractere recebido
        // Enquanto houver espaço no buffer
        while (index < sizeof(command) - 1)
        {
            int character = uart_getc(UART_ID); // Lê o caractere
            if (character != PICO_ERROR_TIMEOUT) // Se houver um caractere disponível
            {
                command[index++] = (char)character; // Armazena o caractere no buffer
                if (character == '\n' || character == '\r') // Se for um caractere de nova linha
                {
                    break; // sai do loop
                }
            }
        }
        command[index] = '\0'; // Adiciona o terminador de string
        if (index > 0) // Se houver algum caractere no buffer
        {
            process_command(command); // Processa o comando
            command_received = true; // Indica que um comando foi recebido
        }
    }

    if (!command_received) // se nao houver comando recebido
    {
        if (scanf("%1s", command) == 1) // Tenta ler um caracterer via scanf
        {
            process_command(command); // Processa o comando
        }
    }
}

// Função para ler dados via USB
void usb_read()
{
    if (stdio_usb_connected())
    {                                  // Verifica se o USB está conectado
        int c = getchar_timeout_us(0); // Tenta ler sem bloqueio (retorna PICO_ERROR_TIMEOUT se não houver dado)
        if (c != PICO_ERROR_TIMEOUT)   // Se houver um caractere disponível
        {
            command[0] = (char)c;     // Armazena o caractere no buffer
            command[1] = '\0';        // Adiciona o terminador de string
            process_command(command); // Processa o comando
        }
    }
}

#endif