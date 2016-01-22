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

inline const char* ToString(ControlCode code)
{
    switch (code)
    {
        case ControlCode::FORWARD:   return "FORWARD";
        case ControlCode::BACK:   return "BACK";
        case ControlCode::RIGHT:   return "RIGHT";
        case ControlCode::LEFT:   return "LEFT";
        case ControlCode::STOP:   return "STOP";
    }

    String str = String(static_cast<unsigned long>(code));
    //char cstr[16];
    char* cstr = new char [17];
    str.toCharArray(cstr,16);
    return cstr;
}



class IControlReceiver{
  public:
    virtual ControlCode GetControlCode() = 0;    
};

class IControlTransmitter{
  public:
    virtual void SetCode(ControlCode code) = 0;    
};

#endif