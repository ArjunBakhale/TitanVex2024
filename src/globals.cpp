#include "main.h"
// TODO: Update globals
// pros::ADIDigitalOut wings ('G');
pros::Motor Intake(15, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor IntakeLow(6, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

// pros::Motor Slapper(11, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
// pros::Motor Slapper2(9, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
// pros::ADIButton limitSwitch('B');
pros::ADIDigitalOut clampPiston ('H');
pros::ADIDigitalOut steakArmPiston ('G');

pros::Motor LadyBrown(14, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

