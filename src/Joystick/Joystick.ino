#include "RCSwitch.h"
#include "Modules/RemoteControl/RCTransmitter.h"

int up_button = 2;
int down_button = 4;
int left_button = 5;
int right_button = 3;
int start_button = 6;
int select_button = 7;
int analog_button = 8;
int x_axis = A0;
int y_axis = A1;

int buttons[] = {up_button, 
                down_button,
                left_button,
                right_button,
                start_button,
                select_button,
                analog_button};

RCTransmitter test = RCTransmitter();

void setup(void)
{
  
  for(int i; i < 7; i++)
  {
    pinMode(buttons[i], INPUT);
    digitalWrite(buttons[i], HIGH);
  }

  Serial.begin(9600);
}

void loop(void)
{

  int x = map(analogRead(x_axis), 0, 1000, -1, 1);
  Serial.print("x = "), Serial.print(x), Serial.print("\t");
  if(-1 == x) x = 2;
  x = x * 4;
  ControlCode xCode = static_cast<ControlCode>(x);

  int y = map(analogRead(y_axis), 0, 1000, -1, 1);
  Serial.print("y = "), Serial.print(y), Serial.print("\t");
  if(-1 == y) y = 2;
  ControlCode yCode = static_cast<ControlCode>(y);

  ControlCode code = xCode | yCode;

  if(0 == static_cast<unsigned long>(code)) code = ControlCode::STOP;
  Serial.print("code = "), Serial.print(ToString(code)), Serial.print("\t");

  test.SetCode(code);

  Serial.print("\n");
  delay(20);
}
