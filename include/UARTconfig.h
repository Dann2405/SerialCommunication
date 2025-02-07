#ifndef UARTCONFIG_H
#define UARTCONFIG_H

#define UART_ID uart0    // Seleciona a UART0
#define BAUD_RATE 115200 // Define a taxa de transmissão
#define UART_TX_PIN 0    // Pino GPIO usado para TX
#define UART_RX_PIN 1    // Pino GPIO usado para RX

char command[2];                // Variável para armazenar o comando recebido
bool command_received = false;  // flag para indicar se um comando foi recebido
bool prompt_exibido = false;    // flag para indicar se o prompt foi exibido
uint32_t last_command_time = 0; // vai armazenar o tempo do último comando recebido

void my_uart_init()
{
    uart_init(UART_ID, BAUD_RATE);                  // Inicializa o UART com a taxa de transmissão definida
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART); // configura o pino TX
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART); // configura o pino RX
}

// função para processar o comando recebido
void process_command(const char *command)
{
    switch (command[0])
    {
    case '0':
        set_number0(led_r, led_g, led_b);
        break;
    case '1':
        set_number1(led_r, led_g, led_b);
        break;
    case '2':
        set_number2(led_r, led_g, led_b);
        break;
    case '3':
        set_number3(led_r, led_g, led_b);
        break;
    case '4':
        set_number4(led_r, led_g, led_b);
        break;
    case '5':
        set_number5(led_r, led_g, led_b);
        break;
    case '6':
        set_number6(led_r, led_g, led_b);
        break;
    case '7':
        set_number7(led_r, led_g, led_b);
        break;
    case '8':
        set_number8(led_r, led_g, led_b);
        break;
    case '9':
        set_number9(led_r, led_g, led_b);
        break;
    default:
        printf("\nComando inválido\n");
        break;
    }
    printf("\nComando recebido: %s\n", command);
}

// função para ler dados via UART
void uart_read()
{
    if (!prompt_exibido) // Se o prompt não foi exibido, exibe
    {
        printf("Digite um comando: ");
        prompt_exibido = true;
    }
    if (uart_is_readable(UART_ID)) // Verifica se há dados disponíveis para leitura
    {
        int index = 0; // Índice para armazenar os caracteres recebidos
        while (index < sizeof(command) - 1) // Enquanto houver espaço no buffer
        {
            int character = uart_getc(UART_ID); // Lê um caractere
            if (character != PICO_ERROR_TIMEOUT)// Se houver um caractere disponível
            {
                command[index++] = (char)character; // Armazena o caractere no buffer
                if (character == '\n' || character == '\r') // Se o caractere for um retorno de carro ou nova linha
                {
                    break; // sai do loop
                }
            }
        }
        command[index] = '\0'; // Adiciona o terminador de string
        if (index > 0) // Se houver dados no buffer
        {
            process_command(command); // Processa o comando
            prompt_exibido = false; // Para exibir o prompt novamente na próxima vez
        }
    }
}

// Função para ler dados via USB
void usb_read()
{
    if (stdio_usb_connected())
    {                                  // Verifica se o USB está conectado
        int c = getchar_timeout_us(0); // Tenta ler sem bloqueio (retorna PICO_ERROR_TIMEOUT se não houver dado)
        if (c != PICO_ERROR_TIMEOUT) // Se houver um caractere disponível
        {
            command[0] = (char)c; // Armazena o caractere no buffer
            command[1] = '\0'; // Adiciona o terminador de string
            process_command(command); // Processa o comando
        }
    }
}

#endif