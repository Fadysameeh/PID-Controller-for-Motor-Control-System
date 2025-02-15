#PID Controller for Motor Control System

Overview
This project implements a PID Controller (Proportional-Integral-Derivative) to control the movement of a linear actuator in an electromechanical system. The PID controller is used to regulate both position and velocity through feedback loops, ensuring minimal error between the desired setpoints and the actual measured positions and velocities.
Key Features
•	PID Control: Uses Proportional (Kp), Integral (Ki), and Derivative (Kd) parameters to regulate position and velocity.
•	Cascade Control Loop: Implements a cascade PID control strategy with three loops:
o	Inner Loop (Velocity Control): Uses a PI controller to manage the velocity of the system.
o	Outer Loop (Position Control): Uses a P controller for position control based on the setpoint.
•	Anti-Wind-Up: Prevents the controller from continuing to accumulate error during saturation.
•	Encoder Feedback: Uses encoder feedback for precise positioning and velocity control.
•	Manual Tuning: Allows manual tuning of PID parameters for different setpoints to achieve optimal control.
•	Real-Time Control: Operates in real-time, adjusting motor input and avoiding idle time.
Objective
•	Setpoint Control: Move the actuator to a specific position and achieve the desired velocity with minimal error using PID control.
•	Parameter Estimation: Calculate and tune the PID constants (Kp, Ki, Kd) to ensure smooth and accurate movement of the system.
System Design
The system consists of:
•	A motor connected to a linear actuator controlled by PWM signals.
•	Encoder feedback to monitor and adjust the actuator's position.
•	A PID controller that continuously adjusts the motor’s control signal to reduce error between the target and actual position/velocity.
How It Works
1.	Position Setpoint: The user inputs the desired position setpoint.
2.	Velocity Setpoint: The user inputs the desired velocity.
3.	The PID controller adjusts the motor’s power and direction based on the feedback from the encoder, ensuring the system reaches the target position and velocity.
Applications
•	Automation Systems: For controlling motors and actuators in robotics and manufacturing systems.
•	Industrial Applications: Precision control of motors and actuators in machinery.
•	Educational Use: Learn and apply PID control algorithms in real-time systems.
Technologies Used
•	C++ Programming: Core control logic.
•	Arduino Platform: Hardware interface for motor control and encoder reading.
•	PID Control Algorithms: Fundamental control theory for managing position and velocity.

