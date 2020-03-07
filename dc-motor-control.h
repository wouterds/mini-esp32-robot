#ifndef _DC_MOTOR_CONTROL_H
#define _DC_MOTOR_CONTROL_H

#include <Arduino.h>
#include <esp_bt.h>
#include <analogWrite.h>
#include "ps3-controller.h"

#define PIN_DC_MOTOR_LF 16
#define PIN_DC_MOTOR_LB 4
#define PIN_DC_MOTOR_RF 26
#define PIN_DC_MOTOR_RB 25

class DCMotorControl {
  public:
    static void init(void);
    static void setLeftMotorSpeed(int speed);
    static void setLeftMotorSpeedPercent(float percent);
    static void setRightMotorSpeed(int speed);
    static void setRightMotorSpeedPercent(float percent);
};

#endif // _DC_MOTOR_CONTROL_H
