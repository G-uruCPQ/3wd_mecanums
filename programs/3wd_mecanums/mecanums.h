#ifndef MECANUMS_H
#define MECANUMS_H

#include "config.h"

const float MECANUM1[3][3] = {
  {-0.5f,  .866f, 1.0f},  // M1: 右前（+60°）→ (-1/2,  √3/2, r)
  { 1.0f,  .0f,   1.0f},  // M2: 後方（180°）→ ( 1  ,  0   , r)
  {-0.5f, -.866f, 1.0f}   // M3: 左前（-60°）→ (-1/2, -√3/2, r)
};

const float MECANUM2[3][3] = {
  {.0, .0, .0},
  {.0, .0, .0},
  {.0, .0, .0}
};

const float MECANUM3[3][3] = {
  {.0, .0, .0},
  {.0, .0, .0},
  {.0, .0, .0}
};

const float MECANUM_ZEROS[3][3] = {
  {.0, .0, .0},
  {.0, .0, .0},
  {.0, .0, .0}
};

#endif