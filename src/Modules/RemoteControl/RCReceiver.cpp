#include "RCReceiver.h"

RCReceiver::RCReceiver() {
  this->_switch = new RCSwitch();
  this->_switch->enableReceive(0);
}

ControlCode RCReceiver::GetControlCode(){
  if (this->_switch->available()) {
    unsigned long rCode = this->_switch->getReceivedValue();  
    this->_switch->resetAvailable();
    if(rCode != 0)
      return static_cast<ControlCode>(rCode);
  }

  return ControlCode::STOP;
}
