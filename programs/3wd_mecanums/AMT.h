#ifndef AMT_H
#define AMT_H

#include <Arduino.h>

class AMT {
public:
    AMT(const uint8_t dipSwitch, const uint8_t* pins = nullptr);
    ~AMT() = default;

    void init();
    // void interruptMethod_brief();
    void interruptMethod();
    float getRevolution();
    float getDegrees();
    bool forward;

private:
    const uint8_t dipSwitch;
    const uint8_t* pins;
    float ppr;
    int prevState;
    volatile long counter;
};

#endif