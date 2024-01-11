/**
 * @file dice.c
 *
 * Implementiert ein Würfel Programm zur Ansteuerung von 7 LEDs
 * Features: Ruhemmodus, Modularität, Animationen
 *
 * @author Jan Ritter
 */

//include header files
#include <stdio.h>
#include "pico/stdlib.h"
#include "dice_hardware.h"

int main(){
   
    dice_hardware_init();
    bool action = false;
    const uint LEDS[7] = {GPIO_LED1, GPIO_LED6, GPIO_LED2, GPIO_LED5, GPIO_LED3, GPIO_LED4, GPIO_LED7};

    //Simple Start Animation
    for (int i = 0 ; i < 7 ; i++){
        gpio_put(LEDS[i], 1);
        sleep_ms(200);
    }
    for (int i = 0 ; i < 7 ; i++){
        gpio_put(LEDS[i], 0);
        sleep_ms(200);
        //timer_start(1);//gehe sofort in die callback Funktion -> Ruhezustand
    }
    

    // Hier laeueft das Programm in Dauerschleife
   while(true){
    

    while(getButton()){
        // Produziere Pseudozufallszahl
        int rNumber = 1;
        uint32_t dice1;
        dice1 = rand() % 6 + 1;
        rNumber = rNumber + 1;
        
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
        for (int i = 0 ; i < 7 ; i++){
        gpio_put(LEDS[i],0);
        sleep_ms(100);
        }
        
        Button = false;
        //Timer nachdem der Dormant Mode automatisch startet
        timer_start(5000);//in ms
    }
   }

    return 0;
}