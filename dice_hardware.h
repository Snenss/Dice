/**
 * @file dice_hardware.h
 *
 * Dient der ansteuerung der Pico Würfel Hardware
 *
 * @author Jan Ritter / Chat Gpt
 */

#include "pico/time.h"
#include "hardware/timer.h"



// Konstanten für Harware Pins
extern const unsigned int GPIO_BUTTON;
extern const unsigned int GPIO_LED1;
extern const unsigned int GPIO_LED2;
extern const unsigned int GPIO_LED3;
extern const unsigned int GPIO_LED4;
extern const unsigned int GPIO_LED5;
extern const unsigned int GPIO_LED6;
extern const unsigned int GPIO_LED7;

// Globale Variable für den Button status
extern bool Button;


bool getButton();
 
/**
 * Intialisiert den Eingang und alle Ausgaenge.
 * Initialisiert den Callback für den Eingang
 * 
*/
void dice_hardware_init();

/**
 * Startet den Timer, der festlegt, wann in den Dormant Mode gewechselt wird.
 * 
 * @param minutes: Zeit in Minuten,bis timer ausloest
*/
void timer_start(uint32_t minutes);

/**
 * hält den Timer an
 * 
*/
void timer_stop();

