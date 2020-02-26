/**
 * UWB Feather Ranging Demo
 * Configures device as. Derived from DW1000Ranging_ANCHOR & DW1000Ranging_TAG
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
#define LED         31

// Choose one
#define OP_TAG
//#define OP_ANCHOR

#ifdef OP_TAG
#include "tag.h"
#endif
#ifdef OP_ANCHOR
#include "anchor.h"
#endif