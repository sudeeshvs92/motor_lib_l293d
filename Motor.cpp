
// Arduino  Motor Library v1.1.0 - Control many motors with L293d (single enable).
// https://github.com/sudeeshvs92/Motor
// Copyright 2017 Sudeesh v s
// MIT License

#include "Motor.h"

/**
 * Full Constructor
 */
Motor::Motor(byte E1,byte I1, byte I2, byte I3, byte I4, int delay,int speed) {
    
    setControlPins(I1, I2, I3, I4,E1);
    setDelay(delay);
    setSpeed(speed);
}

/**
 * Default Constructor
 */
Motor::Motor() {
   
    
}


/**
 * Set Control pins
 */
void Motor::setControlPins(byte I1, byte I2, byte I3, byte I4,byte E1) {
    mI1 = I1;
    mI2 = I2;
    mI3 = I3;
    mI4 = I4;
    mE1 = E1;
   
    //pinMode(mE1, OUTPUT);
    pinMode(mI1, OUTPUT);
    pinMode(mI2, OUTPUT);
    pinMode(mI3, OUTPUT);
    pinMode(mI4, OUTPUT);
}

/**
 * Set delay value
 */
void Motor::setDelay(int delay) {
    mDelay = delay;
}

/**
 * Set PWM Speed
 */
void Motor::setSpeed(int speed) {

if(speed > -1 && speed < 256) {
     
     
      if(mSpeed != speed) {
        mSpeed = speed;
         analogWrite(mE1,mSpeed);
      }
    }
 
}

/**
 * Start the bot and move forward
 */
void Motor::start() {
    setSpeed(255);
    moveForward();
    delay(mDelay);
}

/**
 * Move forward
 */
void Motor::moveForward() {
    
    digitalWrite(mI1, HIGH);
    digitalWrite(mI2, LOW);
    digitalWrite(mI3, HIGH);
    digitalWrite(mI4, LOW);
    delay(mDelay);
    
     
}

/**
 * Move backward
 */
void Motor::moveBackward() {
    

    digitalWrite(mI1, LOW);
    digitalWrite(mI2, HIGH);
    digitalWrite(mI3, LOW);
    digitalWrite(mI4, HIGH);
    delay(mDelay);

}

/**
 * Turn Left
 */
void Motor::turnLeft() {
    
    digitalWrite(mI1, HIGH);
    digitalWrite(mI2, LOW);
    digitalWrite(mI3, LOW);
    digitalWrite(mI4, HIGH);
    delay(mDelay);

    
    

}

/**
 * Turn Right
 */
void Motor::turnRight() {
   
    digitalWrite(mI1, LOW);
    digitalWrite(mI2, HIGH);
    digitalWrite(mI3, HIGH);
    digitalWrite(mI4, LOW);
    delay(mDelay);

}

/**
 * Stop Bot
 */
void Motor::stop() {
    setSpeed(0);
    digitalWrite(mI1, LOW);
    digitalWrite(mI2, LOW);
    digitalWrite(mI3, LOW);
    digitalWrite(mI4, LOW);
   
}


