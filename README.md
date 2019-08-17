# Scanner Pro MK3
Takes USB input from a barcode scanner and sends the message to the computer with customizable macros.

### Current Build
[![Build Status](https://travis-ci.com/oschwartz10612/Scanner-Pro-MK3.svg?branch=master)](https://travis-ci.com/oschwartz10612/Scanner-Pro-MK3)

## Installation
Download and install the latest upload application from [releases.](https://github.com/oschwartz10612/Scanner-Pro-MK3/releases)

## Usage
1. Plug in the Scanner Pro to a USB port on a computer.

2. In Windows device manager under "Ports" make note of the Arduino device COM port. For example: COM8.

3. Run the "Scanner Pro Upload" application.

4. Enter the COM port.

5. Pick a script to download by entering the corresponding number.

6. Allow the script to download to the board. You should hear the Windows chime confirming that the board has disconnected then reconnected.

## How to make a custom script?
1. Download and install Python.

2. Download and install [platformio](https://platformio.org/install/cli).

3. Clone or download this repository:
```bash
git clone https://github.com/oschwartz10612/Scanner-Pro-MK3.git
```

4. Create a new file in the scripts directory with the .h extension and a creative name. Populate the file with the following boilerplate:
```c++
#include <includes.h>

bool script(String msg) {
 if (msg != "") {
     //Your code goes here
     Keyboard.print(msg);
 }
 return true;
}
```

5. Write your script in place of the comment. You can access the data from the scanner in the msg variable. Refer to Arduino's [Keyboard](https://www.arduino.cc/reference/en/language/functions/usb/keyboard/) library documentation for reference about writing to the computer as a HID device.

6. In main.cpp, change the following line to match your script file:
```c++
#include <scripts/rackLocationLOANER.h> //User Scripts
```

7. Compile your code to ensure that there are no errors using the following command:
```bash
pio run
```

8. If there are no errors, upload your script to the board by running the following command:
```bash
pio run -t upload
```

9. If you would like to add your script to the uploader, create a new pull request with your new script in the script folder and it will be added for future users.

