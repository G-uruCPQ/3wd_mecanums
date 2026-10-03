#include "Kinematics.h"
#include "config.h"
#include "mecanums.h"

Kinematics::Kinematics(DCMotor& m1, DCMotor& m2, DCMotor& m3) {
  motor1 = &m1;
  motor2 = &m2;
  motor3 = &m3;
}

void Kinematics::init() {
  motor1->init();
  motor2->init();
  motor3->init();

  switch (ROBOT_NUM) {
    case 1:  matrix = &MECANUM1; break;
    case 2:  matrix = &MECANUM2; break;
    case 3:  matrix = &MECANUM3; break;

    default: matrix = &MECANUM_ZEROS; break;
  }
}

void Kinematics::update(float vx, float vy, float vrot) {

}
