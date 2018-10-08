#include <Arduino.h>
#include <NanoMotors.h>
#include <NewPing.h>

// Переменные пинов
int LeftSensor = 8;
int MiddleSensor = 7;
int RightSensor = 6;
int Trig = 3;
int Echo = 5;
// Объекты управления
NanoMotors M_control(11, 12, 9, 10);
NewPing U_control(Trig, Echo, 400);
void setup() {
    Serial.begin(9600);
    pinMode(3, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);    
    pinMode(11, OUTPUT);    
    pinMode(12, OUTPUT);
	pinMode(Trig, OUTPUT);
	pinMode(Echo, INPUT);
    M_control.Nm_setSpeed(255); // Скорость моторов
    // Если вы проверяете работоспособность порта, раскомментируйте:
    // Serial.println("Serial Test");
}

void loop() {
    int MotionTimeout = 200;
    int Distance = U_control.ping_cm(); // Получаем растояние до ближайшего препятствия
    // Снимаем показания с датчиков
    int LeftValue = !digitalRead(LeftSensor);
    int MiddleValue = !digitalRead(MiddleSensor);
    int RightValue = !digitalRead(RightSensor);
    // Показания (в 75% случаев они правильные):
    Serial.print("L:");
    Serial.println(LeftValue);
    Serial.print("M:");
    Serial.println(MiddleValue);
    Serial.print("R:");
    Serial.println(RightValue);
    int MinDistance = 10; // Минимальная дистанция
    if(Distance >= MinDistance)
    {
        if(LeftValue == 0 && MiddleValue == 1 && RightValue == 0) M_control.Nm_setDirection(NanoMotors::Direction::Forward); 
        else if(LeftValue == 1 && MiddleValue == 0 && RightValue == 0) M_control.Nm_setDirection(NanoMotors::Direction::Left);
        else if(LeftValue == 0 && MiddleValue == 0 && RightValue == 1) M_control.Nm_setDirection(NanoMotors::Direction::Right);
        else if(LeftValue == 1 && MiddleValue == 1 && RightValue == 0) M_control.Nm_setDirection(NanoMotors::Direction::Left);
        else if(LeftValue == 0 && MiddleValue == 0 && RightValue == 1) M_control.Nm_setDirection(NanoMotors::Direction::Right);
        else if(LeftValue == 1 && MiddleValue == 1 && RightValue == 1)
        { 
            Serial.println("Everything on black");
            M_control.Nm_setDirection(NanoMotors::Direction::Left);
            delay(MotionTimeout);
        }
        else
        {
            Serial.println("Everything on white!");
            while(digitalRead(MiddleSensor) != HIGH)
            { 
                if(Distance >= MinDistance)
                {
                    if(digitalRead(RightSensor) == HIGH) M_control.Nm_setDirection(NanoMotors::Direction::Right);
                    else if(digitalRead(LeftSensor) == HIGH) M_control.Nm_setDirection(NanoMotors::Direction::Left);
                    else
                    {
                        M_control.Nm_setDirection(NanoMotors::Direction::Left);
                        delay(MotionTimeout);
                        M_control.Nm_setDirection(NanoMotors::Direction::Backward);
                        delay(500);
                    }
                    delay(MotionTimeout);
                }
                else
                {
                    M_control.Nm_setDirection(NanoMotors::Direction::Backward);
                    delay(1000);
                }
            }
            M_control.Nm_setDirection(NanoMotors::Direction::Left);
            delay(MotionTimeout);

        }
    }
    else
    {
       M_control.Nm_setDirection(NanoMotors::Direction::Right);
    }
    // Test Delay:
    // delay(500);

}