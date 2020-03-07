#include "bluetooth-control.h"

void BluetoothControl::init() {
  while (!btStart())
  {
    delay(100);
  }

  while (esp_bluedroid_init() != ESP_OK)
  {
    delay(100);
  }

  while (esp_bluedroid_enable() != ESP_OK)
  {
    delay(100);
  }

  BluetoothControl::displayMacAddress();
}

void BluetoothControl::displayMacAddress() {
  Serial.print("Bluetooth address: ");
  const uint8_t *point = esp_bt_dev_get_address();
  for (int i = 0; i < 6; i++)
  {
    char str[3];
    sprintf(str, "%02x", (int)point[i]);
    Serial.print(str);

    if (i < 5)
    {
      Serial.print(":");
    }
  }
  Serial.println();
}
