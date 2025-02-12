#include "main.h"
// TODO: Update globals
// pros::ADIDigitalOut wings ('G');
pros::Rotation rotSensor(5); // Using port 2 for rotation sensor
pros::Motor rotationMotor(1, pros::E_MOTOR_GEARSET_18); // Using port 3 with green cartridge (200RPM)
//pros::Optical colorSensor(16); // Using port 1 for color sensor

//PID port = 21


//pros::Motor Intake(1, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor intake_Conveyer(20, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

// pros::Motor Slapper(11, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
// pros::Motor Slapper2(9, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
// pros::ADIButton limitSwitch('B');
pros::ADIDigitalOut clampPiston ('G');
pros::ADIDigitalOut steakArmPiston ('G');

//pros::Motor LadyBrown(14, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

