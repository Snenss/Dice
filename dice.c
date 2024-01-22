/**
 * @file dice.c
 *
 * Implementiert ein Würfel Programm zur Ansteuerung von 7 LEDs
 * Features: abschaltbarer Ruhemmodus, Modularität, Animationen
 * Version fuer 6LEDs in einer Reihe
 *
 * @author Jan Ritter
 */

//include header files
#include <stdio.h>
#include "pico/stdlib.h"
#include "dice_hardware.h"
#include "dice_animation.h"



int main(){

    int error = 0;
    error = dice_hardware_init();

    //Start Animation
    animations_start(ANIMATION_VERY_FAST);
    //Timer für Dormant mode Aktivierung
    timer_start(10000);
    

    // Hier laeueft das Programm in Dauerschleife
   while(!error){
    

    while(getButton()){

        //Alle LEDs aus
        animations_put_off(ANIMATION_VERY_FAST);

        // Produziere Pseudozufallszahl
        uint32_t dice1;
        dice1 = rand() % 6 + 1;
        
       //LEDs von 0 bis dice anschalten
       for (int i = 0 ; i < dice1 ; i++){
        gpio_put(LEDS[i],1);
       }
        Button = false;
        //Timer nachdem der Dormant Mode automatisch startet
        timer_start(5000);//in ms
    }
   }

    return error;
}