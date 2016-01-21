#ifndef _IControl_h
#define _IControl_h

enum ControlCode : unsigned long {
  FORWARD = 1,
  BACK = 2,
  LEFT = 4,
  RIGHT = 8,
  STOP = 1024
};

inline ControlCode operator|(ControlCode a, ControlCode b)
{return static_cast<ControlCode>(static_cast<int>(a) | static_cast<int>(b));}



class IControl{
  public:
    virtual ControlCode GetControlCode() = 0;    
};

#endif