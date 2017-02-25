// Arduino  Motor Library v1.1.0 - Control many motors with L293d (single enable).
// https://github.com/sudeeshvs92/Motor
// Copyright 2017 Sudeesh v s
// MIT License



#ifndef Motor_H
#define Motor_H



#if ARDUINO >= 100
    #include "Arduino.h"
#else    
    #include "WProgram.h"
#endif

class Motor {

public:

    // constructor
    Motor(); // empty constructor
    Motor(byte E1,byte I1, byte I2, byte I3, byte I4, int delay,int speed); // full constructor
    void setControlPins(byte I1, byte I2, byte I3, byte I4,byte E1);
    void setDelay(int delay);
    void setSpeed(int speed);

    // movement functions
    void start();
    void moveForward();
    void moveBackward();
    void turnLeft();
    void turnRight();
    void stop();

   

private:

    int mDelay; // delay while switching
    int mSpeed; // PWM motor speed
    // enable pins
    byte mE1;
    // Control Pins
    byte mI1;
    byte mI2;
    byte mI3;
    byte mI4;
};

#endif
