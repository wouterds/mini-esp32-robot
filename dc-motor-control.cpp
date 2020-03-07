#include "dc-motor-control.h"

void DCMotorControl::init()
{
  pinMode(PIN_DC_MOTOR_LF, OUTPUT);
  pinMode(PIN_DC_MOTOR_LB, OUTPUT);
  pinMode(PIN_DC_MOTOR_RF, OUTPUT);
  pinMode(PIN_DC_MOTOR_RB, OUTPUT);
}

void DCMotorControl::setLeftMotorSpeed(int speed)
{
  if (speed > 0)
  {
    analogWrite(PIN_DC_MOTOR_LF, abs(speed));
    analogWrite(PIN_DC_MOTOR_LB, 0);
    return;
  }

  if (speed < 0)
  {
    analogWrite(PIN_DC_MOTOR_LF, 0);
    analogWrite(PIN_DC_MOTOR_LB, abs(speed));
    return;
  }

  analogWrite(PIN_DC_MOTOR_LF, 0);
  analogWrite(PIN_DC_MOTOR_LB, 0);
}

void DCMotorControl::setLeftMotorSpeedPercent(float percent)
{
  DCMotorControl::setLeftMotorSpeed(percent * 1024);
}

void DCMotorControl::setRightMotorSpeed(int speed)
{
  if (speed > 0)
  {
    analogWrite(PIN_DC_MOTOR_RF, abs(speed));
    analogWrite(PIN_DC_MOTOR_RB, 0);
    return;
  }

  if (speed < 0)
  {
    analogWrite(PIN_DC_MOTOR_RF, 0);
    analogWrite(PIN_DC_MOTOR_RB, abs(speed));
    return;
  }

  analogWrite(PIN_DC_MOTOR_RF, 0);
  analogWrite(PIN_DC_MOTOR_RB, 0);
}

void DCMotorControl::setRightMotorSpeedPercent(float percent)
{
  DCMotorControl::setRightMotorSpeed(percent * 1024);
}
