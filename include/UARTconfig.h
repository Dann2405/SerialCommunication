#ifndef UARTCONFIG_H
#define UARTCONFIG_H

#define UART_ID uart0    // Seleciona a UART0
#define BAUD_RATE 115200 // Define a taxa de transmissão
#define UART_TX_PIN 0    // Pino GPIO usado para TX
#define UART_RX_PIN 1    // Pino GPIO usado para RX

char command[1]; // Variável para armazenar o comando recebido
bool command_received = false; // flag para indicar se um comando foi recebido
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

// Função para ler dados da UART
void uart_read()
{
    printf("Digite um comando: ");
    if (uart_is_readable(UART_ID)) // verifica se a UART está pronta para leitura
    {
        int index = 0; // índice para armazenar os caracteres recebidos
        while (index < sizeof(command) - 1) // loop para ler os caracteres recebidos
        {
            int character = uart_getc(UART_ID); // lê um caractere da UART
            if (character != PICO_ERROR_TIMEOUT) // verifica se o caractere é válido
            {
                command[index++] = (char)character; // armazena o caractere na variável command
                if (character == '\n' || character == '\r') // verifica se o caractere é um caractere de nova linha
                {
                    break; // sai do loop
                }
            }
        }
        command[index] = '\0'; // adiciona o caractere nulo ao final da string
        if (index > 0) // verifica se algum caractere foi recebido
        {
            process_command(command); // processa o comando recebido
            command_received = true; // define a flag para indicar que um comando foi recebido
        }
    }

    if (!command_received) // verifica se um comando foi recebido
    {
        if (scanf("%1s", command) == 1) // lê um comando da entrada padrão 
        {
            process_command(command); // processa o comando recebido
        }
    }
}


#endif