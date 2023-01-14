#include "main.h"
#include "subsystemHeaders/autonomous.h"
#include "subsystemHeaders/driver.h"
#include "subsystemHeaders/globals.h"
#include "subsystemHeaders/autonmethods.h"


void skills()
{
  resetDriveEncoders();
  moveIntake(1,0.25);
  moveDistance(20);
  turn(90);
  moveDistance(-23);
  moveIntake(1,0.25);
  moveDistance(3);
  turn(-50);
  flywheel.move_voltage(10000);
  moveDistance(72);
  turn(-98);
  moveDistance(12);
  pros::delay(5000);
  moveIntake(-1,0.25);
  pros::delay(3000);
  moveIntake(-1,1.5);
  moveDistance(-12);
  pros::delay(2000);
  moveDistance(-39);
  turn(-135);
  moveDistance(-58);
  turn(-20);
  moveDistance(-6);
  moveIntake(1,0.25);
  moveDistance(19);
  turn(90);
  moveDistance(-28);
  moveIntake(1,0.25);
  turn(-45);
  moveDistance(35);
}

void left_auton()
{
  resetDriveEncoders();
  moveIntake(1,0.50);
  moveDistance(1);
  turn(45);
  flywheel.move_voltage(12000);
  moveDistance(40);
  turn(-72);
  pros::delay(6000);
  moveIntake(-1,0.5);
  pros::delay(4000);
  moveIntake(-1,2);
}

void right_auton()
{
  resetDriveEncoders();
  moveDistance(-25);
  turn(90);
  moveDistance(-7);
  moveIntake(-1,0.25);
}
