#ifndef _RCTransmitter_h
#define _RCTransmitter_h

#include "RCSwitch.h"
#include "../IControl.h"

class RCTransmitter : public IControlTransmitter {
  public:
    RCTransmitter();   
    virtual void SetCode(ControlCode code);

  private:
    RCSwitch *_switch;
};

#endif