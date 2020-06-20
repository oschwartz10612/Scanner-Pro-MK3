
# Scanner Pro MK3
A simple Arduino based USB device that interfaces with common USB barcode scanners or other text based HID devices (like keyboards) and provides scripting and payload based delivery opportunities through HID (keyboard input) text to the host.

![](/docs/board_v1.jpg)

## Scanner Pro Manager
A desktop application to install precompiled firmware for Scanner Pro boards as well as interacting over UART. Download from [releases](https://github.com/oschwartz10612/Scanner-Pro-MK3/releases). 

Firmware files are distributed in .hex precompiled binaries. See [the wiki](https://github.com/oschwartz10612/Scanner-Pro-MK3/wiki/FCPS-Precompiled-Firmware-2.0) to browse and install precompiled firmware. Current precompiled firmware includes:
 1. [FCPS Firmware 2.0](https://github.com/oschwartz10612/Scanner-Pro-MK3/wiki/FCPS-Precompiled-Firmware-2.0)

If you have written firmware and would like to share. Open a pull request and include your source code and compiled hex in the firmware directory.

## Developing Firmware
Custom sketches can be written for the board in using the Arduino Board framework. Reference [the wiki](https://github.com/oschwartz10612/Scanner-Pro-MK3/wiki/Developing-Custom-Scripts-and-Firmware) for more information.

## PCB and Parts
PCB files and a BOM are included in the repo. If you would like one you can reach out.