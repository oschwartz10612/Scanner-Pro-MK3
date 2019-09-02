#include <includes.h>

//Scan the rack location to store in memory. Then scan ID and barcode.
String rack = "";
bool eFlag = false;
bool script(String msg) {
    int delayTime = 50;
    if (msg != "") {
        //Check if it is a barcode by looking at the first two numbers
        for (unsigned int i = 0; i < sizeof(msg); i++) {
            if (isalpha(msg[i])) {
                rack = msg;
                if(String(msg[i]) == "e") {
                    eFlag = true;
                } else {
                    eFlag = false;
                }
                return true;
            }
        }


        bool barcode = false;
        for (int i = 0; i < 2; i++) {
            if (String(msg[i]) == "0") {
                barcode = true;
            } else {
                barcode = false;
            }
        }

        if(barcode) {
            Keyboard.print(msg);
            delay(delayTime);
            Keyboard.write(9); //TAB
            Keyboard.print(rack);
            if (eFlag) {
                Keyboard.print("-");
            }
            Keyboard.write(9); //TAB
        } else {
            Keyboard.print(msg);
            Keyboard.write(9); //TAB
        }
    }
    return true;
}