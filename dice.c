/**
 * @file dice.c
 *
 * Implementiert ein Würfel Programm zur Ansteuerung von 7 LEDs
 * Features: abschaltbarer Ruhemmodus, Modularität, Animationen
 *
 * @author Jan Ritter
 */

//include header files
#include <stdio.h>
#include "pico/stdlib.h"
#include "dice_hardware.h"
#include "dice_animation.h"
#include "hardware/uart.h"



int main(){

    int error = 0;
    error = dice_hardware_init();

    //Start Animation
    animations_start(ANIMATION_VERY_FAST);
    

    // Hier laeueft das Programm in Dauerschleife
   while(!error){
    

    while(getButton()){

        // Produziere Pseudozufallszahl
        //int rNumber = 1;
        uint32_t dice1;
        dice1 = rand() % 6 + 1;
        //rNumber = rNumber + 1;
        
        // bei ungeraden Zahlen muss immer led7 an, bei gerade nie
        // Dieses If auskommentiert führt zu 6LEDs in einer Reihe
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
        animations_put_off(ANIMATION_VERY_FAST);
        Button = false;
        //Timer nachdem der Dormant Mode automatisch startet
        timer_start(5000);//in ms
    }
   }

    return error;
}