#include "main.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;


///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 8, 0, 20, 0);
  /*chassis.set_pid_constants(&chassis.forward_drivePID, 2.5, 0.5, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 2.5, 0.5, 5, 0);*/

  chassis.set_pid_constants(&chassis.forward_drivePID, 0.35, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.35, 0, 5, 0);

  chassis.set_pid_constants(&chassis.turnPID, 7.5, 0.001, 79, 15);
  //chassis.set_pid_constants(&chassis.swingPID, 9, 0.002, 79, 15);
  chassis.set_pid_constants(&chassis.swingPID, 5, 0.002, 79, 15);
}

void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}


void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}




///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches
  chassis.set_drive_pid(60, DRIVE_SPEED);





}
void awayautonplease(){
  



}

void closegame(){

  wings.set_value(true);
  chassis.set_drive_pid(30, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
  chassis.wait_drive(); 
  wings.set_value(false);

  
  chassis.set_drive_pid(-30, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
  chassis.wait_drive(); 

  chassis.set_swing_pid(RIGHT_SWING, -35, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(45, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
  chassis.wait_drive();

  /*
  chassis.set_drive_pid(-5, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
  chassis.wait_drive();

  wings.set_value(true); // Activate the wings
  chassis.wait_drive(); 
  wings.set_value(true); // Activate the wings
  chassis.set_swing_pid(LEFT_SWING, -35, SWING_SPEED);
  chassis.wait_drive(); 
  wings.set_value(false);
  chassis.wait_drive(); 
  wings.set_value(false);

  chassis.set_drive_pid(-57, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
  chassis.wait_drive(); 
  */
}
void fargame(){
  
chassis.set_drive_pid(-20, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
chassis.wait_drive(); 

chassis.set_swing_pid(LEFT_SWING, -30, SWING_SPEED);
chassis.wait_drive(); 

chassis.set_drive_pid(-30, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
chassis.wait_drive(); 

chassis.set_swing_pid(LEFT_SWING, -25, SWING_SPEED);
chassis.wait_drive(); 

chassis.set_drive_pid(-20, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
chassis.wait_drive(); 

chassis.set_drive_pid(10, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
chassis.wait_drive(); 
chassis.set_drive_pid(-20, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
chassis.wait_drive(); 

chassis.set_drive_pid(10, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
chassis.wait_drive(); 
chassis.set_drive_pid(-20, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
chassis.wait_drive(); 

chassis.set_drive_pid(12, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
chassis.wait_drive(); 
chassis.set_drive_pid(-20, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
chassis.wait_drive(); 

chassis.set_drive_pid(15, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
chassis.wait_drive();

wings.set_value(true); // Activate the wings

chassis.set_drive_pid(-20, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
chassis.wait_drive(); 
chassis.set_drive_pid(15, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller

chassis.wait_drive(); 
chassis.set_swing_pid(LEFT_SWING, 10, SWING_SPEED);

chassis.set_drive_pid(-20, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
chassis.wait_drive(); 
chassis.set_drive_pid(15, DRIVE_SPEED, false);



  /*//wings.set_value(true);
  chassis.set_drive_pid(-11, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
  chassis.wait_drive();

  pros::delay(500); // Wait for 1500 millisecond// Wait for the drive PID controller to reach its target
  chassis.wait_drive(); 

  chassis.set_turn_pid(-52.5, TURN_SPEED);
  chassis.wait_drive(); 

  pros::delay(500);
  wings.set_value(true);

  // Wait for the drive PID controller to reach its target
  chassis.set_drive_pid(-45, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
  chassis.wait_drive();
  chassis.set_drive_pid(10, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
  chassis.wait_drive();
  chassis.set_drive_pid(-20, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
  chassis.wait_drive();
  chassis.set_drive_pid(25,DRIVE_SPEED, false);
  chassis.wait_drive();
  wings.set_value(true);
  chassis.wait_drive();
  chassis.set_turn_pid(10, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-30, DRIVE_SPEED, false);
  chassis.wait_drive();
  chassis.set_drive_pid(20, DRIVE_SPEED, false);
  */
}

void inch10dick() {
  //chassis.set_swing_pid(RIGHT_SWING, 90, SWING_SPEED);
  chassis.set_drive_pid(22, DRIVE_SPEED, true);
}
///
//slaves should die!!! ong
// Turn Example
///
void auton_skills() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at

  //shit thats off

  
  chassis.set_drive_pid(18, DRIVE_SPEED, false); // Set the drive PID controller's target to 18 units at DRIVE_SPEED, without resetting the controller
  chassis.wait_drive(); // Wait for the drive PID controller to reach its target

  chassis.set_turn_pid(-60, TURN_SPEED); // Set the turn PID controller's target to -60 degrees at TURN_SPEED
  chassis.wait_drive(); // Wait for the turn PID controller to reach its target

  wings.set_value(true); // Activate the wings

  //chassis.set_max_speed(0); // Set the maximum speed of the chassis to 0

  //Slapper.move_velocity(200); // Set the Slapper's velocity to 200
  //Slapper2.move_velocity(-200); // Set the Slapper2's velocity to 200
  //pros::delay(1000); // Wait for 27000 milliseconds
/*
  while (true) { // Start an infinite loop
    if (limitSwitch.get_value()) // If the limit switch is pressed
    {
      Slapper.move_velocity(0); // Stop the Slapper
      Slapper2.move_velocity(0); // Stop the Slapper2
      break; // Exit the loop
    }
  }
*/
  wings.set_value(false); // Deactivate the wings
  pros::delay(500); // Wait for 500 milliseconds

  // The following lines are similar to the above, but with different targets and speeds for the PID controllers
  chassis.set_turn_pid(178, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(22, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, 135, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(80, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, 95, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(14, DRIVE_SPEED, false);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, 45, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_mode(ez::DISABLE); // Disable the chassis's control mode
  chassis.set_tank(127, 127); // Set the tank drive's left and right speeds to 127
  pros::delay(1500); // Wait for 1500 milliseconds
  chassis.set_tank(0,0); // Stop the tank drive

  // The following lines are similar to the above, but with different targets and speeds for the PID controllers
  chassis.set_drive_pid(-9, DRIVE_SPEED, false);
  chassis.wait_drive();
  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(28, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.set_swing_pid(LEFT_SWING, 128, SWING_SPEED);
  chassis.wait_drive();

  wings.set_value(true); // Activate the wings

  chassis.set_mode(ez::DISABLE); // Disable the chassis's control mode
  chassis.set_tank(127, 127); // Set the tank drive's left and right speeds to 127
  pros::delay(3500); // Wait for 3500 milliseconds
  chassis.set_tank(0,0); // Stop the tank drive

  wings.set_value(false); // Deactivate the wings

  // The following lines are similar to the above, but with different targets and speeds for the PID controllers
  chassis.set_drive_pid(-35, DRIVE_SPEED, false);
  chassis.wait_drive();
  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(42, DRIVE_SPEED, false);
  chassis.wait_drive();
  chassis.set_swing_pid(LEFT_SWING, 180, SWING_SPEED);
  chassis.wait_drive();

  wings.set_value(true); // Activate the wings

  chassis.set_mode(ez::DISABLE); // Disable the chassis's control mode
  chassis.set_tank(127, 127); // Set the tank drive's left and right speeds to 127
  pros::delay(4500); // Wait for 4500 milliseconds



}



///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // wait_until will wait until the robot gets to a desired position


  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_until(-6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();
}



///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive


  chassis.set_swing_pid(ez::LEFT_SWING, 135, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(12);

  chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
  chassis.wait_drive();
}



///
// Auto that tests everything
///
void combining_movements() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Interference example
///
void tug (int attempts) {
  for (int i=0; i<attempts-1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees. 
// If interfered, robot will drive forward and then attempt to drive backwards. 
void interfered_example() {
 chassis.set_drive_pid(24, DRIVE_SPEED, true);
 chassis.wait_drive();

 if (chassis.interfered) {
   tug(3);
   return;
 }

 chassis.set_turn_pid(90, TURN_SPEED);
 chassis.wait_drive();
}



// . . .
// Make your own autonomous functions here!
// . . .