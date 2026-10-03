#include "DCMotor.h"
#include "config.h"

namespace {
  // DCMotor* mcnm[3];
  uint8_t totalFBMotorCount = 0;
}

DCMotor::DCMotor(uint8_t* pins, bool useEncoder)
  : pins(pins), useEncoder(useEncoder),
    targetRpm(0), preRev(0), prevTime(0) {}

void DCMotor::init() {
  pinMode(pins[0], OUTPUT);
  pinMode(pins[1], OUTPUT);
  analogWrite(pins[0], 0);
  digitalWrite(pins[1], LOW);

  if (useEncoder) {
    encoder = new AMT(AMT_dip[totalFBMotorCount], pins);
    encoder->init();
    float* k[3] = mcnmPID_Param[totalFBMotorCount];
    totalFBMotorCount++;

    pid = new Pid(k);
    pid->init();

    preRev = encoder->getRevolution();
    prevTime = millis();
  }
}

void DCMotor::update() {
  float control;

  if (useEncoder) {
    unsigned long now = millis();
    float dt = (now > prevTime) ? now - prevTime : 10.0;
    prevTime = now;

    float nowRev = encoder->getRevolution();
    float nowRpm = (nowRev - preRev) / (1000 * dt);
    control = pid->pid_out(targetRpm, nowRpm, dt);
    preRev = nowRev;
  } else {
    control = 1.7 * targetRpm;
  }

  // Serial.println(control);
  control = constrain(control, -255, 255);
  analogWrite(pins[0], static_cast<uint8_t>(abs(control)));
  digitalWrite(pins[1], control>0);
}
