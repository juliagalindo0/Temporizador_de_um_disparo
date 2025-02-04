#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUTTON 5
#define INTERVAL_MS 3000

volatile int state = 0;
volatile bool is_running = false;

// Callback para desligar LEDs em sequência
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    if (state == 0) {
        gpio_put(LED_RED, 0);
    } else if (state == 1) {
        gpio_put(LED_BLUE, 0);
    } else if (state == 2) {
        gpio_put(LED_GREEN, 0);
        is_running = false; // Permite novo acionamento
        return 0;
    }
    state++;
    add_alarm_in_ms(INTERVAL_MS, turn_off_callback, NULL, false);
    return 0;
}

// Callback do botão
void button_callback(uint gpio, uint32_t events) {
    if (!is_running) {
        sleep_ms(50); // Debounce simples
        if (gpio_get(BUTTON) == 0) {
            is_running = true;
            state = 0;
            gpio_put(LED_RED, 1);
            gpio_put(LED_BLUE, 1);
            gpio_put(LED_GREEN, 1);
            add_alarm_in_ms(INTERVAL_MS, turn_off_callback, NULL, false);
        }
    }
}

int main() {
    stdio_init_all();
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);
    gpio_init(LED_RED);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_RED, 0);
    
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &button_callback);
    
    while (1) {
        sleep_ms(100); // Loop principal
    }
}
