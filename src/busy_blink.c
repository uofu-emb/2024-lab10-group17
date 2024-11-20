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

#pragma GCC optimize ("O0")

int count = 0;
bool on = false;
const uint GPIO_PIN = 0; // Use GPIO 0

int main( void )
{
    stdio_init_all();
    while(1) {
        uint32_t k;
        for (int i = 0; i < 30;) {
            uint32_t j = 0;
            j = ((~j >> i) + 1) * 27644437;
            k = j;
        }
    }
    return 0;
}
