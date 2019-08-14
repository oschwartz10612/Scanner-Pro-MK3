#include <includes.h>

//Just scan barcode and finish with "FCPSON" in PXI
bool script(String msg) {
    int delayTime = 50;
    if (msg != "") {
        Keyboard.write(9); //TAB
        delay(delayTime);
        Keyboard.print("2390N");
        delay(delayTime);
        Keyboard.print(msg);
        delay(delayTime);
        Keyboard.write(9); //TAB
        delay(delayTime);
        Keyboard.print("FCPSON");
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
  return true;
}




