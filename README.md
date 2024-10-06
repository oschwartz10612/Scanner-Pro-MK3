
# Scanner Pro MK3
A simple Arduino based USB device that interfaces with common USB barcode scanners or other text based HID devices (like keyboards) and provides scripting and payload based delivery opportunities through HID (keyboard input) text to the host.

![](/docs/board_v2.png)
![](/docs/board_v2_keyboard.png)

### How does it work?
The Scanner Pro acts as a USB host device for keyboards and barcode scanners and receives the barcode data as a string. This string can be manipulated or used for logic in user generated scripts before being spit out back to the computer. The ATMEGA32U4 on board acts like a USB client device (i.e. a USB keyboard) and sends the output as keystrokes so it's just like using a keyboard.

### Example Use Cases
- Wrap keyboard keys with a modifier to enable multi-keyboard macros. See [this example script](https://github.com/oschwartz10612/Scanner-Pro-MK3/wiki/Keyboard-Pass-through). 
- Populate all PXI imaging screen dialog boxes upon the scan of the computer's barcode ID.
- Populate software installation dialog boxes upon the scan of the computer's barcode ID.
- Populate inventory form dialog boxes differently based on what type of device you scan.
- Complete checkout and checkin device forms with detection of user role based on device ID barcode.

See [FCPS Firmware 2.0](https://github.com/oschwartz10612/Scanner-Pro-MK3/wiki/FCPS-Precompiled-Firmware-2.0) for a real world use case.

### Compatibility
The Scanner Pro acts as a USB host device. This means that it works with all barcode scanners that mimic a USB HID keyboard (and even keyboards themselves)! The device detects the end of a barcode by waiting for either a `tab` or `enter` key id at the end of the barcode. Most scanners can be configured.

## Scanner Pro Manager
A desktop application to install precompiled firmware for Scanner Pro boards as well as interacting over UART. Download from [releases](https://github.com/oschwartz10612/Scanner-Pro-MK3/releases). 
![](/docs/demo.png)

## Firmware
Firmware files are distributed in .hex precompiled binaries. See [the wiki](https://github.com/oschwartz10612/Scanner-Pro-MK3/wiki/FCPS-Precompiled-Firmware-2.0) to browse and install precompiled firmware. Current precompiled firmware includes:
 1. [FCPS Firmware 2.0](https://github.com/oschwartz10612/Scanner-Pro-MK3/wiki/FCPS-Precompiled-Firmware-2.0)

If you have written firmware and would like to share. Open a pull request and include your source code and compiled hex in the firmware directory.

### Developing Firmware
Custom sketches can be written for the board in using the Arduino Board framework. Reference [the wiki](https://github.com/oschwartz10612/Scanner-Pro-MK3/wiki/Developing-Custom-Scripts-and-Firmware) for more information.

If you would like custom developed firmware for your application, please open an issue or contact me.

## PCB and Parts
PCB files and a BOM are included in the repo. If you would like one, please [place an order](https://www.ebay.com/itm/194171078355) on eBay or message me there with questions about the product.


