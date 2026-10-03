#include <Arduino.h>

#include "config.h"
#include "DCMotor.h"
#include "Kinematics.h"

DCMotor mcnm1(&PIN_MCNM[0], true);
DCMotor mcnm2(&PIN_MCNM[1], true);
DCMotor mcnm3(&PIN_MCNM[2], true);
Kinematics kinematics(mcnm1, mcnm2, mcnm3);


void setup() {
  // --- Serial Monitor ---
  if (DEBUG_MODE) {
    Serial.begin(SERIAL_BAUD_RATE);
    while (!Serial) {}
    Serial.printf("=== mecanum%d Program Start ===\n", ROBOT_NUM);
  }
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