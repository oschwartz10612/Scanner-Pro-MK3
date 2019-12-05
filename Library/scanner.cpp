/*
  scanner.cpp - Library for writing custom scripts for the Scanner Pro MK3
  Created by Owen Schwartz, November 30, 2019.
  Released into the public domain.
*/

#include <Arduino.h>
#include "scanner.h"

Scanner::Scanner() {
    Serial1.begin(9600);
    Keyboard.begin();
}

void Scanner::write(int data) {
    Keyboard.write(data);
}

void Scanner:print(String data) {
    Keyboard.print(data);
}

void Scanner::disable_output() {
    Keyboard.end();
}

String Scanner::read_enter() {
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
                        _msg += "[Up]";
                        break; 
                    case 0x50:
                        _msg += "[Down]";
                        break; 
                    case 0x4B:
                        _msg += "[Left]";
                        break; 
                    case 0x4D:
                        _msg += "[Right]";
                        break;         
                    case 0x54:
                        _msg += "[Print]";
                        break; 
                    case 0x5B:
                        _msg += "[Windows]";
                        break;   
                    default:
                        _msg += "[?]";
                        break;            
                }
                flag_esc = 0;    
            }
            else {  
                if(inByte == 9) {return "";}
                else if(inByte == 13) {
                    return _msg;
                    _msg = "";
                }
                else if(inByte == 10) {return "";}
                    else {
                    _msg += (char)inByte;
                    return "";
                }
            }
        }  
    }
}

String Scanner::read_tab() {
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
                        _msg += "[Up]";
                        break; 
                    case 0x50:
                        _msg += "[Down]";
                        break; 
                    case 0x4B:
                        _msg += "[Left]";
                        break; 
                    case 0x4D:
                        _msg += "[Right]";
                        break;         
                    case 0x54:
                        _msg += "[Print]";
                        break; 
                    case 0x5B:
                        _msg += "[Windows]";
                        break;   
                    default:
                        _msg += "[?]";
                        break;            
                }
                flag_esc = 0;    
            }
            else {  
                if(inByte == 9) { //Tab
                    return _msg;
                    _msg = "";
                }
                else if(inByte == 13) {return "";}
                else if(inByte == 10) {return "";}
                    else {
                    _msg += (char)inByte;
                    return "";
                }
            }
        }  
    }
}