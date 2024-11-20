/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"

int count = 0;
bool on = false;
const uint GPIO_PIN = 0; // Use GPIO 0

int main( void )
{
    stdio_init_all();
    gpio_init(GPIO_PIN);
    gpio_set_dir(GPIO_PIN, GPIO_OUT);
    
    while (true) {
        gpio_put(GPIO_PIN, on);
        if (count++ % 11 == 0) on = !on;
        sleep_ms(500);
    }

    return 0;
}
