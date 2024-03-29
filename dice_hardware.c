/**
 * @file dice_hardware.c
 *
 * Dient der Ansteuerung der Pico Würfel Hardware
 *
 * @author Jan Ritter
 */
#include "dice_hardware.h"
#include "pico/stdlib.h"
#include "pico/time.h"
#include "hardware/timer.h"
#include "pico/sleep.h"
#include "dice_animation.h"

typedef enum {
    PRESS_ONE_SECOND = 1 * 1000000,
    PRESS_TWO_SECONDS = 2 * 1000000,
    PRESS_THREE_SECONDS = 3 * 1000000
} LongPressDuration;

typedef enum {
    DEBOUNCE_LONG = 10000,
    DEBOUNCE_MIDDLE = 5000,
    DEBOUNCE_SHORT = 2500
} debounce;

// GPIO Konstanten
const unsigned int GPIO_BUTTON = 9;
const unsigned int GPIO_LED1 = 2;
const unsigned int GPIO_LED2 = 3;
const unsigned int GPIO_LED3 = 4;
const unsigned int GPIO_LED4 = 5;
const unsigned int GPIO_LED5 = 6;
const unsigned int GPIO_LED6 = 7;
const unsigned int GPIO_LED7 = 8;
unsigned int LEDS[7] = {GPIO_LED1, GPIO_LED6, GPIO_LED2, GPIO_LED5, GPIO_LED3, GPIO_LED4, GPIO_LED7};

//globale timer variablen
struct repeating_timer timer;
uint32_t time_ms;
//globale Button Variable
bool Button = false;
//globale Dormant Variable
bool dormantActive = true;


void button_callback(uint gpio, uint32_t events){
    static absolute_time_t button_press_time;
    button_press_time = get_absolute_time();

    while(!gpio_get(gpio)){
        busy_wait_ms(1);//Auf loslassen warten (System frozen)
    }
    static absolute_time_t button_release_time;
    button_release_time = get_absolute_time();

    uint32_t press_duration = absolute_time_diff_us(button_press_time, button_release_time);
    if(press_duration > PRESS_TWO_SECONDS){
        //bei langem Tastendruck dormant Umschalten
        dormantActive = !dormantActive;
        // bei Aktivierung
        if (dormantActive){
            animations_blink(ANIMATION_FAST, 3);
        // bei Deaktivierung
        }else{
            animations_blink(ANIMATION_FAST, 6);
        }

    }else if (press_duration > DEBOUNCE_MIDDLE){//entprellen
        Button = true;
    }
    timer_stop();
}

volatile bool getButton(){
    return Button;
}

int dice_hardware_init(){
    // Set Button variable false
    Button = false;
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
    /*Legt den GPIO fest, der einen Interrupt ausloesen soll. Der aktuelle Prozessor wird interrupted
    param2 legt die Ausloesebedingung fest
    1 aktiviert den hier gerade konfigurierten Interrupt
    */
    gpio_set_irq_enabled(GPIO_BUTTON,  GPIO_IRQ_EDGE_RISE, 1);//Idee normal=up, Fall = An, Rise = Aus  
    //Callback Funktion festlegen fuer ↑
    gpio_set_irq_callback(button_callback);
    //eine der IRQ baenke wird aktiviert //////////////hier ruhemodus
    if (1) irq_set_enabled(IO_IRQ_BANK0, true);

    return 0;
}
/**
 * Wird nach dem Ablaufen des Timers aufgerufen.
 * Signalisiert Eintritt in den dormant modes durch blinkende LED
 * 
 * @param : timer Globale timer variable
*/
bool timer_callback(struct repeating_timer *timer) {
    
    //Animation
    animations_blink(ANIMATION_VERY_SLOW, 2);
    timer_stop();
    //wechsel auf Basic clock Generator
    sleep_run_from_xosc();
    //Aufruf der sleep Funktion
    sleep_goto_dormant_until_pin(GPIO_BUTTON, true, false);
    return true;
}

/**
 * Startet den Timer, der festlegt, wann in den Dormant Mode gewechselt wird.
 * 
 * @param minutes: Zeit in Minuten, bis Timer ausloest
*/
void timer_start(uint32_t minutes) {
    //time_ms = minutes * 60 * 1000;
    time_ms = minutes;
    if (dormantActive){
    add_repeating_timer_ms(time_ms, timer_callback, NULL, &timer);
    }
}

/**
 * Stoppt den aktiven repeating Timer
*/
void timer_stop() {
    cancel_repeating_timer(&timer);
}

    

