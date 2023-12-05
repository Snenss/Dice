/**
 * @file dice_hardware.c
 *
 * Dient der ansteuerung der Pico Würfel Hardware
 *
 * @author Jan Ritter / Chat Gpt
 */
#include "dice_hardware.h"
#include "pico/stdlib.h"
#include "pico/time.h"
#include "hardware/timer.h"
#include "pico/sleep.h"

// GPIO Konstanten
const unsigned int GPIO_BUTTON = 1;
const unsigned int GPIO_LED1 = 2;
const unsigned int GPIO_LED2 = 3;
const unsigned int GPIO_LED3 = 4;
const unsigned int GPIO_LED4 = 5;
const unsigned int GPIO_LED5 = 6;
const unsigned int GPIO_LED6 = 7;
const unsigned int GPIO_LED7 = 8;

//globale timer variablen
struct repeating_timer timer;
uint32_t time_ms;



void dice_hardware_init(){
    // Init GPIO s
    gpio_init(GPIO_BUTTON);
    gpio_init(GPIO_LED1);
    gpio_init(GPIO_LED2);
    gpio_init(GPIO_LED3);
    gpio_init(GPIO_LED4);
    gpio_init(GPIO_LED5);
    gpio_init(GPIO_LED6);
    gpio_init(GPIO_LED7);

    //set the direction modes
    gpio_set_dir(GPIO_BUTTON, GPIO_IN);
    gpio_set_dir(GPIO_LED1, GPIO_OUT);
    gpio_set_dir(GPIO_LED2, GPIO_OUT);
    gpio_set_dir(GPIO_LED3, GPIO_OUT);
    gpio_set_dir(GPIO_LED4, GPIO_OUT);
    gpio_set_dir(GPIO_LED5, GPIO_OUT);
    gpio_set_dir(GPIO_LED6, GPIO_OUT);
    gpio_set_dir(GPIO_LED7, GPIO_OUT);

    gpio_pull_up(GPIO_BUTTON);

}
/**
 * Wird nach ablaufen des Timers aufgerufen.
 * Signalisiert Eintritt in den dormant modes durch blinkende LED
 * stoppt den timer
 * geht in den Dormant mode
*/
bool timer_callback(struct repeating_timer *t) {
    gpio_put(GPIO_LED7, 1);
    busy_wait_ms(200);
    gpio_put(GPIO_LED7, 0);
    busy_wait_ms(200);
    gpio_put(GPIO_LED7, 1);
    busy_wait_ms(200);
    gpio_put(GPIO_LED7, 0);
    timer_stop();
    sleep_run_from_xosc();
    sleep_goto_dormant_until_pin(GPIO_BUTTON, true, false);
    return true;
}


void timer_start(uint32_t minutes) {
    //time_ms = minutes * 60 * 1000;
    time_ms = minutes;
    add_repeating_timer_ms(time_ms, timer_callback, NULL, &timer);
}

void timer_stop() {
    cancel_repeating_timer(&timer);
}

    

