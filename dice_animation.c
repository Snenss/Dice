/**
 * @file dice_animation.h
 *
 * Beschreibt Anmationen und deren Hilfsfunktionen
 *
 * @author Jan Ritter
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "dice_hardware.h"



void animations_blink(int speed, int blinkCount){
    for(int j = 0 ; j < blinkCount ; j++){

    for (int i = 0 ; i < 7 ; i++){
            gpio_put(LEDS[i], 1);
            }
            busy_wait_ms(speed);

            for (int i = 0 ; i < 7 ; i++){
                gpio_put(LEDS[i], 0);   
            }
        busy_wait_ms(speed);
    }

}

void animations_start(int speed){

    for (int i = 0 ; i < 7 ; i++){
        gpio_put(LEDS[i], 1);
        sleep_ms(speed);
    }
    for (int i = 0 ; i < 7 ; i++){
        gpio_put(LEDS[i], 0);
        sleep_ms(speed);     
    }
}


void animations_put_off(int speed){

    for (int i = 0 ; i < 7 ; i++){
        gpio_put(LEDS[i],0);
        sleep_ms(speed);
    }   
}


