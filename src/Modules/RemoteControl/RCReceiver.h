#ifndef _RCReceiver_h
#define _RCReceiver_h

#include "RCSwitch.h"
#include "../IControl.h"

class RCReceiver : public IControlReceiver {
  public:
    RCReceiver();   
    virtual ControlCode GetControlCode();

  private:
    RCSwitch *_switch;

    int _commandDelayMs;
    ControlCode _lastCommand;
    unsigned long _lastCommandTime; 
};

#endif