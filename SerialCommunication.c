#include "include/bibliotecas.h"

int main()
{
    stdio_init_all();
    ws2812_init();

    set_number0(200, 0, 0);

    while (true) {
        sleep_ms(500);
        printf("Hello, world!\n");
    }
}