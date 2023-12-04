// PROGRAM TO BLINK ONBOARD LED OF PI PICO

//include header files
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/sleep.h"
#include "dice_hardware.h"

int main(){
   
    dice_hardware_init();
    bool action = false;
    const uint LEDS[7] = {GPIO_LED1, GPIO_LED6, GPIO_LED2, GPIO_LED5, GPIO_LED3, GPIO_LED4, GPIO_LED7};
    int waitcount = 0;

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
    // Set device in Dice rolling mode
   while(true){
    waitcount++;
    if (!gpio_get(GPIO_BUTTON)){
        action = true;
        waitcount = 0;
    }
    // Activate Dorm mode after some tries 
    if (waitcount > 20000000){
        gpio_put(GPIO_LED7, 1);
        sleep_ms(2000);
        gpio_put(GPIO_LED7, 0);
        sleep_run_from_xosc();
        sleep_goto_dormant_until_pin(GPIO_BUTTON, true, false);
    }


    while(action){
        // Produce random numer between 1 and 6
        int rNumber = 1;
        uint32_t dice1;
        dice1 = rand() % 6 + 1;
        rNumber = rNumber + 1;
        
        // bei ungeraden Zahlen muss immer led7 an, bei gerade nie
       if (dice1 % 2 != 0){
        dice1--;
        gpio_put(GPIO_LED7,1);
       }
       //LEDs von 0 bis dice anschalten
       for (int i = 0 ; i < dice1 ; i++){
        gpio_put(LEDS[i],1);
       }
       //Kurz warten
        sleep_ms(1000);
        //Alle LEDs aus
        for (int i = 0 ; i < 7 ; i++){
        gpio_put(LEDS[i],0);
        sleep_ms(100);
        }
        
        action = false;
    }
   }

    return 0;
}