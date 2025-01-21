#include "main.h"
// TODO: Update globals
// pros::ADIDigitalOut wings ('G');
pros::Motor Intake(15, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
// pros::Motor Slapper(11, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
// pros::Motor Slapper2(9, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
// pros::ADIButton limitSwitch('B');
pros::ADIDigitalOut clampPiston ('H');

pros::Motor LadyBrown(13, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

