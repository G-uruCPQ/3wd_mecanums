#include <Arduino.h>

#include "config.h"
#include "DCMotor.h"
#include "Kinematics.h"
#include "myBLEController.h"

hw_timer_t *timer = NULL;   // タイマーのポインタ

void onTimer();

// 各種インスタンス生成
DCMotor mcnm[3];
Kinematics kinematics(mcnm);
MyBLEController myBLE;

void setup() {
  // --- Serial Monitor ---
  if (DEBUG_MODE) {
    Serial.begin(SERIAL_BAUD_RATE);
    while (!Serial) {}
    Serial.printf("=== mecanum%d Program Start ===\n", ROBOT_NUM);
  }
  for (size_t i = 0; i < 3; i++) mcnm[i] = DCMotor(PIN_MCNM[i], true);
  kinematics.init();

  // BLE初期化
  myBLE.begin("My BLE Controller");  // 広告するデバイス名
  // timer = timerBegin(1000);  // タイマーを1kHzで初期化
  // timerAttachInterrupt(timer, &onTimer);  // 割り込み関数を設定
  // timerAlarm(timer, 50, true, 0);  // 50msごとに割り込みを発生させる

  // Serial2.begin(SERIAL_BAUD_RATE, SERIAL_8N1, PIN_UART2_RX, PIN_UART2_TX);
}

// int16_t v[3] = {0, 0, 0};  // {vx, vy, vrot}

// void IRAM_ATTR onTimer() {
//   // 何かキーが受信されていれば確認
//   // static String lastVal;
//   current = myBLE.getLastReceived();
//   if (DEBUG_MODE){
//     Serial.print("d0:");
//     Serial.print(current[0][0]);
//     Serial.print(current[0][1]);
//     Serial.print(",d1:");
//     Serial.print(current[1][0]);
//     Serial.println(current[1][1]);
//   }
//   v[0] = (current[0][0] - 512); v[1] = (current[0][1] - 512); v[2] = (current[1][0] - 512);
// }

void loop(){
  // BLEコールバックが更新した値を取得
  auto current = myBLE.getLastReceived();

  int16_t raw_v[3] = {
    current[0][0] - 512,  // X
    current[0][1] - 512,  // y
    current[1][0] - 512   // rot
  };
  
  float vx   = (abs(raw_v[0]) > 15) ? raw_v[0] / 512.0f : 0;
  float vy   = (abs(raw_v[1]) > 15) ? raw_v[1] / 512.0f : 0;
  float vrot = (abs(raw_v[2]) > 15) ? raw_v[2] / 512.0f : 0;

  // 通信断絶時停止
  if (!myBLE.isDeviceConnected()) {vx = 0; vy = 0; vrot = 0;}

  kinematics.update(vx, vy, vrot);

  if (DEBUG_MODE) Serial.printf("BLE: %d  vx:%f vy:%f vrot:%f\n", myBLE.isDeviceConnected(), vx, vy, vrot);

  delay(10);
}