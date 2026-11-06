#include "Kinematics.h"
#include "config.h"
#include "mecanums.h"

Kinematics::Kinematics(DCMotor* motor)
  : motor(motor) {}

void Kinematics::init() {
  for (size_t i = 0; i < 3; i++) motor[i].init();

  switch (ROBOT_NUM) {
    case 1: matrix = MECANUM1; break;
    case 2: matrix = MECANUM2; break;
    case 3: matrix = MECANUM3; break;

    default: matrix = MECANUM_ZEROS; break;
  }
}

void Kinematics::update(float vx, float vy, float vrot) { //vx, vy, vrot: -1.0 ~ 1.0 
  constexpr float MAX_RPM = 45.0f;
  constexpr float ROT_GAIN = 0.7f;

  float w[3] = {
    matrix[0][0] * vx + matrix[0][1] * vy + matrix[0][2] * ROT_GAIN * vrot,
    matrix[1][0] * vx + matrix[1][1] * vy + matrix[1][2] * ROT_GAIN * vrot,
    matrix[2][0] * vx + matrix[2][1] * vy + matrix[2][2] * ROT_GAIN * vrot
  };

  float maxAbs = 1.0f;
  for (size_t i = 0; i < 3; i++) maxAbs = max(maxAbs, fabsf(w[i]));

  // Serial.printf("%f %f %f\n", w[0], w[1], w[2]);

  for (size_t i = 0; i < 3; i++) {
    motor[i].targetRpm = MAX_RPM * w[i] / maxAbs;
    motor[i].update();
  }
}

// float Kinematics::deg2rpm(float degPerSec) {return degPerSec * 60.0f / 360.0f;}
