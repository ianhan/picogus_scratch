#include <stdio.h>
#include <pico/stdlib.h>
#include "ws2812.pio.h"
#include "isa_io.pio.h" // UART_TX_PIN

#define WS2812_SM 2

uint8_t palette[256][3];
uint8_t palette_index;
uint8_t palette_position;

void pal_dac_write(uint8_t index)
{
    palette_index = index;
    palette_position = 0;
}

void pal_dac_data(uint8_t data)
{
    palette[palette_index][palette_position] = data;
    switch(palette_position)
    {
        case 0:
        case 1:
            palette_position++;
            break;
        case 2:
            palette_position = 0;
            palette_index++;
            break;
    }
}

void clear_leds()
{
    for (int y = 0; y < 256; y++)
    {
        pio_sm_put_blocking(pio0, WS2812_SM, 0);
    }
}

void update_leds()
{
    for (int y = 0; y < 16; y++)
    {
        for (int x = 0; x < 16; x++)
        {
            // every other row of this panel is wired in the other direction
            uint8_t index = (16 * y) + ((y & 1) ? x : 15 - x);

            // todo: gamma table
            uint8_t rval = palette[index][0] >> 2;
            uint8_t gval = palette[index][1] >> 2;
            uint8_t bval = palette[index][2] >> 2;

            // GRB? okay.
            pio_sm_put_blocking(pio0, WS2812_SM, gval << 24 | rval << 16 | bval << 8);
        }
    }
    busy_wait_ms(5);
}

void play_pal() {
    puts("starting core 1 PAL");

    uint offset = pio_add_program(pio0, &ws2812_program);
    pio_sm_claim(pio0, WS2812_SM);
    ws2812_program_init(pio0,
                        WS2812_SM,
                        offset,
                        UART_TX_PIN,
                        800000,
                        0);

    clear_leds();

    while(1)
    {
        update_leds();
    }
}
