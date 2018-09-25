#ifndef NanoMotors_h
#define NanoMotors_h
#include "Arduino.h"
class NanoMotors
{
    private:
     int d1_pin_P;
     int d2_pin_P;
     int s1_pin_P;
     int s2_pin_P;
	 int speed1_P;
	 int speed2_P;
    public:
     NanoMotors(int d1_pin, int d2_pin, int s1_pin, int s2_pin);
     enum Direction
     {
        Forward = 1,
        Backward = 0,
        Left = 2,
        Right = 3
     };
     void Nm_setDirection(Direction motor1_d, Direction motor2_d);
     void Nm_setSpeed(int motor1_s, int motor2_s);
};
#endif


