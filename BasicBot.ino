
#include <Motor.h>

Motor bot;

void setup() {

   
    
    bot.setControlPins(0, 1, 2, 3,4);
    bot.setDelay(20);
    bot.stop();
    delay(2000);
}

void loop() {
    bot.setSpeed(250);
    bot.setDelay(20);
  bot.moveForward();
  delay(2000);
    bot.turnLeft();
     delay(2000);
     
     bot.turnRight();
     delay(2000);
     bot.setSpeed(150);
   
}
