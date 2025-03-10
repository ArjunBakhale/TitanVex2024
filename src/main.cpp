#include "main.h"
#include <iostream>
// Chassis constructor
Drive chassis (
  //TODO: Add the left ports
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {15, 12, 13} //LEFT PORTR NUM GOES AFDTER COMMAN

  //TODO: Add the right ports
  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  ,{-11, -14, -19}

  // IMU Port
  // TODO: Add the IMU port
  ,21

  // Wheel Diameter (Remember, 4" wheels are actually 4.125!)

  ,2.75

  // Cartridge RPM
  //   (or tick per rotation if using tracking wheels)
  ,600

  // External Gear Ratio (MUST BE DECIMAL)
  //    (or gear ratio of tracking wheel)
  // eg. if your drive is 84:36 where the 36t is powered, your RATIO would be 2.333.
  // eg. if your drive is 36:60 where the 60t is powered, your RATIO would be 0.6.
  ,1.0


  // Uncomment if using tracking wheels
  
  /*
  // Left Tracking Wheel Ports (negative port will reverse it!)
  // ,{1, 2} // 3 wire encoder
  // ,8 // Rotation sensor

  // Right Tracking Wheel Ports (negative port will reverse it!)
  // ,{-3, -4} // 3 wire encoder
  // ,-9 // Rotation sensor
  */

  // Uncomment if tracking wheels are plugged into a 3 wire expander
  // 3 Wire Port Expander Smart Port
  // ,1
);



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  // Print our branding over your terminal :D
  ez::print_ez_template();
  
  pros::delay(100); // Stop the user from doing anything while legacy ports configure.

  // Configure your chassis controls
  chassis.toggle_modify_curve_with_controller(true); // Enables modifying the controller curve with buttons on the joysticks
  chassis.set_active_brake(0.1); // Sets the active brake kP. We recommend 0.1.
  chassis.set_curve_default(3, 0); // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)  
  default_constants(); // Set the drive to your own constants from autons.cpp!
  

  // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
  // chassis.set_left_curve_buttons (pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT); // If using tank, only the left side is used. 
  // chassis.set_right_curve_buttons(pros::E_CONTROLLER_DIGITAL_Y,    pros::E_CONTROLLER_DIGITAL_A);

  // Autonomous Selector using LLEMU
  ez::as::auton_selector.add_autons({
    //choices: auton_skills inch10dick closegame     .

    // 2025 Titan Autons
    /*Auton("Match auton", match_auton),
    Auton("Skills", auton_skills),*/

    // Auton("Example Turn\n\nTurn 3 times.", drive_example),
    // Auton("Drive and Turn\n\nDrive forward, turn, come back. ", drive_and_turn),
    // Auton("Drive and Turn\n\nSlow down during drive.", wait_until_change_speed),
    // Auton("Swing Example\n\nSwing, drive, swing.", swing_example),
    // Auton("Combine all 3 movements", combining_movements),
    // Auton("Interference\n\nAfter driving forward, robot performs differently if interfered or not.", interfered_example),
  });

  // Initialize chassis and auton selector
  chassis.initialize();
  ez::as::initialize();
}



/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  // . . .
}



/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  
  // . . .
}



/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  chassis.reset_pid_targets(); // Resets PID targets to 0
  chassis.reset_gyro(); // Reset gyro position to 0
  chassis.reset_drive_sensor(); // Reset drive sensors to 0
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD); // Set motors to hold.  This helps autonomous consistency.
  
  //this makes the whole thing backwards chat
  //---------------------------------------
  //chassis.setReversed(true);

  ez::as::auton_selector.call_selected_auton(); // Calls selected auton from autonomous selector.
}



/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

//fully extended angle: 4.04 degrees
//intake_ready angle: 214.8 degrees
//rest angle: 264.78 degrees

/*
void moveToAngle(const double targetAngle) {
  const int THRESHOLD = 150; // Tighter threshold (1.5 degrees)
  const int APPROACH_THRESHOLD = 250; // Start precise control within 2 degrees
  const int FAST_VELOCITY = 15;
  const int MIN_VELOCITY = 5; // Minimum velocity for precise control

  while (true) {
    double currentAngle = rotSensor.get_angle() * 100;
    double error = targetAngle - currentAngle;

    if (std::abs(error) <= THRESHOLD) {
      rotationMotor.move_velocity(0);
      rotationMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE); 
      break;
    }

    // Calculate velocity based on error (proportional control)
    int velocity = std::abs(error) <= APPROACH_THRESHOLD ? 
      std::max(MIN_VELOCITY, (int)(std::abs(error) * 0.5)) : FAST_VELOCITY;

    rotationMotor.move_velocity(error <  0 ? -velocity : velocity);
    pros::delay(10); // Faster control loop
  }
  pros::delay(50);
}*/

/*
void moveToAngle(const double targetAngle) {
  const int THRESHOLD = 25;
  const int APPROACH_THRESHOLD = 50; 
  const int FAST_VELOCITY = 100;
  const int MIN_VELOCITY = 25;

  while (true) {
    double currentAngle = rotSensor.get_angle();
    double error = targetAngle - currentAngle;

    if (std::abs(error) <= THRESHOLD) {
      rotationMotor.move_velocity(0);
      rotationMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE); // Use BRAKE mode to hold position
      break;
    }

    int brown_velocity = std::abs(error) <= APPROACH_THRESHOLD ? 
      std::max(MIN_VELOCITY, (int)(std::abs(error) * 0.5)) : FAST_VELOCITY;

    // Inverted direction logic
    if (error > 0) {
      rotationMotor.move_velocity(-brown_velocity); // Move forward
    } else {
      rotationMotor.move_velocity(brown_velocity); // Move backward
    }
    
    pros::delay(10);
  }
  pros::delay(50);
}
*/

void moveToAngle(double targetAngle){
  const int threshold = 250;
  const int fastVelocity = 100;
  const int slowVelocity = 100;
  const int slowDistance = 50; // Distance to start slowing down

  while (true) {
    double currentAngle = rotSensor.get_angle();
    double error = targetAngle - currentAngle;

    if (std::abs(error) <= threshold) {
      rotationMotor.move_velocity(0);
      rotationMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); // Use BRAKE mode to hold position
      break;
    }

    int velocity = std::abs(error) <= slowDistance ? 
      std::max(slowVelocity, (int)(std::abs(error) * 0.5)) : fastVelocity;

    // Inverted direction logic
    if (error > 0) {
      rotationMotor.move_velocity(velocity); // Move forward
    } else {
      rotationMotor.move_velocity(-velocity); // Move backward
    }
    
    pros::delay(10);
  }
}


bool toggle1 = false;
bool latch1 = false;
bool toggle2 = false;
bool latch2 = false;
bool intakeSpin = false;
bool intake_toggle = false;
bool drive_inverse = false;
bool clamp_toggle = false;
bool steak_arm_toggle = false;
bool outake_toggle = false;

void opcontrol() {

  // This is preference to what you like to drive on.
  chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  while (true) {

    chassis.tank(); // Tank control
    /*
      cout << rotSensor.get_angle();
      cout << "\n ";
    */
    
    
    if (master.get_digital_new_press(DIGITAL_LEFT)) {
      moveToAngle(1500);
    } 

    else if (master.get_digital_new_press(DIGITAL_UP)) {
      moveToAngle(3300);
    }
    else if(master.get_digital_new_press(DIGITAL_RIGHT)){
      moveToAngle(15000);
    }
    /*
    else{
      rotationMotor.move_velocity(0);
      rotationMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE); // Hold position
    }*/
    

   /*
    if (master.get_digital_new_press(DIGITAL_LEFT)) {
      rotationMotor.move_absolute(0, 15);
    } 

    else if (master.get_digital_new_press(DIGITAL_UP)) {
      rotationMotor.move_absolute(65, 15);
    }
    else if(master.get_digital_new_press(DIGITAL_RIGHT)){
      rotationMotor.move_absolute(115, 15);
    }
    else{
      rotationMotor.move_velocity(0);
      rotationMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); // Hold position
    }
    */


    if (master.get_digital_new_press(DIGITAL_A)) {
      clamp_toggle = !clamp_toggle;
      clampPiston.set_value(clamp_toggle);
    }

    if (master.get_digital_new_press(DIGITAL_Y)) {
      steak_arm_toggle = !steak_arm_toggle;
      steakArmPiston.set_value(steak_arm_toggle);
    }

    // chassis.arcade_standard(ez::SPLIT); // Standard split arcade
    // chassis.arcade_standard(ez::SINGLE); // Standard single arcade
    // chassis.arcade_flipped(ez::SPLIT); // Flipped split arcade
    // chassis.arcade_flipped(ez::SINGLE); // Flipped single arcade

    // . . .
    // Put more user control code here!
    // . . .
    if (master.get_digital_new_press(DIGITAL_R1)) {
      intake_toggle = !intake_toggle;
      outake_toggle = false;
    }
    if(master.get_digital_new_press(DIGITAL_R2)){
      outake_toggle = !outake_toggle;
      intake_toggle = false;
    }
    

    // if (master.get_digital(DIGITAL_R2)) {
    //     Intake.move_velocity(-200);  // Reverse
    // } 
    if (intake_toggle && !outake_toggle) {
    	//Intake.move_velocity(-200);   // intake (Negative intakes inwards)
    	intake_Conveyer.move_velocity(200);
	  } else if (outake_toggle && !intake_toggle) {
    	//Intake.move_velocity(200); 	// Outake (Positive outtakes outwards)
    	intake_Conveyer.move_velocity(-200);
    }
      else {
        //Intake.move_velocity(0);
        intake_Conveyer.move_velocity(0);
      }


      /*
    if(outake_toggle){
      Intake.move_velocity(200);
      intake_Conveyer.move_velocity(-200);
    }
    else if(!intake_toggle && !outake_toggle){
      Intake.move_velocity(0);
      intake_Conveyer.move_velocity(0);
    }*/

    //manual lady brown 
    /*
    // Replace existing if statement with:
    if(master.get_digital(DIGITAL_L1)) {
        // Move up while held
        LadyBrown.move_velocity(200);  // 8V for up movement
    }     else if(master.get_digital(DIGITAL_L2)) {
        // Move down while held
        LadyBrown.move_velocity(-200); // 5V for down movement
    }
    else {
        // Hold position when no input
        LadyBrown.move_voltage(0);
        LadyBrown.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }

  */


    // else if(master.get_digital(DIGITAL_RIGHT)) {
    //     // Move down while held
    //     LadyBrown.move_velocity(-200); // 5V for down movement
    // }
    /*
    else {
        // Hold position when no input
        LadyBrown.move_voltage(0);
        LadyBrown.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }*/

    pros::delay(20);

    /*if (master.get_digital(DIGITAL_L2)) {
      if (!latch1)
      {
        toggle1 = !toggle1;
        latch1 = true;
      }
    }
    else
    {
      latch1 = false;
    }*/
    
    // if (toggle2) {
    //   Slapper.move_velocity(110);
    //   Slapper2.move_velocity(-110);
    // }
    // else 
    // {
    //   Slapper.move_velocity(0);
    //   Slapper2.move_velocity(0);
    // }

    // if (master.get_digital_new_press(DIGITAL_DOWN)){
    //   drive_inverse = !drive_inverse;
    //   //chassis.set_drive_inverse(drive_inverse);
    // }

    // if (master.get_digital(DIGITAL_UP)) {
    //   if (!latch2)
    //   {
    //     toggle2 = !toggle2;
    //     latch2 = true;
    //   }
    // }
    // else
    // {
    //   latch2 = false;
    // }
    // /*if (master.get_digital(DIGITAL_B))
    // {
    //   wings.set_value(true);
    // }
    // if (master.get_digital(DIGITAL_A))
    // {
    //   wings.set_value(false);
    // }*/
    // /*bool isPressed = master.get_digital_new_press(DIGITAL_A);

    // if (isPressed && pneumatic_value % 2 == 0) {
    //   wings.set_value(true);
    //   pneumatic_value++;
    // }s
    // else if(isPressed && pneumatic_value % 2 == 1){
    //   wings.set_value(false);
    //   pneumatic_value++;
    // }*/
    // if (master.get_digital_new_press(DIGITAL_A)) {
    //   // Inverts the wings state. e.g. if currently true this will invert it to false.
    //   wing_toggle = !wing_toggle;
    //   wings.set_value(wing_toggle);
    

    
    //   wing2_toggle = !wing2_toggle;
    //   wings2.set_value(wing2_toggle);
    // }


    // pros::delay(ez::util::DELAY_TIME); // This is used for timer calculations!  Keep this ez::util::DELAY_TIME

  }

}
