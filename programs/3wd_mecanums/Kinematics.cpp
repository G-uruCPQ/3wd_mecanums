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

void Kinematics::update(float vx, float vy, float vrot) {
  float w[3] = {
    matrix[0][0] * vx + matrix[0][1] * vy + matrix[0][2] * vrot,
    matrix[1][0] * vx + matrix[1][1] * vy + matrix[1][2] * vrot,
    matrix[2][0] * vx + matrix[2][1] * vy + matrix[2][2] * vrot
  };

  if (DEBUG_MODE) Serial.printf("%f %f %f\n", w[0], w[1], w[2]);

  for (size_t i = 0; i < 3; i++) {
    motor[i].targetRpm = deg2rpm(w[i]);
    motor[i].update();
  }
}

float Kinematics::deg2rpm(float degPerSec) {return degPerSec * 60.0f / 360.0f;}
