  
#include <Scanner.h>

Scanner Scanner;

String data;

void setup() {
  //Put your code here to run once
}

void loop() {
  //Put your code here to loop
  
  if(Scanner.available()) { //Check if there is data to read from the scanner
    
    data = Scanner.read_enter(); //Read the scanner data into a string. Use Scanner.read_tab() if your device uses tabs.

    //Example munipulation
    Scanner.print(data); //Print the scanner data
    Scanner.write(10); //Send a new line
    Scanner.print("END"); //Print the text "END"
  }
  
}
