#include "main.h"

okapi::MotorGroup leftSet({18,14});
okapi::MotorGroup rightSet({13,11});
std::shared_ptr<ChassisController> chassis =
ChassisControllerBuilder()
.withMotors(leftSet, rightSet)
.withDimensions(AbstractMotor::gearset::blue, {{4_in, 9.5_in}, okapi::imev5BlueTPR})
.withMaxVelocity(300)
.build();


void right_auton()
{
  chassis->moveDistance(1.1_ft);//Move forward diagonally
  pros::delay(3);
  chassis->turnAngle(45_deg);//Turn left so the bot roller faces field roller
  pros::delay(3);
  chassis->moveDistance(-2.0_ft);//Move backward and spin roller
  pros::delay(3);
  chassis->moveDistance(5.1_ft);//Move forward and collect discs
  pros::delay(3);
  chassis->turnAngle(-90_deg);//Turn right and face the high goal
  pros::delay(3);
  flywheel.move_velocity(600); //Shoot discs into high goal
  pros::delay(3);
}

void left_auton()
{
  chassis->moveDistance(-0.1_ft);
  pros::delay(20);
  roller.move_velocity(200);
  pros::delay(20);
  chassis->moveDistance(1_ft);
}

void skills_auton()
{
  /*
  chassis->moveDistance(-.80_ft);//Slightly move forward
  roller.move_velocity(-600); //Rotates initial field roller
  pros::delay(800);
  roller.move_velocity(0);
  pros::delay(100);
  chassis->turnAngle(-10_deg);
  flywheel.move_velocity(-300);
  pros::delay(2000);
  indexer.move_relative(52, 100);
  pros::delay(1000);
  indexer.move_relative(52, 100);
  pros::delay(1000);
  /*


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
