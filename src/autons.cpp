#include "main.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 0.75*75; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;


///
// Constants
///
//kP is 15 and the kD is 300
/*
notes: 
do the turn first
find a good Kp AND THEN A GOOD kD for turn
then do heading: adjust kP until it barely veers into a certain direction and then stop: it hsoul look look undesireable before we mess with kD
s*/
// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  /*chassis.set_pid_constants(&chassis.forward_drivePID, 2.5, 0.5, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 2.5, 0.5, 5, 0);*/

//untuned
  
  //chassis.set_pid_constants(&chassis.forward_drivePID, 25, 0, 0, 0);


  // chassis.set_pid_constants(&chassis.backward_drivePID, 0.35, 0, 5, 0);
  //chassis.set_pid_constants(&chassis.headingPID, 8, 0, 20, 0);
  // chassis.set_pid_constants(&chassis.turnPID, 7.5, 0.001, 79, 15);
  // chassis.set_pid_constants(&chassis.swingPID, 5, 0.002, 79, 15);

  //chassis.set_pid_constants(&chassis.forward_drivePID,
  //chassis.set_pid_constants(&chassis.backward_drivePID, 0, 0, 10, 0);
  //tuned
  chassis.set_pid_constants(&chassis.turnPID, 5, 0, 50, 15);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);

}

// void one_mogo_constants() {
//   chassis.set_slew_min_power(80, 80);
//   chassis.set_slew_distance(7, 7);
//   chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
//   chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
//   chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
//   chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
//   chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
// }

// void two_mogo_constants() {
//   chassis.set_slew_min_power(80, 80);
//   chassis.set_slew_distance(7, 7);
//   chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
//   chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
//   chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
//   chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
//   chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
// }


// void modified_exit_condition() {
//   chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
//   chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
//   chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
// }

void wallAuton() {

    clampPiston.set_value(false);
    chassis.set_drive_pid(-24, DRIVE_SPEED, true); //back 24
    chassis.wait_drive();
    chassis.set_turn_pid(90, TURN_SPEED); //turn right 90
    chassis.wait_drive();
    chassis.set_drive_pid(-18, DRIVE_SPEED, true); //back 18
    chassis.wait_drive();
    Intake.move_velocity(-200); //start intake
    pros::delay(1500); 
    Intake.move_velocity(0);
    chassis.set_drive_pid(18, DRIVE_SPEED, true); //forward 18
    chassis.wait_drive();
    chassis.set_turn_pid(45, TURN_SPEED); //turn left 45
    chassis.wait_drive();
    chassis.set_drive_pid(60, DRIVE_SPEED, true); //forward 18
    chassis.wait_drive();
    Intake.move_velocity(0); //stop intake
    chassis.set_turn_pid(-45, TURN_SPEED); //turn left 45
    chassis.wait_drive();
    chassis.set_drive_pid(-24, DRIVE_SPEED, true); //back 24
    chassis.wait_drive();
    clampPiston.set_value(true);
    Intake.move_velocity(-200); //start intake
    chassis.set_drive_pid(20, DRIVE_SPEED, true); //forward 20
    chassis.wait_drive();
    chassis.set_turn_pid(90, TURN_SPEED); //turn right 90
    chassis.wait_drive();
    chassis.set_drive_pid(18, DRIVE_SPEED, true); //forward 18
    chassis.wait_drive();
    chassis.set_turn_pid(90, TURN_SPEED); //turn right 90;
    chassis.wait_drive();
    chassis.set_drive_pid(24, DRIVE_SPEED, true); //forward 24
    chassis.wait_drive();
}

void driveAuton() {
  chassis.set_drive_pid(10, DRIVE_SPEED, true); //forward 10
}

void pid_tune() {

  driveAuton();
  wallAuton();

}
