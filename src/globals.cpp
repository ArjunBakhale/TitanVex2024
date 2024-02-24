#include "main.h"
pros::ADIDigitalOut wings ('B');
pros::Motor Intake(1, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Slapper(11, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Slapper2(20, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::ADIButton limitSwitch('G');
pros::ADIDigitalOut wings2 ('A');