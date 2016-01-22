#include "RCReceiver.h"

RCReceiver::RCReceiver() {
  this->_switch = new RCSwitch();
  this->_switch->enableReceive(0);

  this->_commandDelayMs = 1250;
  this->_lastCommand = ControlCode::STOP;
  this->_lastCommandTime = millis();
}

ControlCode RCReceiver::GetControlCode(){
  if (this->_switch->available()) {
    unsigned long rCode = this->_switch->getReceivedValue();  
    this->_switch->resetAvailable();

    this->_lastCommand = static_cast<ControlCode>(rCode);
    this->_lastCommandTime = millis();
    return this->_lastCommand;
  }

  if((millis() - this->_lastCommandTime) < this->_commandDelayMs)
    return this->_lastCommand;

  return ControlCode::STOP;
}
