// Board config file for PicoGUS 2.0, also compatible with the Pi Pico 
#ifndef _BOARDS_PICOW_FAST_H
#define _BOARDS_PICOW_FAST_H

// Allow extra time for xosc to start.
#define PICO_XOSC_STARTUP_DELAY_MULTIPLIER 64

// Slower flash to assist restarts when flashing on the fly
#define PICO_FLASH_SPI_CLKDIV 6

#include "boards/pico_w.h"
#endif