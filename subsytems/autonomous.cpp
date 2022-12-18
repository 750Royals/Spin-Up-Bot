#include "main.h"

okapi::MotorGroup leftSet({18,14});
okapi::MotorGroup rightSet({13,11});
std::shared_ptr<ChassisController> chassis =
ChassisControllerBuilder()
.withMotors(leftSet, rightSet)
.withDimensions(AbstractMotor::gearset::blue, {{4_in, 9.5_in}, okapi::imev5BlueTPR})
.withMaxVelocity(500)
.build();




void right_auton()
{
  frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  backRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  chassis->moveDistance(1.5_ft);
  chassis->turnAngle(-90_deg);
  chassis->moveDistance(-1.5_ft);
  chassis->turnAngle(90_deg);
  chassis->moveDistance(-1.6_ft);
  roller.move_velocity(-600);
  pros::delay(800);
  roller.move_velocity(0);
  chassis->turnAngle(-90_deg);
  flywheel.move_velocity(-400);
  pros::delay(4000);
  indexer.move_relative(45, 100);
  pros::delay(1000);
  indexer.move_relative(45, 100);
  pros::delay(1000);
}

void left_auton()
{
  indexer.move_relative(170, 80);
  pros::delay(50);
  indexer.move_absolute(170, 80);
  /*indexer.move_relative(170, 80);
  indexer.move_relative(170, 80);

  frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  backRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  flywheel.move_velocity(-399);
  chassis->moveDistance(-0.2_ft);
  roller.move_velocity(-600);
  pros::delay(200);
  roller.move_velocity(0);
  pros::delay(100);
  chassis->moveDistance(0.5_ft);
  pros::delay(100);
  chassis->turnAngle(50_deg);
  pros::delay(50);
  chassis->moveDistance(2_ft);
  pros::delay(50);
  chassis->turnAngle(-108_deg);
  pros::delay(50);
  chassis->moveDistance(0.6_ft);
  pros::delay(50);
  indexer.move_relative(170, 80);
  pros::delay(3000);
*/
}

void left_auton_backup()
{

  frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  backRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  chassis->moveDistance(-.50_ft);
  roller.move_velocity(-600);
  pros::delay(500);
  roller.move_velocity(0);
  pros::delay(100);
  chassis->moveDistance(0.7_ft);
  chassis->turnAngle(130_deg);
  pros::delay(50);
  flywheel.move_velocity(-300);
  pros::delay(2000);
  indexer.move_relative(170, 100);
  pros::delay(1000);
  indexer.move_relative(170, 100);
  pros::delay(50);

  /*chassis->turnAngle(300_deg);
  flywheel.move_velocity(-300);
  pros::delay(4000);
  indexer.move_relative(45, 100);
  pros::delay(1000);
  indexer.move_relative(45, 100);
  pros::delay(1000);
  indexer.move_relative(45, 100);
  pros::delay(1000);/*
}

void skills_auton()
{
  /*chassis->moveDistance(4.75_ft);//Slightly move forward
  pros::delay(100);
  chassis->turnAngle(-180_deg);//Turn left
  pros::delay(100);
  chassis->moveDistance(-4.6_ft);//Slightly move forward
  pros::delay(101);
  roller.move_velocity(600); //Rotates initial field roller
  pros::delay(900);
  roller.move_velocity(0);
  pros::delay(100);*/
  /*
  ------------------------------------------------------------
  intake.move_velocity(-400);
  chassis->moveDistance(3.1_ft);//Slightly move forward
  pros::delay(300);
  chassis->turnAngle(70_deg);//Turn left
  pros::delay(300);
  chassis->moveDistance(9_ft);//Slightly move forward
  pros::delay(300);
  chassis->turnAngle(-110_deg);//Turn left
  pros::delay(300);
  indexer.move_relative(360, 100);
  pros::delay(50);
  flywheel.move_velocity(600); //Shoot discs into high goal
  pros::delay(300);
-------------------------------------------------------------
*/


  /*chassis->moveDistance(.4_ft);//Slightly move forward
  pros::delay(3);
  chassis->turnAngle(45_deg);//Turn left
  pros::delay(3);
  chassis->moveDistance(1.2_ft);//Slightly move forward
  pros::delay(3);
  chassis->turnAngle(-90_deg);//Turn right
  pros::delay(3);
  chassis->moveDistance(1.8_ft);//Slightly move forward
  pros::delay(3);
  chassis->turnAngle(-90_deg);//Turn right
  pros::delay(3);
  chassis->moveDistance(.7_ft);//Slightly move backward
  pros::delay(3);
  chassis->moveDistance(.6_ft);//Slightly move forward
  pros::delay(3);
  chassis->turnAngle(90_deg);//Turn left
  pros::delay(3);
  chassis->moveDistance(3_ft);//Slightly move forward
  pros::delay(3);
  flywheel.move_velocity(600); //Shoot discs into high goal
  pros::delay(3);
  chassis->moveDistance(-3_ft);//Slightly move backward
  pros::delay(3);
  chassis->turnAngle(-45_deg);//Turn right
  pros::delay(3);
  chassis->moveDistance(5.8_ft);//Slightly move forward
  pros::delay(3); //BOTTOM lEFT POINT FROM MIDDLE
  chassis->turnAngle(45_deg);//Turn left
  pros::delay(3);
  chassis->moveDistance(1_ft);//Slightly move forward
  pros::delay(3);
  flywheel.move_velocity(600); //Shoot discs into high goal
  pros::delay(3);
  chassis->moveDistance(-.3_ft);//Slightly move backward
  pros::delay(3);
  chassis->turnAngle(45_deg);//Turn left
  pros::delay(3);
  chassis->moveDistance(1.7_ft);//Slightly move forward
  pros::delay(3);
  chassis->turnAngle(-90_deg);//Turn right
  pros::delay(3);
  flywheel.move_velocity(600); //Shoot discs into high goal
  pros::delay(3);
  chassis->turnAngle(-90_deg);//Turn right
  pros::delay(3);
  chassis->moveDistance(1.5_ft);//Slightly move forward
  pros::delay(3);
  chassis->turnAngle(90_deg);//Turn left
  pros::delay(3);
  chassis->moveDistance(1.3_ft);//Slightly move forward
  pros::delay(3);
  chassis->turnAngle(90_deg);//Turn left
  pros::delay(3);
  flywheel.move_velocity(600); //Shoot discs into high goal
  pros::delay(3);
  chassis->turnAngle(-90_deg);//Turn right
  pros::delay(3);
  chassis->moveDistance(.4_ft);//Slightly move forward
  pros::delay(3);
  chassis->turnAngle(-90_deg);//Turn right
  pros::delay(3);
  chassis->moveDistance(5_ft);//Slightly move forward
  pros::delay(3);
  chassis->turnAngle(-90_deg);//Turn right
  pros::delay(3);
  chassis->moveDistance(-.4_ft);//Slightly move backward
  pros::delay(3);
  chassis->moveDistance(.4_ft);//Slightly move forward
  pros::delay(3); //MOVE FORWARD FROM TOP-lEFT FIELD ROLLER
  */
}
