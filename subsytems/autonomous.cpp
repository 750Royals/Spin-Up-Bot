#include "main.h"

okapi::MotorGroup leftSet({18,14});
okapi::MotorGroup rightSet({13,11});
std::shared_ptr<ChassisController> chassis =
ChassisControllerBuilder()
.withMotors(leftSet, rightSet)
.withDimensions(AbstractMotor::gearset::blue, {{4_in, 11.5_in}, okapi::imev5BlueTPR})
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
  chassis->moveDistance(0.5_ft);//Spin roller and move forward
  pros::delay(3);
  chassis->turnAngle(-15_deg);//Turn slightly right
  pros::delay(3);
  chassis->moveDistance(2.4_ft);//Move forward and collect discs on autonomous line
  pros::delay(3);
  chassis->turnAngle(-90_deg);//Turn right
  pros::delay(3);
  chassis->moveDistance(0.8_ft);//Slightly move forward
  pros::delay(3);
  chassis->turnAngle(90_deg);//Turn left
  pros::delay(3);
  chassis->moveDistance(1.0_ft);//Slightly move forward
  pros::delay(3);
  chassis->turnAngle(90_deg);//Turn left
  pros::delay(3);
  chassis->moveDistance(0.8_ft);//Slightly move forward
  pros::delay(3);
  flywheel.move_velocity(600); //Shoot discs into high goal
  pros::delay(3);
}

void skills_auton()
{
  /*roller.move_velocity(600); //Rotates initial field roller
  pros::delay(100);*/
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
