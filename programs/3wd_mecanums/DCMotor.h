#ifndef DCMOTOR_H
#define DCMOTOR_H

#include <Arduino.h>
#include "AMT.h"
#include "pid.h"

class DCMotor {
public:
  DCMotor(const uint8_t* pins = nullptr, bool useEncoder = true);
  ~DCMotor() = default;

  void init();
  void update();
  float targetRpm;

private:
  const uint8_t* pins;

  AMT* encoder;
  Pid* pid;
  bool useEncoder;

  unsigned long prevTime;
  float preRev;
};

#endif
