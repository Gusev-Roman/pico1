#include <Arduino.h>
#include <stdio.h>
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/timer.h"
#include "pico/time.h"
#include "hardware/adc.h"
#include "hardware/dma.h"
//#include "MBED_RPi_Pico_ISR_Timer.h"

struct repeating_timer timer;
// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  _gpio_init(PIN_LED);
  adc_init();
  adc_gpio_init(PIN_A0);  
  //pinMode(LED_BUILTIN, OUTPUT);
  gpio_set_outover(PIN_LED, GPIO_OVERRIDE_NORMAL);
  //alarm_pool_add_repeating_timer_us(pool, 31, coda, NULL, &timer );
  //alarm_pool_add_repeating_timer_ms
  SerialUSB.begin(115200);
  SerialUSB.println("Hello PICO!");
}

// the loop routine runs over and over again forever:
void loop() {
  //digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  gpio_put(PIN_LED, HIGH);
  //delay(1000);               // wait for a second
  sleep_ms(500);
  adc_read();
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);               // wait for a second
  //busy_wait_us(300000);
  sleep_ms(300);
  SerialUSB.println("Hello PICO!");
}
