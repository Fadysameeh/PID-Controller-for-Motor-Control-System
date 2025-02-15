#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "main.h"

void setMotor(int dir, int pwmVal) {
    analogWrite(PWM_PIN, pwmVal); 
    if (dir == 1) 
        digitalWrite(DIR_PIN, LOW); 
    else if (dir == -1) 
        digitalWrite(DIR_PIN, HIGH); 
}

void readEncoder1() {
    int b = digitalRead(ENCB); 
    if (b > 0) 
        posi--; 
    else 
        posi++; 
}

void readEncoder2() {
    int b = digitalRead(ENCA); 
    if (b > 0) 
        posi++; 
    else 
        posi--; 
}

void Input(float pos_setpoint, float vel_setpoint) {
    while (!Serial.available()); 
    pos_setpoint = Serial.parseFloat(); 
    Serial.println("Enter Position Set Point: ");
    while (!Serial.available()); 
    pos_setpoint = Serial.parseFloat(); 
    delay(100); 
    if (pos_setpoint > 75) pos_setpoint = 75; 

    while (!Serial.available()); 
    vel_setpoint = Serial.parseFloat(); 
    Serial.println("Enter Velocity Set Point:");
    while (!Serial.available()); 
    vel_setpoint = Serial.parseFloat(); 
    if (vel_setpoint > 63) vel_setpoint = 63; 
}
