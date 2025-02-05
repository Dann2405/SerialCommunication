#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"
#include "hardware/pio.h"


int main()
{
    stdio_init_all();

    while (true) {
        sleep_ms(500);
        printf("Hello, world!\n");
    }
}
