/*
  scanner.h - Library for writing custom scripts for the Scanner Pro MK3
  Created by Owen Schwartz, November 30, 2019.
  Released into the public domain.
*/

#ifndef Scanner_h
#define Scanner_h

#include "Arduino.h"

class Scanner
{
  public:
    Scanner();

    String read_enter();
    String read_tab();
    
    void write(int data);
    void print(String data);

  private:
    String _msg;
};

#endif