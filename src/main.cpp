#include <Arduino.h>

#define N_PINS 5                                       // Number of Pins
#define BAUDRATE 9600                                  // Serial Communication Baudrate

#define T_ON    100                                    // Time LED is ON 
#define T_OFF   400                                    // Time LED is OFF
#define T_WAIT  3000                                   // Time to Wait

// Global Variables
uint8_t pinLed[] = {13, 12, 8, 7, 4};                  // Pins for LEDs

void setup() {
  Serial.begin(BAUDRATE);                              // Start Serial Communication

  // Set Pins as Output
  for (uint8_t i = 0; i < N_PINS; i++) {                // Loop for all LEDs
     pinMode( pinLed[i], OUTPUT);                       // Set Pin as Output
  }
}

void loop() {
  for (uint8_t i = 0; i < N_PINS; i++) {                // Loop for all LEDs
    digitalWrite(pinLed[i], HIGH);                      // Turn ON LED
    delay(T_ON);                                        // Time LED is ON
    digitalWrite(pinLed[i], LOW);                       // Turn OFF LED
    delay(T_OFF);                                       // Time LED is OFF
  }
  delay(T_WAIT);                                        // Time to Wait
}