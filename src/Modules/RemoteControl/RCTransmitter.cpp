#include "RCTransmitter.h"

RCTransmitter::RCTransmitter() {
  this->_switch = new RCSwitch();
  this->_switch->enableTransmit(10);
}

void RCTransmitter::SetCode(ControlCode code){
  this->_switch->send(static_cast<unsigned long>(code), 24);
}
