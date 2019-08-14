#include <includes.h>

//Snippit for barcodes with student ids in PXI
bool script(String msg) {
    int delayTime = 50;
    if (msg != "") {
        //Check if it is a barcode by looking at the first two numbers
        bool barcode = false;
        for (int i = 0; i < 2; i++) {
            if (String(msg[i]) == "0") {
                barcode = true;
            } else {
                barcode = false;
            }
        }

        if(barcode) {
            Keyboard.write(9); //TAB
            delay(delayTime);
            Keyboard.print("2390N");
            delay(delayTime);
            Keyboard.print(msg);
            delay(delayTime);
            Keyboard.write(9); //TAB
        } else {
            Keyboard.print(msg);
            delay(delayTime);
            Keyboard.write(9); //TAB
            delay(delayTime);
            Keyboard.write(9); //TAB
            delay(delayTime);
            Keyboard.write(9); //TAB
            delay(delayTime);
            Keyboard.write(111); //o
            delay(delayTime);
            Keyboard.write(176); //Enter
            delay(delayTime);
            Keyboard.write(176); //Enter
        }
    }
    return true;
}