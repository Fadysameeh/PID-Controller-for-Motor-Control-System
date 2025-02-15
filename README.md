# PID-Controller-for-Motor-Control-System

Overview
This project implements a PID Controller (Proportional-Integral-Derivative) to control the movement of a linear actuator in an electromechanical system. The PID controller is used to control both the position and velocity of the actuator through feedback loops, ensuring minimal error between the desired setpoints and the actual measured positions and velocities.

Key Features
PID Control: Uses Proportional (Kp), Integral (Ki), and Derivative (Kd) parameters to regulate position and velocity.
Cascade Control Loop: Implements a cascade PID control strategy with three loops:
Inner Loop (Velocity Control): Uses PI controller to manage the velocity of the system.
Outer Loop (Position Control): Uses a P controller for position control based on the setpoint.
Anti-Wind-Up: Prevents the controller from continuing to accumulate error during saturation.
Encoder Feedback: Uses encoder feedback for precise positioning and velocity control.
Manual Tuning: The system allows for the manual tuning of PID parameters for different setpoints to achieve optimal control.
Real-Time Control: The system runs in real-time, with time-based calculations to adjust motor input and avoid idle time.
Project Objective
Setpoint Control: The goal is to move the actuator to a specified position and achieve a desired velocity with minimal error using the PID controller.
Parameter Estimation: The PID constants (Kp, Ki, Kd) are calculated and tuned to ensure smooth and accurate movement of the system.
System Design
The system consists of a motor connected to a linear actuator and controlled by PWM signals. The motor's movement is adjusted based on feedback from the encoder, which measures the position of the actuator.
The PID controller receives setpoints for both position and velocity, and continuously adjusts the motor's control signal to bring the system closer to the target setpoint.
Usage
Position Setpoint: User inputs the desired position setpoint.
Velocity Setpoint: User inputs the desired velocity.
The PID controller adjusts the motor's power and direction accordingly, based on the current error in position and velocity.
Applications
Automation Systems: Ideal for systems requiring precise control of position and velocity, such as robotics and motion control.
Industrial Applications: Used for controlling actuators and motors in industrial machinery.
Engineering and Research: Provides an excellent learning platform for understanding and applying PID control in electromechanical systems.
Technologies Used
C++ Programming: Core logic implemented in C++.
Arduino Platform: Used for hardware interfacing, including motor control and encoder reading.
PID Control Algorithms: Fundamental control theory for regulating position and velocity.
