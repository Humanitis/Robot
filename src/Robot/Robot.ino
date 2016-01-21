/*
  RF_Sniffer
 
  Hacked from http://code.google.com/p/rc-switch/
 
  by @justy to provide a handy RF code sniffer
*/
 
#include "RCSwitch.h"
#include "../Modules/RemoteControl/RCReceiver.h"
#include <stdlib.h>
#include <stdio.h>
RCReceiver test = RCReceiver();
 
void setup() {
  Serial.begin(9600);
  //mySwitch.enableReceive(0);  // Receiver on inerrupt 0 =&gt; that is pin #2
  Serial.println("Start");
}
 
void loop() {
  ControlCode code = test.GetControlCode();
  if (code != ControlCode::STOP) {
 
     Serial.print("Received ");
     Serial.print(code);

    Serial.println("");
 
  }
}
