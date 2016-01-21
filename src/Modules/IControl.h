#ifndef _IControl_h
#define _IControl_h

enum ControlCode : unsigned long {
  FORWARD = 1,
  BACK = 2,
  RIGHT = 4,
  LEFT = 8,
  STOP = 1024
};

inline ControlCode operator|(ControlCode a, ControlCode b)
{return static_cast<ControlCode>(static_cast<unsigned long>(a) | static_cast<unsigned long>(b));}



class IControlReceiver{
  public:
    virtual ControlCode GetControlCode() = 0;    
};

class IControlTransmitter{
  public:
    virtual void SetCode(ControlCode code) = 0;    
};

#endif