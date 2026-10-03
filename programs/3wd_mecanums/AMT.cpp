#include "AMT.h"

namespace {
  AMT* encoder[3];
  int totalEncoderCount = 0;

  void encoderISR1() { if (encoder[0]) encoder[0]->interruptMethod(); }
  void encoderISR2() { if (encoder[1]) encoder[1]->interruptMethod(); }
  void encoderISR3() { if (encoder[2]) encoder[2]->interruptMethod(); }
}

AMT::AMT(uint8_t dipSwitch, uint8_t* pins)
  : dipSwitch(dipSwitch), pins(pins) {}

void AMT::init() {
  pinMode(pin[2], INPUT);
  pinMode(pin[3], INPUT);

  totalEncoderCount++;
  switch (totalEncoderCount) {
    case 1:
      encoder[0] = this;
      attachInterrupt(digitalPinToInterrupt(pinA), encoderISR1, CHANGE);
      break;
    case 2:
      encoder[1] = this;
      attachInterrupt(digitalPinToInterrupt(pinA), encoderISR2, CHANGE);
      break;
    case 3:
      encoder[2] = this;
      attachInterrupt(digitalPinToInterrupt(pinA), encoderISR3, CHANGE);
      break;
    default:
      Serial.println("Too many encoders");
      break;
  }

  switch (dipSwitch) {
  case 0b0000: ppr = 2048; break;
  case 0b0010: ppr = 1024; break;
  case 0b1000: ppr = 1000; break;
  case 0b0100: ppr =  800; break;
  case 0b0001: ppr =  512; break;
  case 0b1010: ppr =  500; break;
  case 0b0110: ppr =  400; break;
  case 0b1100: ppr =  384; break;
  case 0b0011: ppr =  256; break;
  case 0b1001: ppr =  250; break;
  case 0b0101: ppr =  200; break;
  case 0b1110: ppr =  192; break;
  case 0b1011: ppr =  125; break;
  case 0b0111: ppr =  100; break;
  case 0b1101: ppr =   96; break;
  case 0b1111: ppr =   48; break;
  default:
    Serial.println("Not found number of dip switch.");
    break;
  }


  prevState = (digitalRead(pinA) << 1) | digitalRead(pinB);

  counter = 0;
}

// void AMT::interruptMethod_brief() {
//   // Serial.println("foo");
//   bool a = digitalRead(pinA);
//   bool b = digitalRead(pinB);

//   if (a) {
//     if (b) {
//       counter--;  // 逆回転
//       forward = false;
//     } else {
//       counter++;  // 正回転 
//       forward = true;
//     }
//   }
// }

void AMT::interruptMethod() {
  int currState = (digitalRead(pinA) << 1) | digitalRead(pinB);
  int diff = (currState - prevState);

  if (diff == 1 || diff == -1) {
    counter++; forward = true;
  } else if (diff == 3 || diff == -3) {
    counter--; forward = false;
  }
  prevState = currState;
}

float AMT::getRevolution() {
  // Serial.printf("%d ", counter);
  return counter / (2 * ppr);
}

float AMT::getDegrees() {
  return 180 * counter / ppr;
}
