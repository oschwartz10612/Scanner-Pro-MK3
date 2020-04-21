/*
  Scanner.cpp - Library for writing custom scripts for the Scanner Pro MK3
  Created by Owen Schwartz, November 30, 2019.
  Released into the public domain.
*/

#include <Arduino.h>
#include <./keyboard/Keyboard.h>
#include "Scanner.h"

Scanner::Scanner()
{
    Serial1.begin(9600);
    Keyboard.begin();
}

void Scanner::write(int data)
{
    Keyboard.write(data);
}

void Scanner::print(String data)
{
    Keyboard.print(data);
}

void Scanner::disable_output()
{
    Keyboard.end();
}

boolean Scanner::available()
{
    if (Serial1.available() > 0 && _finished == false)
    {
        return true;
    }
    else
    {
        _finished = false;
        return false;
    }
}

void serialFlush()
{
    char t = Serial.read();
    while (Serial.available() > 0)
    {
        t = Serial.read();
    }
}

String Scanner::read_enter()
{
    _msg = "";
    while (true)
    {
        if (Serial1.available() > 0)
        {
            inByte = Serial1.read();
            if (inByte == 27)
            {
                flag_esc = 1;
            }
            else
            {
                if (flag_esc == 1)
                {
                    // Previous char was ESC - Decode all the escaped keys
                    switch (inByte)
                    {
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
                else
                {
                    if (inByte == 13)
                    { //Enter
                        serialFlush();
                        _finished = true;
                        return _msg;
                    }
                    else
                    {
                        _msg += (char)inByte;
                    }
                }
            }
        }
    }
}

String Scanner::read_tab()
{
    _msg = "";
    while (true)
    {
        if (Serial1.available() > 0)
        {
            inByte = Serial1.read();
            if (inByte == 27)
            {
                flag_esc = 1;
            }
            else
            {
                if (flag_esc == 1)
                {
                    // Previous char was ESC - Decode all the escaped keys
                    switch (inByte)
                    {
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
                else
                {
                    if (inByte == 9)
                    { //Tab
                        serialFlush();
                        _finished = true;
                        return _msg;
                    }
                    else
                    {
                        _msg += (char)inByte;
                    }
                }
            }
        }
    }
}