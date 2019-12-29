/**
 * UWB Feather Anchor Demo
 * Configures device as. Derived from DW1000Ranging_ANCHOR
 * example in thoro/arduino-dw1000
 * 
 * Visit prototypingcorner.io/projects/uwb-feather for more information
 */

#include <Arduino.h>
#include <SPI.h>
#include "DW1000Ranging.h"

#define DW1000_RST  2
#define DW1000_IRQ  3
#define DW1000_CS   4
#define LED         13

void newRange() {
  // Quick flash of LED for visual confirmation
  digitalWrite(LED, HIGH);
  delay(20);
  digitalWrite(LED, LOW);

  Serial.print("from: "); Serial.print(DW1000Ranging.getDistantDevice()->getShortAddress(), HEX);
  Serial.print("\t Range: "); Serial.print(DW1000Ranging.getDistantDevice()->getRange()); Serial.print(" m");
  Serial.print("\t RX power: "); Serial.print(DW1000Ranging.getDistantDevice()->getRXPower()); Serial.println(" dBm");
}

void newBlink(DW1000Device* device) {
  Serial.print("blink; 1 device added ! -> ");
  Serial.print(" short:");
  Serial.println(device->getShortAddress(), HEX);
}

void inactiveDevice(DW1000Device* device) {
  Serial.print("delete inactive device: ");
  Serial.println(device->getShortAddress(), HEX);
}

void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);

  //init the configuration
  DW1000Ranging.initCommunication(DW1000_RST, DW1000_CS, DW1000_IRQ);

  // Attach events
  DW1000Ranging.attachNewRange(newRange);
  DW1000Ranging.attachBlinkDevice(newBlink);
  DW1000Ranging.attachInactiveDevice(inactiveDevice);

  //Enable the filter to smooth the distance
  //DW1000Ranging.useRangeFilter(true);
  
  // Start module as Anchor
  DW1000Ranging.startAsAnchor("82:17:5B:D5:A9:9A:E2:9C", DW1000.MODE_LONGDATA_RANGE_ACCURACY);
}

void loop() {
  DW1000Ranging.loop();
}