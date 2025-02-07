#ifndef MATRIXWS2812
#define MATRIXWS2812

// Definições iniciais
#define WS2812_PIN 7
#define IS_RGBW false
#define columns 5
#define rows 5

uint8_t led_r = 0; // Intensidade do LED Vermelho
uint8_t led_g = 0; // Intensidade do LED Verde
uint8_t led_b = 200; // Intensidade do LED Azul

// BUFFER DE NUMEROS DE 0 A 9
bool number0[columns][rows] =
    {
        0, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 1, 1, 0}; // Vai exibir o numero zero

bool number1[columns][rows] =
    {
        0, 0, 1, 0, 0,
        0, 1, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 1, 1, 1, 0}; // Vai exibir o numero um

bool number2[columns][rows] =
    {
        0, 0, 1, 1, 0,
        0, 1, 0, 0, 1,
        0, 0, 0, 1, 0,
        0, 0, 1, 0, 0,
        0, 1, 1, 1, 1}; // Vai exibir o numero dois

bool number3[columns][rows] =
    {
        0, 0, 1, 1, 0,
        0, 1, 0, 0, 1,
        0, 0, 0, 1, 0,
        0, 1, 0, 0, 1,
        0, 0, 1, 1, 0
    }; // Vai exibir o numero três

bool number4[columns][rows] =
    {
        0, 0, 0, 1, 1,
        0, 0, 1, 0, 1,
        0, 1, 1, 1, 1,
        0, 0, 0, 0, 1,
        0, 0, 0, 0, 1
    }; // Vai exibir o numero 4


bool number5[columns][rows] =
    {
        0, 1, 1, 1, 1,
        0, 1, 1, 1, 0,
        0, 0, 0, 0, 1, 
        0, 1, 0, 0, 1,
        0, 0, 1, 1, 0
    }; // Vai exibir o numero 5

bool number6[columns][rows] = 
    {
        0, 1, 1, 1, 1,
        0, 1, 0, 0, 0, 
        0, 1, 1, 1, 1,
        0, 1, 0, 0, 1, 
        0, 1, 1, 1, 1
    }; // Vai exibir o numero 6

bool number7[columns][rows] =
    {
        0, 1, 1, 1, 1,
        0, 0, 0, 0, 1,
        0, 0, 0, 1, 0,
        0, 0, 1, 0, 0, 
        0, 1, 0, 0, 0
    }; // Vai exibir o numero 7

bool number8[columns][rows] =
    {
        0, 0, 1, 1, 0,
        0, 1, 0, 0, 1,
        0, 0, 1, 1, 0,
        0, 1, 0, 0, 1,
        0, 0, 1, 1, 0
    }; // Vai exibir o numero 8

bool number9[columns][rows] = 
    {
        0, 0, 1, 1, 0,
        0, 1, 0, 0, 1,
        0, 0, 1, 1, 1,
        0, 0, 0, 1, 0,
        0, 0, 1, 0, 0
    }; // vai exibir o numero 9

// função para enviar cor para o led
static inline void put_pixel(uint32_t pixel_grb)
{
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

// função que vai combinar os valores RGB em um inteiro de 32 bits
static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b)
{
    return ((uint32_t)(r) << 8) | ((uint32_t)(g) << 16) | ((uint32_t)(b));
}

// A baixo estão as funções para configuração da matrix 5x5 WS2812 em zigue-zague para o padrão serpente
// Number 0 - Matrix
void set_number0(uint8_t r, uint8_t g, uint8_t b)
{
    uint32_t color = urgb_u32(r, g, b); // Define a cor com base nos parâmetros das linhas 10 a 12

    for (int i = columns - 1; i >= 0; i--) // pecorre as linhas de cima para baixo
    {
        if ((columns - i) % 2 == 0) // As colunas Ler da direita para a esquerda (Colunas PAR)
        {
            for (int j = 0; j < rows; j++) // Linhas lidas da esquerda para a direita j = 0 até j for = 4
            {
                if (number0[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
        else // As colunas impares tem as direções invertidas (LINHAS são lidas da DIREITA para a ESQUERDA, criando assim um padrão zigue-zague)
        {
            for (int j = rows - 1; j >= 0; j--) // Ler da esquerda para a direita
            {
                if (number0[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
    }
}

// Number 1 - matrix
void set_number1(uint8_t r, uint8_t g, uint8_t b)
{
    uint32_t color = urgb_u32(r, g, b); // Define a cor com base nos parâmetros das linhas 10 a 12

    for (int i = columns - 1; i >= 0; i--) // pecorre as linhas de cima para baixo
    {
        if ((columns - i) % 2 == 0) // As colunas Ler da direita para a esquerda
        {
            for (int j = 0; j < rows; j++) // Linhas lidas da esquerda para a direita j = 0 até j for = 4
            {
                if (number1[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
        else // As colunas impares tem as direções invertidas (LINHAS são lidas da DIREITA para a ESQUERDA, criando assim um padrão zigue-zague)
        {
            for (int j = rows - 1; j >= 0; j--) // Ler da esquerda para a direita
            {
                if (number1[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
    }
}

// Number 2 - matrix
void set_number2(uint8_t r, uint8_t g, uint8_t b)
{
    uint32_t color = urgb_u32(r, g, b); // Define a cor com base nos parâmetros das linhas 10 a 12

    for (int i = columns - 1; i >= 0; i--) // pecorre as linhas de cima para baixo
    {
        if ((columns - i) % 2 == 0) // As colunas Ler da direita para a esquerda
        {
            for (int j = 0; j < rows; j++) // Linhas lidas da esquerda para a direita j = 0 até j for = 4
            {
                if (number2[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
        else // As colunas impares tem as direções invertidas (LINHAS são lidas da DIREITA para a ESQUERDA, criando assim um padrão zigue-zague)
        {
            for (int j = rows - 1; j >= 0; j--) // Ler da esquerda para a direita
            {
                if (number2[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
    }
}

// Number 3 - matrix
void set_number3(uint8_t r, uint8_t g, uint8_t b)
{
    uint32_t color = urgb_u32(r, g, b); // Define a cor com base nos parâmetros das linhas 10 a 12

    for (int i = columns - 1; i >= 0; i--) // pecorre as linhas de cima para baixo
    {
        if ((columns - i) % 2 == 0) // As colunas Ler da direita para a esquerda
        {
            for (int j = 0; j < rows; j++) // Linhas lidas da esquerda para a direita j = 0 até j for = 4
            {
                if (number3[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
        else // As colunas impares tem as direções invertidas (LINHAS são lidas da DIREITA para a ESQUERDA, criando assim um padrão zigue-zague)
        {
            for (int j = rows - 1; j >= 0; j--) // Ler da esquerda para a direita
            {
                if (number3[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
    }
}

// Number 4 - matrix
void set_number4(uint8_t r, uint8_t g, uint8_t b)
{
    uint32_t color = urgb_u32(r, g, b); // Define a cor com base nos parâmetros das linhas 10 a 12

    for (int i = columns - 1; i >= 0; i--) // pecorre as linhas de cima para baixo
    {
        if ((columns - i) % 2 == 0) // As colunas Ler da direita para a esquerda
        {
            for (int j = 0; j < rows; j++) // Linhas lidas da esquerda para a direita j = 0 até j for = 4
            {
                if (number4[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
        else // As colunas impares tem as direções invertidas (LINHAS são lidas da DIREITA para a ESQUERDA, criando assim um padrão zigue-zague)
        {
            for (int j = rows - 1; j >= 0; j--) // Ler da esquerda para a direita
            {
                if (number4[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
    }
}

// Number 5 - matrix
void set_number5(uint8_t r, uint8_t g, uint8_t b)
{
    uint32_t color = urgb_u32(r, g, b); // Define a cor com base nos parâmetros das linhas 10 a 12

    for (int i = columns - 1; i >= 0; i--) // pecorre as linhas de cima para baixo
    {
        if ((columns - i) % 2 == 0) // As colunas Ler da direita para a esquerda
        {
            for (int j = 0; j < rows; j++) // Linhas lidas da esquerda para a direita j = 0 até j for = 4
            {
                if (number5[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
        else // As colunas impares tem as direções invertidas (LINHAS são lidas da DIREITA para a ESQUERDA, criando assim um padrão zigue-zague)
        {
            for (int j = rows - 1; j >= 0; j--) // Ler da esquerda para a direita
            {
                if (number5[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
    }
}

// Number 6 - matrix
void set_number6(uint8_t r, uint8_t g, uint8_t b)
{
    uint32_t color = urgb_u32(r, g, b); // Define a cor com base nos parâmetros das linhas 10 a 12

    for (int i = columns - 1; i >= 0; i--) // pecorre as linhas de cima para baixo
    {
        if ((columns - i) % 2 == 0) // As colunas Ler da direita para a esquerda
        {
            for (int j = 0; j < rows; j++) // Linhas lidas da esquerda para a direita j = 0 até j for = 4
            {
                if (number6[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
        else // As colunas impares tem as direções invertidas (LINHAS são lidas da DIREITA para a ESQUERDA, criando assim um padrão zigue-zague)
        {
            for (int j = rows - 1; j >= 0; j--) // Ler da esquerda para a direita
            {
                if (number6[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
    }
}

// Number 7 - matrix
void set_number7(uint8_t r, uint8_t g, uint8_t b)
{
    uint32_t color = urgb_u32(r, g, b); // Define a cor com base nos parâmetros das linhas 10 a 12

    for (int i = columns - 1; i >= 0; i--) // pecorre as linhas de cima para baixo
    {
        if ((columns - i) % 2 == 0) // As colunas Ler da direita para a esquerda
        {
            for (int j = 0; j < rows; j++) // Linhas lidas da esquerda para a direita j = 0 até j for = 4
            {
                if (number7[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
        else // As colunas impares tem as direções invertidas (LINHAS são lidas da DIREITA para a ESQUERDA, criando assim um padrão zigue-zague)
        {
            for (int j = rows - 1; j >= 0; j--) // Ler da esquerda para a direita
            {
                if (number7[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
    }
}

// Number 8 - matrix
void set_number8(uint8_t r, uint8_t g, uint8_t b)
{
    uint32_t color = urgb_u32(r, g, b); // Define a cor com base nos parâmetros das linhas 10 a 12

    for (int i = columns - 1; i >= 0; i--) // pecorre as linhas de cima para baixo
    {
        if ((columns - i) % 2 == 0) // As colunas Ler da direita para a esquerda
        {
            for (int j = 0; j < rows; j++) // Linhas lidas da esquerda para a direita j = 0 até j for = 4
            {
                if (number8[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
        else // As colunas impares tem as direções invertidas (LINHAS são lidas da DIREITA para a ESQUERDA, criando assim um padrão zigue-zague)
        {
            for (int j = rows - 1; j >= 0; j--) // Ler da esquerda para a direita
            {
                if (number8[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
    }
}

// Number 9 - matrix
void set_number9(uint8_t r, uint8_t g, uint8_t b)
{
    uint32_t color = urgb_u32(r, g, b); // Define a cor com base nos parâmetros das linhas 10 a 12

    for (int i = columns - 1; i >= 0; i--) // pecorre as linhas de cima para baixo
    {
        if ((columns - i) % 2 == 0) // As colunas Ler da direita para a esquerda
        {
            for (int j = 0; j < rows; j++) // Linhas lidas da esquerda para a direita j = 0 até j for = 4
            {
                if (number9[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
        else // As colunas impares tem as direções invertidas (LINHAS são lidas da DIREITA para a ESQUERDA, criando assim um padrão zigue-zague)
        {
            for (int j = rows - 1; j >= 0; j--) // Ler da esquerda para a direita
            {
                if (number9[i][j])
                {
                    put_pixel(color); // Liga os LEDs com um buffer
                }
                else
                {
                    put_pixel(0); // Desliga o LEDs em false (0)
                }
            }
        }
    }
}

#endif