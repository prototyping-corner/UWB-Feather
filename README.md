# UWB Feather
### *Version 1.1*
![License](https://i.creativecommons.org/l/by-nc/4.0/88x31.png)

![Boards](/docs/images/uwb_feather_v1_018.jpg)

The Ultra-WideBand Feather incorporates the Decawave DWM1000 module and an ATSAMD21 ARM Cortex M0 into the Adafruit feather form-factor. The DWM1000 module is an IEEE802.15.4-2011 UWB compliant wireless module capable of precision indoor positioning and high data rates, making this board perfect for robotics projects where localization is required.  

Version 1.1 changes to be complete:
 - Change the USB-C connector BoM item and PCB footprint
 - Add Micro USB footprint in addition to USB-C (makers choice)
 - Replace individual charge and D13 LED’s with RGB led to integrate
 - Change SWD 5×2 header BoM item
 - Add pull-up resistor on DWM1000 IRQ line
 - Reroute with 8/8 mil minimum traces
 - Tidy up silkscreen layer
 - Enlarge test pads and expose SWD on bottom layer for pogo-pin programming
 - Re-position crystal and bypass capacitors to be closer to target components
 - Pullback copper fill and wires from the antenna facing side of DWM1000 module
 - Change J4 (SWD header) BoM item

For full project details and documentation visit [prototypingcorner.io/projects/uwb-feather](prototypingcorner.io/projects/uwb-feather).

## Firmware
Firmware providing in this repository is for testing the DWM1000 module and utilizes the [thotro/arduino-dw1000](https://github.com/thotro/arduino-dw1000) library. As this repository is no longer actively maintained, future development will focus on a new library.
