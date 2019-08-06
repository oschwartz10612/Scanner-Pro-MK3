#include <includes.h>

#include <scripts/pxiID.h> //User Scripts


String msg;
char flag_esc = 0;
int inByte;

void setup() {
  Serial1.begin(9600);
  Keyboard.begin();
}

void onFinished() {
  if (script(msg)) {
    msg = "";
  } else {
    Keyboard.print("Error!");
  }
}

void loop() {

  if (Serial1.available() > 0) {
    inByte = Serial1.read();

    if(inByte == 27) {
      flag_esc = 1;
    } 
    else {
      if(flag_esc == 1) {
        // Previous char was ESC - Decode all the escaped keys
        switch(inByte) {
          case 0x48:
            msg += "[Up]";
            break; 
          case 0x50:
            msg += "[Down]";
            break; 
          case 0x4B:
            msg += "[Left]";
            break; 
          case 0x4D:
            msg += "[Right]";
            break;         
          case 0x54:
            msg += "[Print]";
            break; 
          case 0x5B:
            msg += "[Windows]";
            break;   
          default:
            msg += "[?]";
            break;            
        }
        flag_esc = 0;    
      }
      else {  
        if(inByte == 9) { //Tab
          onFinished();
        }
        else if(inByte == 13) { //Enter
          onFinished();
        }
        else if(inByte == 10) {}
        else {
          msg += (char)inByte;
        }
      }
    }  
  }
}

  2390N0098055555   2390N0098055555   2390N0098055555   2390N0098055555   2390N0098055555 dfdffdg     onFinished
  fsgffdffdf      onFinished
  fffffffffff     onFinished
  

