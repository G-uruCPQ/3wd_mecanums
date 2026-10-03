#ifndef CONFIG_H
#define CONFIG_H

// ピン配置
const uint8_t PIN_MCNM[3][4] = {  // PWM, DIR, ENC_A, ENC_B
  {16,  4, 32, 33},
  {17,  5, 34, 35},
  {19, 18, 36, 39}
};
const uint8_t PIN_UART2_TX = 26;
const uint8_t PIN_UART2_RX = 27;

// AMTのdip配置
const int AMT_dip[3] = {0b0000, 0b0000, 0b0000};

// PIDパラメータ
const float mcnmPID_Param[3][3] = { // Kp, Ki, Kd
  {10.0, 0.0, 0.0},
  {10.0, 0.0, 0.0},
  {10.0, 0.0, 0.0}
};

const uint8_t ROBOT_NUM = 1   // mecanum1
// const uint8_t ROBOT_NUM = 2   // mecanum2
// const uint8_t ROBOT_NUM = 3   // mecanum3

const bool DEBUG_MODE = true;
const int SERIAL_BAUD_RATE = 115200;

#endif
