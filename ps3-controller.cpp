#include "ps3-controller.h"

void PS3Controller::init() {
  while (!Ps3.begin())
  {
    delay(100);
  }

  while (!Ps3.isConnected())
  {
    delay(100);
  }
}

PS3Controller_ButtonData PS3Controller::buttonData() {
  return Ps3.data.button;
}

bool PS3Controller::triangleButtonPressed() {
  return PS3Controller::buttonData().triangle;
}

bool PS3Controller::circleButtonPressed() {
  return PS3Controller::buttonData().circle;
}

bool PS3Controller::crossButtonPressed() {
  return PS3Controller::buttonData().cross;
}

bool PS3Controller::squareButtonPressed() {
  return PS3Controller::buttonData().square;
}

bool PS3Controller::l1ButtonPressed() {
  return PS3Controller::buttonData().l1;
}

bool PS3Controller::l2ButtonPressed() {
  return PS3Controller::buttonData().l2;
}

bool PS3Controller::r1ButtonPressed() {
  return PS3Controller::buttonData().r1;
}

bool PS3Controller::r2ButtonPressed() {
  return PS3Controller::buttonData().r2;
}

PS3Controller_AnalogStickData PS3Controller::analogStickData() {
  return Ps3.data.analog.stick;
}

float PS3Controller::analogStickPercentLX()
{
  return PS3Controller::convertJoystickValueToPercent(PS3Controller::analogStickData().lx);
}

float PS3Controller::analogStickPercentLY()
{
  return PS3Controller::convertJoystickValueToPercent(PS3Controller::analogStickData().ly);
}

float PS3Controller::analogStickPercentRX()
{
  return PS3Controller::convertJoystickValueToPercent(PS3Controller::analogStickData().rx);
}

float PS3Controller::analogStickPercentRY()
{
  return PS3Controller::convertJoystickValueToPercent(PS3Controller::analogStickData().ry);
}

float PS3Controller::convertJoystickValueToPercent(int value)
{
  int adjustedValue = (value + 1) * -1;

  if (adjustedValue > 127)
  {
    adjustedValue = 127;
  }

  if (adjustedValue < -127)
  {
    adjustedValue = -127;
  }

  return adjustedValue / 127.0;
}
