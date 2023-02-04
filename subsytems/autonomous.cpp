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
  flywheelOn(9200);
  moveDistance(-5);
  moveRoller(1, 0.1);
  turn(-60);
  intakeOn(1);
  moveDistance(25);
  intakeOff();
  turn(120);
  moveDistance(-10);
  moveRoller(1, 0.1);
  moveDistance(5);
  turn(-80);
  moveDistance(37);
  turn(-3);
  pros::delay(500);
  indexer.move_relative(600, 600);
  intakeOn(1);
  pros::delay(2500);
  indexer.move_relative(800, 600);
  intakeOff();
  pros::delay(500);
  moveDistance(-49);
  turn(52);
  moveDistance(5);
  piston.set_value(true);
  /*moveDistance(-5);
  moveRoller(1, 0.1);
  moveDistance(5);
  turn(78);
  moveDistance(44);
  turn(10);  
  pros::delay(500);
  indexer.move_relative(600, 600);
  intakeOn(1);
  pros::delay(1800);
  indexer.move_relative(2400, 600);
  pros::delay(500);
  turn(-10);
  moveDistance(-20);
  turn(-70);
  moveDistance(27);
  turn(38);
  flywheelOn(9500);
  intakeOn(1);
  moveDistance(38);
  turn(95);
  indexer.move_relative(600, 600);
  intakeOn(1);
  pros::delay(1800);
  indexer.move_relative(2400, 600);
  turn(-97);
  intakeOn(1);
  moveDistance(30);
  flywheelOn(10000);
  turn(120);
  indexer.move_relative(600, 600);
  intakeOn(1);
  pros::delay(1800);
  indexer.move_relative(2400, 600);
  turn(5);
  moveDistance(-20);
  turn(130);
  moveDistance(-25);
  moveRoller(1, 0.1);*/
}

void left_auton()
{
  resetDriveEncoders();
  flywheelOn(11500);
  moveDistance(-5);
  moveRoller(1, 0.05);
  moveDistance(9);
  turn(-33);
  moveDistance(5);
  pros::delay(1000);
  indexer.move_relative(600, 600);
  intakeOn(1);
  pros::delay(1800);
  indexer.move_relative(2400, 600);
  /*turn(67);
  intakeOn(1);
  moveDistance(25);
  pros::delay(100);
  moveDistance(20);
  intakeOff();
  turn(-100);
  indexer.move_relative(600, 600);
  intakeOn(1);
  pros::delay(1800);
  indexer.move_relative(2400, 600);
  turn(100);
  moveDistance(25);*/

  /*moveDistance(-5);
  moveRoller(1, 0.05);
  moveDistance(5);
  turn(50);
  moveDistance(24);
  turn(-75);
  flywheelOn(10500);
  pros::delay(3000);
  indexer.move_relative(600, 600);
  intakeOn(1);
  pros::delay(1000);
  indexer.move_voltage(12000);*/
}

void right_auton()
{
  resetDriveEncoders();
  flywheelOn(10000);
  moveDistance(-25);
  turn(95);
  moveDistance(-12);
  moveRoller(1, 0.05);
  moveDistance(5);
  intakeOn(1);
  turn(-57);
  moveDistance(62);
  turn(95);
  pros::delay(1000); 
  indexer.move_relative(600, 600);
  intakeOn(1);
  pros::delay(1800);
  indexer.move_relative(2400, 600);
  turn(-90);
  intakeOn(1);
  moveDistance(25);
  pros::delay(50);
  pros::delay(15);
  turn(90);

  /*
  moveDistance(9);
  turn(18);
  pros::delay(1300);
  indexer.move_relative(600, 600);
  intakeOn(1);
  pros::delay(1000);
  indexer.move_voltage(12000);*/
}
