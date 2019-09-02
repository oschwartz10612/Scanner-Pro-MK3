# Scanner Pro MK3
Takes USB input from a USB Keyboard HID device and sends the message to the computer with customizable macros.

Works with barcode scanners and USB Keyboards.

### Current Build
[![Build Status](https://travis-ci.com/oschwartz10612/Scanner-Pro-MK3.svg?branch=master)](https://travis-ci.com/oschwartz10612/Scanner-Pro-MK3)

## Installation
Download the latest manager application from [releases.](https://github.com/oschwartz10612/Scanner-Pro-MK3/releases)

## Install new Firmware
1. Plug in the Scanner Pro to a USB port on a computer.

2. Run Scanner Pro Manager

3. Ensure that the port is correctly selected

4. Download the latest firmware from [releases.](https://github.com/oschwartz10612/Scanner-Pro-MK3/releases)

5. Click "Select File" and choose a .hex file.

4. Click "Run"

## Execute commands
Interaction with the device is done through serial commands.

1. Plug in the Scanner Pro to a USB port on a computer.

2. Run Scanner Pro Manager

3. Ensure that the port is correctly selected

4. Click "Connect" and ensure that the device connects.

5. Plug a scanner into the Scanner Pro and scan the following barcode to change the device into program mode.
[program](assets/program.png)

6. Wait for the following output
```
Ready to accept commands!
```

7. Type the command in the input next to "Send" and click "Send"

### Available SET Commands
```
SET school_code <code>
```
Sets the school code for the PXI script. This appends to the front of a scanned barcode.

### Available GET Commands
```
GET school_code
```
Gets the current school code

## How to make a custom script?
Work in progress...