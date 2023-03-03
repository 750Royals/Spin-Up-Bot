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
  flywheelOn(10000);
  intakeOn(12000);
  moveDistance(-9, 500);
  moveRoller(1, 0.25);
  moveDistance(11, 1000);
  turn(-35, 300);
  moveDistance(9, 1000);
  turn(120, 1000);
  moveDistance(-9, 500);
  moveRoller(1, 0.25);
  moveDistance(10, 500);
  turn(-90, 500);
  moveDistance(36, 1000);
  indexer.move_relative(300, 600);
  pros::delay(500);
  indexer.move_relative(300, 600);
  pros::delay(500);
  indexer.move_relative(300, 600);
  moveDistance(-20, 1000);
  turn(45, 500);
  moveDistance(40, 1000);
  turn(-90, 1000);
  indexer.move_relative(300, 600);
  pros::delay(500);
  indexer.move_relative(300, 600);
  pros::delay(500);
  indexer.move_relative(300, 600);
  turn(90, 1000);
  moveDistance(50, 1000);
  turn(-120, 1000);
  moveDistance(20, 500);
  indexer.move_relative(300, 600);
  pros::delay(500);
  indexer.move_relative(300, 600);
  pros::delay(500);
  indexer.move_relative(300, 600);
  moveDistance(-30, 1000);
  turn(-90, 1000);
  moveDistance(-10, 1000);
  moveRoller(1, 0.25);
    moveDistance(11, 1000);
  turn(-35, 300);
  moveDistance(9, 1000);
  turn(120, 1000);
  moveDistance(-9, 500);
  moveRoller(1, 0.25);
  moveDistance(10, 500);
  turn(-90, 500);
  moveDistance(36, 1000);
  indexer.move_relative(300, 600);
  pros::delay(500);
  indexer.move_relative(300, 600);
  pros::delay(500);
  indexer.move_relative(300, 600);
  moveDistance(-20, 1000);
  turn(45, 500);
  moveDistance(40, 1000);
  turn(-90, 1000);
  indexer.move_relative(300, 600);
  pros::delay(500);
  indexer.move_relative(300, 600);
  pros::delay(500);
  indexer.move_relative(300, 600);
  turn(90, 1000);
  moveDistance(50, 1000);
  turn(-120, 1000);
  moveDistance(20, 500);
  indexer.move_relative(300, 600);
  pros::delay(500);
  indexer.move_relative(300, 600);
  pros::delay(500);
  indexer.move_relative(300, 600);
  moveDistance(-30, 1000);
  turn(-45, 600);
  piston.set_value(true);
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
  moveDistance(24);
  turn(90);
  moveDistance(-3);
  moveRoller(1, 0.05);
  moveDistance(3);
  turn(-45);
  moveDistance(2);
  turn(20);
  indexer.move_relative(600, 600);
  indexer.move_relative(600, 600);
  turn(-20);
  moveDistance(20);
  intakeOn(1);
  moveDistance(20);
  turn(90);
  indexer.move_relative(600, 600);
  indexer.move_relative(600, 600);
  indexer.move_relative(600, 600);
  pros::delay(1000);
  intakeOn(0);
  turn(180);
  moveDistance(10);
  intakeOn(1);
  turn(45);
  moveDistance(24);
  intakeOn(0);
  pros::delay(1000);
  turn(90);
  moveDistance(35);
  indexer.move_relative(600, 600);
  indexer.move_relative(600, 600);
  indexer.move_relative(600, 600);
}

void test()
{
  resetDriveEncoders();

}
