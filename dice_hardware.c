
#include "dice_hardware.h"
#include "pico/stdlib.h"

const unsigned int GPIO_BUTTON = 1;
const unsigned int GPIO_LED1 = 2;
const unsigned int GPIO_LED2 = 3;
const unsigned int GPIO_LED3 = 4;
const unsigned int GPIO_LED4 = 5;
const unsigned int GPIO_LED5 = 6;
const unsigned int GPIO_LED6 = 7;
const unsigned int GPIO_LED7 = 8;

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