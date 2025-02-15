#include "main.h"

// PID constants 
float kp_v = 3.7; 
float ki_v = 34.48 * 3.7; 
float kp_p = 10; 
int i = 0;

//PID variables 
long start_time = 0; 
volatile int posi = 0; // current position
long prevT = 0; // previous time
float eintegral = 0; // integral error
float pos_setpoint = 0; // target position
float vel_setpoint = 0; // target velocity
float velocity = 0;
double pos = 0;
double pos_error = 0;
double vel_error = 0;
float Pos_ControlSignal = 0;
float Vel_ControlSignal = 0;

void setup() {
    // Encoder
    pinMode(ENCA, INPUT_PULLUP); 
    pinMode(ENCB, INPUT_PULLUP); 
    // Motor
    pinMode(PWM_PIN, OUTPUT); 
    pinMode(DIR_PIN, OUTPUT); 
    // Interrupts
    attachInterrupt(digitalPinToInterrupt(ENCA), readEncoder1, RISING); 
    attachInterrupt(digitalPinToInterrupt(ENCB), readEncoder2, RISING); 
    
    while (digitalRead(LimitSwitch) == LOW) setMotor(-1, 200); 
    setMotor(1, 255); 
    delay(60); 
    analogWrite(PWM_PIN, 0); 
    posi = 0; 
    
    Serial.begin(9600); 
    Serial.println("Enter Position Set Point: "); 
    while (!Serial.available()); 
    pos_setpoint = Serial.parseFloat(); 
    if (pos_setpoint > 80) pos_setpoint = 80; 
    while (pos_setpoint < 0) {
        while (!Serial.available()); 
        pos_setpoint = Serial.parseFloat(); 
        Serial.println("Enter a positive Position Set Point: "); 
        while (!Serial.available()); 
        pos_setpoint = Serial.parseFloat(); 
        if (pos_setpoint > 80) pos_setpoint = 80;
    }
    while (!Serial.available()); 
    vel_setpoint = fabs(Serial.parseFloat()); 
    Serial.println("Enter Velocity Set Point:"); 
    while (!Serial.available()); 
    vel_setpoint = fabs(Serial.parseFloat()); 
    if (vel_setpoint > 63) vel_setpoint = 63; 
    start_time = millis(); 
    prevT = micros(); 
}

void loop() {
    if (i < 1) 
        pos_error = fabs(pos_setpoint - pos); 
    if (millis() - start_time < (pos_error / vel_setpoint) * 1000 + 500) {
        // time difference
        long currT = micros(); 
        float deltaT = ((float)(currT - prevT)) / (1.0e6); 
        prevT = currT; 
        
        // Read position and velocity
        noInterrupts();  
        velocity = ((posi / 102.313892) - pos) / deltaT; 
        pos = (double(posi) / 102.313892);   
        interrupts(); 

        // Position Control Signal 
        Pos_ControlSignal = (pos_setpoint - pos) * kp_p; 

        // Saturation of the control signal with target velocity
        if (fabs(Pos_ControlSignal) > vel_setpoint) {
            if (Pos_ControlSignal >= 0) 
                Pos_ControlSignal = vel_setpoint; 
            else 
                Pos_ControlSignal = -vel_setpoint;
        }
        
        vel_error = Pos_ControlSignal - velocity; 
        eintegral = eintegral + vel_error * deltaT; 
        Vel_ControlSignal = kp_v * vel_error + ki_v * eintegral;

        int dir = 1; 
        if (Vel_ControlSignal < 0) dir = -1; 
        
        // Motor power
        float pwr = fabs(Vel_ControlSignal); 
        if (pwr >= 255) pwr = 255; 
        
        setMotor(dir, pwr); 
        i++; 
        
        if (i > 1) {
            Serial.print(velocity); 
            Serial.print("   "); 
            Serial.print(pos); 
            Serial.println(); 
        }
    } else {
        setMotor(0, 0); 
        while (!Serial.available()); 
        pos_setpoint = Serial.parseFloat(); 
        Serial.println("Enter Position Set Point: ");
        while (!Serial.available()); 
        pos_setpoint = Serial.parseFloat(); 
        if (pos_setpoint > 80) pos_setpoint = 80; 
        while (pos_setpoint < 0) {
            while (!Serial.available()); 
            pos_setpoint = Serial.parseFloat(); 
            Serial.println("Enter a positive Position Set Point: "); 
            while (!Serial.available()); 
            pos_setpoint = Serial.parseFloat(); 
            if (pos_setpoint > 80) pos_setpoint = 80;
        }

        while (!Serial.available()); 
        vel_setpoint = fabs(Serial.parseFloat()); 
        Serial.println("Enter Velocity Set Point:"); 
        while (!Serial.available()); 
        vel_setpoint = fabs(Serial.parseFloat()); 
        if (vel_setpoint > 63) vel_setpoint = 63; 
        i = 0; 
        eintegral = 0; 
        start_time = millis(); 
        prevT = micros(); 
    }
}
