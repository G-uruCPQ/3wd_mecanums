#ifndef PID_H
#define PID_H

#include <Arduino.h>

class Pid{
  public:
    Pid(float* k = nullptr);
    ~Pid() = default;

    void init();
    int pid_out(float tagRpm, float nowRpm, float dt);
    // int debug();

  private:
    float* k;
    float pErr, iErr, dErr;
    float preErr;
    float integralMax;
};

#endif
