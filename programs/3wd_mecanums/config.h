#ifndef CONFIG_H
#define CONFIG_H

#define PIN_MCNM1_PWM       16
#define PIN_MCNM1_DIR        4
#define PIN_MCNM1_ENC_A     32
#define PIN_MCNM1_ENC_B     33

#define PIN_MCNM2_PWM       17
#define PIN_MCNM2_DIR        5
#define PIN_MCNM2_ENC_A     34
#define PIN_MCNM2_ENC_B     35

#define PIN_MCNM3_PWM       19
#define PIN_MCNM3_DIR       18
#define PIN_MCNM3_ENC_A     36
#define PIN_MCNM3_ENC_B     39

#define PIN_UART2_TX        26
#define PIN_UART2_RX        27

#define MCNM1_Kp            10.0
#define MCNM1_Ki            0.0
#define MCNM1_Kd            0.0
#define MCNM2_Kp            10.0
#define MCNM2_Ki            0.0
#define MCNM2_Kd            0.0
#define MCNM3_Kp            10.0
#define MCNM3_Ki            0.0
#define MCNM3_Kd            0.0

#define AMT_dip1            0b0000
#define AMT_dip2            0b0000
#define AMT_dip3            0b0000

#define DEBUG_MODE          true
#define SERIAL_BAUD_RATE    115200

#endif
