#include <Arduino.h>
 
#define BAUDRATE 9600
#define N_Times 10
#define delayTimeOn 100
#define delayTimeOff 1000
#define delayTime 5000

// Pinnummern der LEDs
uint8_t pinLed[] = {13, 12, 8, 7, 4};
uint8_t nPins = sizeof(pinLed)/sizeof(pinLed[0]);
 
void setup() {
  Serial.begin(BAUDRATE);
 
// Pins als Output definiert
  for (uint8_t i = 0; i < nPins; i++) {
     pinMode(pinLed[i], OUTPUT);
  }
}
 
void loop() {
// Zufällige LED an- und ausschalten
  for (uint8_t i = 0; i < N_Times; i++) {
    uint8_t randomPin = random(nPins); //nPins hier korrekt da Index bei 0 beginnt
    digitalWrite(pinLed[randomPin], HIGH);
    delay(delayTimeOn);
    digitalWrite(pinLed[randomPin], LOW);
    delay(delayTimeOff);
  }
  delay(delayTime);
}