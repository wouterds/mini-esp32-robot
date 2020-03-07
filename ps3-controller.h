#ifndef _PSS3_CONTROLLER_H
#define _PSS3_CONTROLLER_H

#include <Arduino.h>
#include <Ps3Controller.h>

#define PS3Controller_AnalogStickData ps3_analog_stick_t
#define PS3Controller_ButtonData ps3_button_t

class PS3Controller {
  public:
    static void init(void);

    static PS3Controller_ButtonData buttonData(void);
    static bool triangleButtonPressed(void);
    static bool circleButtonPressed(void);
    static bool crossButtonPressed(void);
    static bool squareButtonPressed(void);
    static bool l1ButtonPressed(void);
    static bool l2ButtonPressed(void);
    static bool r1ButtonPressed(void);
    static bool r2ButtonPressed(void);

    static PS3Controller_AnalogStickData analogStickData(void);
    static float analogStickPercentLX(void);
    static float analogStickPercentLY(void);
    static float analogStickPercentRX(void);
    static float analogStickPercentRY(void);

  private:
    static float convertJoystickValueToPercent(int value);
};

#endif // _PSS3_CONTROLLER_H
