#include "pid.h"
#include "config.h"

Pid::Pid(const float* k) 
  : kp(k[0]), ki(k[1]), kd(k[2]),
    pErr(0), iErr(0), dErr(0), preErr(0) {}

void Pid::init() {
  integralMax = (ki != 0) ? 255 / ki : 0;
}

int Pid::pid_out(float tagRpm, float nowRpm, float dt) {
  pErr = tagRpm - nowRpm;

  if (tagRpm == 0.0f) {
    iErr = 0;
    preErr = 0;
    return 0;
  }

  iErr += pErr * dt / 1000.0;
  iErr = constrain(iErr, -integralMax, integralMax);

  float dErr = (pErr - preErr) / (dt / 1000.0);
  preErr = pErr;

  if (DEBUG_MODE) {Serial.printf("%f %f %f",pErr,iErr,dErr); Serial.println("");}

  return (int)(kp * pErr + ki * iErr - kd * dErr);
}

// int Pid::debug(){
//   int remeasure=0;
//   for(int i=0;i<10;i++){
//     remeasure=remeasure+pre_measure[i];
//   }
//   return remeasure/10;
// }
