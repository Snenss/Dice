// PROGRAM TO BLINK ONBOARD LED OF PI PICO

//include header files
#include "pico/stdlib.h"
#include <stdio.h>

//This automatically includes both hardware/gpio and pico/time libraries

int main(){
    const uint GPIO_BUTTON = 1;
    const uint GPIO_LED1 = 2;
    const uint GPIO_LED2 = 3;
    const uint GPIO_LED3 = 4;
    const uint GPIO_LED4 = 5;
    const uint GPIO_LED5 = 6;
    const uint GPIO_LED6 = 7;
    const uint GPIO_LED7 = 8;
    bool action = false;
    const uint LEDS[7] = {GPIO_LED1, GPIO_LED2, GPIO_LED3, GPIO_LED4, GPIO_LED5, GPIO_LED6, GPIO_LED7};

    

    //initialise the gpio pins
    
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

    //Simple Start Animation
    for (int i = 0 ; i < 7 ; i++){
        gpio_put(LEDS[i], 1);
        sleep_ms(200);
    }
    for (int i = 0 ; i < 7 ; i++){
        gpio_put(LEDS[i], 0);
        sleep_ms(200);
    }
    

    // Main Rotation
    // Set davice in Dice rolling mode
   while(true){
    if (!gpio_get(GPIO_BUTTON)){
        action = true;
    }


    while(action){
        // Produce random numer between 1 and 6
        int rNumber = 1;
        uint32_t dice1;
        dice1 = rand() % 6 + 1;
        rNumber = rNumber + 1;
        
    

        //roll 
        switch (dice1) {
            case 1:
                gpio_put(GPIO_LED7, 1);
                break;
            case 2:
                gpio_put(GPIO_LED1, 1);
                gpio_put(GPIO_LED6, 1);
                break;
            case 3:
                gpio_put(GPIO_LED1, 1);
                gpio_put(GPIO_LED7, 1);
                gpio_put(GPIO_LED6, 1);
                break;
            case 4:
                gpio_put(GPIO_LED1, 1);
                gpio_put(GPIO_LED2, 1);
                gpio_put(GPIO_LED5, 1);
                gpio_put(GPIO_LED6, 1);
                break;
            case 5:
                gpio_put(GPIO_LED1, 1);
                gpio_put(GPIO_LED2, 1);
                gpio_put(GPIO_LED5, 1);
                gpio_put(GPIO_LED6, 1);
                gpio_put(GPIO_LED7, 1);
                break;
            case 6:
                gpio_put(GPIO_LED1, 1);
                gpio_put(GPIO_LED2, 1);
                gpio_put(GPIO_LED3, 1);
                gpio_put(GPIO_LED4, 1);
                gpio_put(GPIO_LED5, 1);
                gpio_put(GPIO_LED6, 1);
                break;
        }
        sleep_ms(1000);
        gpio_put(GPIO_LED1,0);
        gpio_put(GPIO_LED2,0);
        gpio_put(GPIO_LED3,0);
        gpio_put(GPIO_LED4,0);
        gpio_put(GPIO_LED5,0);
        gpio_put(GPIO_LED6,0);
        gpio_put(GPIO_LED7,0);
        sleep_ms(500);
        action = false;


    }
   }

    return 0;
}