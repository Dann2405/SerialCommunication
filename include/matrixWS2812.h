#ifndef MATRIXWS2812
#define MATRIXWS2812

// Definições iniciais
#define WS2812_PIN 7
#define IS_RGBW false
#define columns 5
#define rows 5

uint8_t led_r = 0; // Intensidade do LED Vermelho
uint8_t led_g = 0; // Intensidade do LED Verde
uint8_t led_b = 0; // Intensidade do LED Azul

// BUFFER DE NUMEROS DE 0 A 9
bool number0[columns][rows] =
{
    0, 1, 1, 1, 0,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    0, 1, 1, 1, 0
}; // Vai exibir o numero zero

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

void set_number0(uint8_t r, uint8_t g, uint8_t b)
{
    uint32_t color = urgb_u32(r, g, b); // Define a cor com base nos parâmetros das linhas 10 a 12

    for (int i = columns - 1; i >= 0; i--)
    {
        if((columns - i) % 2 == 0)
        {
            for (int j = 0; j < rows; j++)
            {
                if(number0[i][j])
                {
                    put_pixel(color);
                }
                else
                {
                    put_pixel(0);
                }
            }
        }
        else
        {
            for (int j = rows - 1; j >=0; j--)
            {
                if(number0[i][j])
                {
                    put_pixel(color);
                }
                else
                {
                    put_pixel(0);
                }
            }
        }
    }

}

#endif