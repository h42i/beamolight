/*
* Thanks to the following post for the IR Codes
* http://community.acer.com/t5/2014-Archives/H6510BD-projector-home-automation-usb-rs232-ir/m-p/236394/highlight/true#M22742
*/

#include <IRremote.h>

IRsend irsend;
int command;
void setup()
{
  IRsend irsend;
  Serial.begin(9600);

}

void loop() {
  while (Serial.available() > 0) {
    command = Serial.parseInt();
    
    if (Serial.read() == '\n') {
      if(command == 1){
        //Command on
	irsend.sendNEC(0x10C8E11E, 32);
        Serial.print("On");
      } else if(command == 2){
        //Command off
        irsend.sendNEC(0x10C8E11E, 32);
        delay(500);
        irsend.sendNEC(0x10C8E11E, 32);
        Serial.print("Off");
    } else if(command == 3){
        //Command Source
        irsend.sendNEC(0x10C831CE, 32);
        Serial.print("Source");
    }
    }
  }
}
