/**
 * @file dice_animation.h
 *
 * gibt Animationen an 7 LED Würfel frei
 *
 * @author Jan Ritter
 */

// Enum für Animationsgeschwindigkeiten
typedef enum {
    ANIMATION_VERY_FAST = 100,
    ANIMATION_FAST = 500,
    ANIMATION_MIDDLE = 1000,
    ANIMATION_SLOW = 1500,
    ANIMATION_VERY_SLOW = 2000
} AnimationSpeed;



/**
 * Beinhaltet Animation zum blinke lassen aller LEDs
 * 
 * @param speed: Animationsgeschwindigkeit
 * @param blinkCount: Wiederholungen
*/
void animations_blink(int speed, int blinkCount);

/**
 * Beinhaltet Animation zu ausschalten
 * 
 * @param LEDS: Array der auszuschaltenen LEDs
*/
void animations_put_off(int speed);

/**
 * Beinhaltet eine Startanimnation
 * 
 * @param speed: Animationsgeschwindigkeit
*/
void animations_start(int speed);
