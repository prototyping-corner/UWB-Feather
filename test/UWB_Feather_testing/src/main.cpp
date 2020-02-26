/**
 * Testing some features of the UWB Feather
 * @todo make it not painful to look at
 */

#include <Arduino.h>
#include "Configuration.h"

void pulse(int pin, int interval) {
  digitalWrite(pin, HIGH);
  delay(interval);
  digitalWrite(pin, LOW);
  delay(interval);
}

float calculateBattVoltage(int pin) {
  float measuredvbat = analogRead(pin);
  measuredvbat *= 2;    // we divided by 2, so multiply back
  measuredvbat *= 3.3;  // Multiply by 3.3V, our reference voltage
  measuredvbat /= 1024; // convert to voltage
  return measuredvbat;
}

void setup() {
  Serial.begin(9600);
  while(!Serial);

  Serial.println("Starting...");
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  //pinMode(BATTERY_VOLT, INPUT);
  pinMode(BATTERY_CHARGE, INPUT);

  Serial.println("Testing RGB LED...");
  Serial.println("RED");
  pulse(LED_RED, 1000);

  Serial.println("GREEN");
  pulse(LED_GREEN, 1000);

  Serial.println("BLUE");
  pulse(LED_BLUE, 1000);

  Serial.println("Testing battery...");
  Serial.println("Running battery test for 20 seconds");
  long millisNow = millis();
  while(millis() < millisNow + 20000) {
    Serial.print("VBat: "); Serial.println(calculateBattVoltage(BATTERY_VOLT));
    Serial.print("Charge: "); Serial.println(!digitalRead(BATTERY_CHARGE));
    
    delay(500);
  }

  Serial.println("Need to test DWM1000 module");
  Serial.println("Testing complete");
  
}

void loop() {
  // put your main code here, to run repeatedly:
}