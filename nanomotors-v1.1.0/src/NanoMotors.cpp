#include "Arduino.h"
#include "NanoMotors.h"
NanoMotors::NanoMotors(int d1_pin, int d2_pin, int s1_pin, int s2_pin)
{
  _dir1_pin = d1_pin;
  _dir2_pin = d2_pin;
  __speed1_pin = s1_pin;
  __speed2_pin = s2_pin;
}
void NanoMotors::Nm_setDirection(Direction direction)
{
   if(direction == Direction::Forward)
   {
      digitalWrite(_dir1_pin, HIGH);
	    analogWrite(_speed1_pin, _speed);
      digitalWrite(_dir2_pin, HIGH);
      analogWrite(_speed2_pin, _speed);
   }
   else if(direction == Direction::Backward)
   {
      digitalWrite(_dir1_pin, LOW);
	    analogWrite(_speed1_pin, _speed);
      digitalWrite(_dir1_pin, LOW);
      analogWrite(_speed1_pin, _speed);
   }  
   else if(direction== Direction::Left )
   {
      digitalWrite(_dir2_pin, LOW);
      digitalWrite(_dir1_pin, HIGH);
      analogWrite(_speed1_pin, 0);  
      analogWrite(_speed2_pin, _speed);
   }
   else if(direction== Direction::Right)  
   {
      digitalWrite(_dir2_pin, HIGH);
      digitalWrite(_dir1_pin, LOW);
      analogWrite(_speed1_pin, 0);  
      analogWrite(_speed2_pin,  _speed);
   }
}

void NanoMotors::Nm_setSpeed(int speed)
{
    analogWrite(__speed1_pin, speed);
    analogWrite(__speed2_pin, speed);
		_speed = speed;
}

