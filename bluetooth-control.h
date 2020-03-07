#ifndef _BLUETOOTH_CONTROL_H
#define _BLUETOOTH_CONTROL_H

#include <Arduino.h>
#include <esp_bt.h>
#include <esp_bt_main.h>
#include <esp_bt_device.h>

class BluetoothControl {
  public:
    static void init(void);
    static void displayMacAddress(void);
};

#endif // _BLUETOOTH_CONTROL_H
