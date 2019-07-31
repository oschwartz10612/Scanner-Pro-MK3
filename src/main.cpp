#include <Arduino.h>

char flag_esc=0;

void setup() {
  Serial.begin(9600);
  Serial.println("Type some characters and i will send them back");
}

void loop() {

  if (Serial.available() > 0) {
    int inByte = Serial.read();  
    if(inByte == 27)
    {
       flag_esc = 1;
    }   
    else
    {
      if(flag_esc==1)
      {
        // Previous char was ESC - Decode all the escaped keys
        switch(inByte)
        {
            case 0x49:
              Serial.print("[PgUp]");
              break;
            case 0x51:
              Serial.print("[PgDn]");
              break;    
            case 0x47:
              Serial.print("[Home]");
              break;
            case 0x4F:
              Serial.print("[End]");
              break;     
            case 0x52:
              Serial.print("[Ins]");
              break;
            case 0x53:
              Serial.print("[Del]");
              break;               
            case 0x3B:
              Serial.print("[F1]");
              break;
            case 0x3C:
              Serial.print("[F2]");
              break;    
            case 0x3D:
              Serial.print("[F3]");
              break;
            case 0x3E:
              Serial.print("[F4]");
              break;     
            case 0x3F:
              Serial.print("[F5]");
              break;
            case 0x40:
              Serial.print("[F6]");
              break;          
            case 0x41:
              Serial.print("[F7]");
              break; 
            case 0x42:
              Serial.print("[F8]");
              break; 
            case 0x43:
              Serial.print("[F9]");
              break; 
            case 0x44:
              Serial.print("[F10]");
              break; 
            case 0x57:
              Serial.print("[F11]");
              break; 
            case 0x58:
              Serial.print("[F12]");
              break;     
            case 0x48:
              Serial.print("[Up]");
              break; 
            case 0x50:
              Serial.print("[Down]");
              break; 
            case 0x4B:
              Serial.print("[Left]");
              break; 
            case 0x4D:
              Serial.print("[Right]");
              break;         
            case 0x54:
              Serial.print("[Print]");
              break; 
            case 0x5B:
              Serial.print("[Windows]");
              break;   
            default:
              Serial.print("[?]");
              break;            
        }
        flag_esc=0;    
      }
      else
      {  

        if(inByte==1)
        {
           Serial.print("Control-A");
        }  
        else if(inByte==2)
        {
           Serial.print("Control-B");
        }
        else if(inByte==3)
        {
           Serial.print("Control-C");
        }
        else if(inByte==4)
        {
           Serial.print("Control-D");
        }
        else if(inByte==5)
        {
           Serial.print("Control-E");
        }
        else if(inByte==6)
        {
           Serial.print("Control-F");
        }
        else if(inByte==7)
        {
           Serial.print("Control-G");
        }
        // Dont decode 8 - backspace
        else if(inByte==9)
        {
           Serial.print("Tab");
        }
        // Dont decode 10 - Line Feed
        else if(inByte==11)
        {
           Serial.print("Control-K");
        }
        else if(inByte==12)
        {
           Serial.print("Control-L");
        }
        // Dont decode 13 - Carriage Return
        else if(inByte==14)
        {
           Serial.print("Control-N");
        }
        else if(inByte==15)
        {
           Serial.print("Control-O");
        }
        else if(inByte==16)
        {
           Serial.print("Control-P");
        }
        else if(inByte==17)
        {
           Serial.print("Control-Q");
        }
        else if(inByte==18)
        {
           Serial.print("Control-R");
        }
        else if(inByte==19)
        {
           Serial.print("Control-S");
        }
        else if(inByte==20)
        {
           Serial.print("Control-T");
        }
        else if(inByte==21)
        {
           Serial.print("Control-U");
        }
        else if(inByte==22)
        {
           Serial.print("Control-V");
        }
        else if(inByte==23)
        {
           Serial.print("Control-W");
        }
        else if(inByte==24)
        {
           Serial.print("Control-X");
        }
        else if(inByte==25)
        {
           Serial.print("Control-Y");
        }        
        else if(inByte==26)
        {
           Serial.print("Control-Z");
        }

        else   
        {
          // Its a normal key
          Serial.write(inByte);
        }  
      }
    }  
  }     
}