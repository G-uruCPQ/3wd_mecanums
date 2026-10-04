#ifndef KINEMATICS_H
#define KINEMATICS_H

#include <Arduino.h>
#include "DCMotor.h"

class Kinematics {
public:
  Kinematics(DCMotor& m1, DCMotor& m2, DCMotor& m3);
  ~Kinematics() = default;

  void init();
  void update(float vx, float vy, float vrot);

private:
  DCMotor* motor1;
  DCMotor* motor2;
  DCMotor* motor3;

  const float (*matrix)[3];

  const float wheelRadius = 0.030;  // [m] φ60mm → 0.030
  const float robotRadius = 0.225;  // [m] φ450mm → 0.225

  float deg2rpm(float degPerSec);
};

#endif