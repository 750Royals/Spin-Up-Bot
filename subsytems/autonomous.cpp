#include "main.h"
#include "pros/rtos.hpp"
#include "subsystemHeaders/autonomous.h"
#include "subsystemHeaders/driver.h"
#include "subsystemHeaders/globals.h"
#include "subsystemHeaders/autonmethods.h"
#include <sys/_intsup.h>


void skills()
{

}

void left_auton()
{
  resetDriveEncoders();
  flywheelOn(11700);
  moveDistance(-9, 500);
  moveRoller(1, 0.25);
  moveDistance(11, 1000);
  turn(-35, 300);
  indexer.move_relative(300, 600);
  flywheelOn(12000);
  pros::delay(550);
  indexer.move_relative(300, 600);
  pros::delay(200);
  moveDistance(-15, 300);
  flywheelOn(9900);
  turn(76, 800);
  pros::delay(100);
  moveDistance(70, 500);
  intakeOn(1);
  moveDistance(16, 400);
  pros::delay(1000);
  moveDistance(16, 400);
  pros::delay(1000);
  moveDistance(20, 400);
  turn(-113, 900);
  moveDistance(12, 800);
  indexer.move_relative(300, 600);
  pros::delay(1500);
  indexer.move_relative(300, 600);
  pros::delay(1500);
  indexer.move_relative(300, 600);
}

void right_auton()
{
}

void test()
{
  resetDriveEncoders();

}
