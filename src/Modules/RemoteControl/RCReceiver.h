#ifndef _RCReceiver_h
#define _RCReceiver_h

#include "RCSwitch.h"
#include "../IControl.h"

class RCReceiver : public IControl {
  public:
    RCReceiver();   
    virtual ControlCode GetControlCode();

  private:
    RCSwitch *_switch;
};

#endif