#ifndef KINEMATICS_H
#define KINEMATICS_H

#include <Arduino.h>
#include "DCMotor.h"

class Kinematics {
public:
  Kinematics(DCMotor* motor);
  ~Kinematics() = default;

  void init();
  void update(float vx, float vy, float vrot);

private:
  DCMotor* motor;

  const float (*matrix)[3];

  const float wheelRadius = 0.030;  // [m] φ60mm → 0.030
  const float robotRadius = 0.225;  // [m] φ450mm → 0.225

  float deg2rpm(float degPerSec);
};

#endif