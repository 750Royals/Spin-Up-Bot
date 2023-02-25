#include "main.h"
#include "pros/rtos.hpp"
#include "subsystemHeaders/autonomous.h"
#include "subsystemHeaders/driver.h"
#include "subsystemHeaders/globals.h"
#include "subsystemHeaders/autonmethods.h"
#include <sys/_intsup.h>


void skills()
{
  resetDriveEncoders();
}

void left_auton()
{
  flywheelOn(11900);
  resetDriveEncoders();
  moveDistance(-5);
  moveRoller(1, 0.1);
  /*moveDistance(10);
  intakeOn(1);
  pros::delay(500);
  indexer.move_relative(400, 600);
  pros::delay(500);
  indexer.move_relative(400, 600);
  pros::delay(700);
  indexer.move_relative(800, 600);*/
}

void right_auton()
{
  flywheelOn(11900);
  resetDriveEncoders();
  moveDistance(-25);
  turn(90);
  moveDistance(-10);
  moveRoller(1, 0.1);
  moveDistance(10);
  turn(35);
  pros::delay(1000);
  indexer.move_relative(400, 600);
  pros::delay(500);
  indexer.move_relative(400, 600);
  pros::delay(700);
  indexer.move_relative(800, 600);
}

void test()
{
  resetDriveEncoders();
  turn(90);
}
