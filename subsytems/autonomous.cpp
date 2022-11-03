#include "main.h"

okapi::MotorGroup leftSet({3,5});
okapi::MotorGroup rightSet({1,4});
std::shared_ptr<ChassisController> chassis =
ChassisControllerBuilder()
.withMotors(leftSet, rightSet)
.withDimensions(AbstractMotor::gearset::blue, {{4_in, 11.5_in}, okapi::imev5BlueTPR})
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
  chassis->turnAngle(-15_deg);//Turn slightly right
  chassis->moveDistance(2.4_ft);//Move forward and collect discs on autonomous line
  chassis->turnAngle(-90_deg);//Turn right
  chassis->moveDistance(0.8_ft);//Slightly move forward
  chassis->turnAngle(90_deg);//Turn left
  chassis->moveDistance(1.0_ft);//Slightly move forward
  chassis->turnAngle(90_deg);//Turn left
  chassis->moveDistance(0.8_ft);//Slightly move forward
  flywheel.move_velocity(600); //Shoot discs into high goal
}
