#include <includes.h>

//Just scan barcode and finish with "FCPSON" in PXI
bool script(String msg) {


  int delayTime = 50;
  if (msg != "") {

    bool barcode = false;
    for (int i = 0; i < 2; i++) {
        if (String(msg[i]) == "0") {
            barcode = true;
        } else {
            barcode = false;
        }
    }

    if (msg == "START") {
      for (size_t i = 0; i < 3; i++) {
        Keyboard.write(9);
        delay(delayTime);
      }
      Keyboard.write(215);
      delay(delayTime);
      Keyboard.write(9);
      delay(delayTime);
      Keyboard.write(32);
      delay(delayTime);
      Keyboard.write(9);

    } 
    if(msg.length() == 7) {
      Keyboard.print(msg);
      delay(delayTime);
      Keyboard.write(176);
      delay(delayTime*4);
      for (size_t i = 0; i < 7; i++) {
        Keyboard.write(9);
        delay(delayTime);
      }
    }
    if (barcode) {
      Keyboard.print(msg);
      delay(delayTime);
      Keyboard.write(176);
      for (size_t i = 0; i < 7; i++) {
        Keyboard.write(9);
        delay(delayTime);
      }
      Keyboard.write(26);
      delay(delayTime);
      Keyboard.write(9);
      delay(delayTime);
      Keyboard.write(26);
      delay(delayTime);
      Keyboard.write(9);
      delay(delayTime);
      Keyboard.write(9);
      delay(delayTime);
    } 
  }
  return true;
}




