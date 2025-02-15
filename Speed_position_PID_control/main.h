#pragma once
#ifndef main_h
#define main_h

#define ENCA 2  
#define ENCB 3   
#define PWM_PIN 5 
#define DIR_PIN 10 
#define LimitSwitch 13

extern volatile int posi;
void setMotor(int dir, int pwmVal);
void readEncoder1();
void readEncoder2();
void Input(float pos_setpoint, float vel_setpoint);

#endif
