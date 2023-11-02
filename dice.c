// PROGRAM TO BLINK ONBOARD LED OF PI PICO

//include header files
#include "pico/stdlib.h"
//This automatically includes both hardware/gpio and pico/time libraries

int main(){
    const uint GPIO_LED = 2;
    //on board led

    //initialise the gpio pin no 25
    gpio_init(GPIO_LED);

    //set the direction as output mode
    gpio_set_dir(GPIO_LED,GPIO_OUT);
    //GPIO_OUT is the macro defination for setting the direction as output

    while(1){
        //make the gpio pin 25 as high
        gpio_put(GPIO_LED,1);

        //provide some delay
        sleep_ms(500);

        //make the pin 25 low
        gpio_put(GPIO_LED,0);

        //provide some delay
        sleep_ms(500);
    }

    return 0;
}