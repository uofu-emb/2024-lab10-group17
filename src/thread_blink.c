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

#define BLINK_TASK_PRIORITY     ( tskIDLE_PRIORITY + 1UL )
#define BLINK_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

void blink_task(__unused void *params) {  
    while (true) {
        gpio_put(GPIO_PIN, on);
        if (count++ % 11 == 0) on = !on;
        vTaskDelay(500);
    }
}


int main( void )
{
    stdio_init_all();
    gpio_init(GPIO_PIN);
    gpio_set_dir(GPIO_PIN, GPIO_OUT);

    TaskHandle_t task;
    xTaskCreate(blink_task, "BlinkThread",
                BLINK_TASK_STACK_SIZE, NULL, BLINK_TASK_PRIORITY, &task);
    vTaskStartScheduler();
    return 0;
}
