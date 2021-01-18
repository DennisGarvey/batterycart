boolean debug = false; //enable serial debug print statements to serial
/*
   Dennis Garvey
*/

#include <Adafruit_INA219.h>//INA219 current sensors
#include <Wire.h> //i2c
#include <FastLED.h> //leds
#include "Battery.h"

/*
   Led stuff
*/
#define DATA_PIN 3
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 150
byte brightness = 255;

int blueThreshold = 100; //if the current(mA) is under this value the leds will turn blue

CRGB leds[NUM_LEDS];
/*
  TCA9548A
*/
#define TCAADDR 0x70 //tca i2c address 
/*
   INA219
*/
Adafruit_INA219 sense1(0x40); //add i2c address(hexidecimal) as a parameter
Adafruit_INA219 sense2(0x41);
Adafruit_INA219 sense3(0x42);
Adafruit_INA219 sense4(0x43);

float currentMultiplier = 3;
/*
   Battery Objects
*/
#define numberOfBatteries 12
//Battery(int ledStart, int ledEnd, int id)
Battery battery[] = {
  Battery(0, 10, 0),
  Battery(10, 20, 1),
  Battery(20, 30, 2),
  Battery(30, 40, 3),
  Battery(40, 50, 4),
  Battery(50, 60, 5),
  Battery(60, 70, 6),
  Battery(70, 80, 7),
  Battery(80, 90, 8),
  Battery(90, 100, 9),
  Battery(100, 110, 10),
  Battery(110, 120, 11),
};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Serial Started");
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  initializeINA219();
  tcaSelect(0);
}
//void loop(){}
void loop() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  if (debug) Serial.println("MILLIS:" + String(millis()));
  if (debug) batteryStats();
  updateCurrent();
  updateVoltage();
  updateHue();
  updateLeds();
}
