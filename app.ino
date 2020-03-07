#include "dc-motor-control.h"
#include "bluetooth-control.h"
#include "ps3-controller.h"

void setup()
{
  Serial.begin(115200);

  DCMotorControl::init();
  BluetoothControl::init();
  PS3Controller::init();
}

void loop()
{
  DCMotorControl::setLeftMotorSpeedPercent(PS3Controller::analogStickPercentLY());
  DCMotorControl::setRightMotorSpeedPercent(PS3Controller::analogStickPercentRY());
}
