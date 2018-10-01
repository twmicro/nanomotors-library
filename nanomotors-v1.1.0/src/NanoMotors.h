#ifndef NanoMotors_h
#define NanoMotors_h
#include "Arduino.h"
class NanoMotors
{
    private:
     int _dir1_pin;
     int _dir2_pin;
     int _speed1_pin;
     int _speed2_pin;
	 int _speed;
    public:
     NanoMotors(int d1_pin, int d2_pin, int s1_pin, int s2_pin);
     enum Direction
     {
        Forward = 1,
        Backward = 0,
        Left = 2,
        Right = 3
     };
     void Nm_setDirection(Direction direction);
     void Nm_setSpeed(int speed);
};
#endif


