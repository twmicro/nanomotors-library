#include "Arduino.h"
#include "NanoMotors.h"
NanoMotors::NanoMotors(int d1_pin, int d2_pin, int s1_pin, int s2_pin)
{
  d1_pin_P = d1_pin;
  d2_pin_P = d2_pin;
  s1_pin_P = s1_pin;
  s2_pin_P = s2_pin;
}
void NanoMotors::Nm_setDirection(Direction motor1_d, Direction motor2_d)
{
     if(motor1_d == Direction::Forward)
     {
          digitalWrite(d1_pin_P, HIGH);
		  analogWrite(s1_pin_P, speed1_P);
     }
     else if(motor2_d == Direction::Forward)
     {
          digitalWrite(d2_pin_P, HIGH);
          analogWrite(s2_pin_P, speed2_P);
     }  
     else if(motor2_d == Direction::Backward)
     {
          digitalWrite(d1_pin_P, LOW);
		  analogWrite(s1_pin_P, speed1_P);
     }  
     else if(motor2_d == Direction::Backward)
     {
          digitalWrite(d2_pin_P, LOW);
          analogWrite(s2_pin_P, speed2_P);
     }  
     else if(motor1_d== Direction::Left && motor2_d== Direction::Left)
     {
          digitalWrite(d2_pin_P, LOW);
          digitalWrite(d1_pin_P, HIGH);
		  analogWrite(s1_pin_P, 0);  
		  analogWrite(s2_pin_P, speed2_P);
     }
     else if(motor1_d== Direction::Right && motor2_d== Direction::Right)  
     {
          digitalWrite(d2_pin_P, HIGH);
          digitalWrite(d1_pin_P, LOW);
	      analogWrite(s2_pin_P, 0);  
		  analogWrite(s1_pin_P,  speed1_P);
     }
     else
     {
          
     }
}

void NanoMotors::Nm_setSpeed(int motor1_s, int motor2_s)
{
        analogWrite(s1_pin_P, motor1_s);
        analogWrite(s2_pin_P, motor2_s);
		speed1_P = motor1_s;
		speed2_P = motor2_s;
}

