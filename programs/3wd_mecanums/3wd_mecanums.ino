#include <Arduino.h>

#include "config.h"
#include "DCMotor.h"
#include "Kinematics.h"

DCMotor mcnm[3];
Kinematics kinematics(mcnm);


void setup() {
  // --- Serial Monitor ---
  if (DEBUG_MODE) {
    Serial.begin(SERIAL_BAUD_RATE);
    while (!Serial) {}
    Serial.printf("=== mecanum%d Program Start ===\n", ROBOT_NUM);
  }
  for (size_t i = 0; i < 3; i++) mcnm[i] = DCMotor(PIN_MCNM[i], true);
  kinematics.init();
  // Serial2.begin(SERIAL_BAUD_RATE, SERIAL_8N1, PIN_UART2_RX, PIN_UART2_TX);
}

void loop(){
  // TODO: 指令値作る

  int vx = 0;
  int vy = 0;
  int vrot = 0;

  kinematics.update(vx, vy, vrot);

  if (DEBUG_MODE) {

  }

  delay(10);
}