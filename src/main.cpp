#include <includes.h>
#include "SerialCommands.h"
#include "eepromStrings.h"

char serial_command_buffer_[32];
SerialCommands serial_commands_(&Serial, serial_command_buffer_, sizeof(serial_command_buffer_), "<>", " ");

String msg;
char flag_esc = 0;
int inByte;
#define SCRIPT read_String(10)
#define SCHOOL_CODE read_String(0)

int installedScriptsPos = 0;
String installedScripts[] = {"pxi", "distribution"};

#include <scripts/pxi.h> //User Scripts
#include <scripts/distribution.h> //User Scripts

void cmd_unrecognized(SerialCommands* sender, const char* cmd) {
	sender->GetSerial()->print("Unrecognized command [");
	sender->GetSerial()->print(cmd);
	sender->GetSerial()->println("]");
}

void cmd_set_eeprom(SerialCommands* sender) {
  char* option = sender->Next();

  if (option == NULL) {
    sender->GetSerial()->println("ERROR: NO OPTION");
    return;

  } else if (strcmp(option, "school_code") == 0) {
    char* schoolCode = sender->Next();
    sender->GetSerial()->print("Saving \"");
    sender->GetSerial()->print(schoolCode);
    sender->GetSerial()->println("\"");

    String data = schoolCode;

    writeString(0, data);

    } else if (strcmp(option, "script") == 0) {
    char* script = sender->Next();
    sender->GetSerial()->print("Setting script as \"");
    sender->GetSerial()->print(script);
    sender->GetSerial()->println("\"");

    String data = script;

    writeString(10, data);

  } else {
    sender->GetSerial()->println("ERROR: OPTION NOT RECOGNIZED");
  }
}

void cmd_get_eeprom(SerialCommands* sender) {
  char* option = sender->Next();

  if (option == NULL) {
    sender->GetSerial()->println("ERROR: NO OPTION");
    return;

  } else if (strcmp(option, "school_code") == 0) {
    String schoolCode = read_String(0);
    sender->GetSerial()->print(schoolCode);

  } else if (strcmp(option, "script") == 0) {
    String script = read_String(10);
    sender->GetSerial()->println("The currently selected script is:");
    sender->GetSerial()->print(script);

  } else if (strcmp(option, "installed_scripts") == 0) {
    sender->GetSerial()->println("Scripts currently installed:");
    for (unsigned int i = 0; i < sizeof(installedScripts); i++) {
      sender->GetSerial()->println(installedScripts[i]);
    }

  } else {
    sender->GetSerial()->println("ERROR: OPTION NOT RECOGNIZED");
  }
}

SerialCommand cmd_set_eeprom_("SET", cmd_set_eeprom);
SerialCommand cmd_get_eeprom_("GET", cmd_get_eeprom);

void setup() {
  Serial1.begin(9600);
  Keyboard.begin();

  serial_commands_.SetDefaultHandler(cmd_unrecognized);
	serial_commands_.AddCommand(&cmd_set_eeprom_);
  serial_commands_.AddCommand(&cmd_get_eeprom_);
}

void onFinished() {
  if (msg == "PROGRAM") {
    Keyboard.end();
    delay(500);
    Serial.begin(9600);
    delay(500);
    Serial.println("Ready to accept commands!");
    while (true) {
      serial_commands_.ReadSerial();
    }
  }
  
  else {

    if (SCRIPT == "pxi") {
      if (pxi(msg)) {
        msg = "";
      } else {
        Keyboard.print("Error!");
      }
    }

    if (SCRIPT == "distribution") {
      if (distribution(msg)) {
        msg = "";
      } else {
        Keyboard.print("Error!");
      }
    }

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
  

