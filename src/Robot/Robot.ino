#include "RCSwitch.h"
#include "Modules/RemoteControl/RCReceiver.h"
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
  Serial.print("Received ");
  Serial.print(ToString(code));
  Serial.print("\n");
}
