#ifndef AMT_H
#define AMT_H

#include <Arduino.h>

class AMT {
public:
    AMT(uint8_t dipSwitch = 0b0000, uint8_t* pins = nullptr);
    ~AMT() = default;

    void init();
    // void interruptMethod_brief();
    void interruptMethod();
    float getRevolution();
    float getDegrees();
    bool forward;

private:
    uint8_t dipSwitch;
    uint8_t* pins;
    float ppr;
    int prevState;
    volatile long counter;
};

#endif