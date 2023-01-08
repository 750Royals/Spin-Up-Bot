#include "main.h"

int deadzone(int value, int deadzone)
{
  if(abs(value)<deadzone)
  {
    return 0;
  }
  return value;
}



void setDriverControls()
{
    int leftY = deadzone(controller.get_analog(ANALOG_LEFT_Y),10);
    int leftX = deadzone(controller.get_analog(ANALOG_LEFT_X),10);
    int rightY = deadzone(controller.get_analog(ANALOG_RIGHT_Y),10);
    int rightX = deadzone(controller.get_analog(ANALOG_RIGHT_X),10);

    int power = leftY;
    int turn = rightX;
    int leftMove = power + turn;
    int rightMove = power - turn;

    flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);


    //Set drive power
    frontRight.move(rightMove);
    frontLeft.move(leftMove);
    backRight.move(rightMove);
    backLeft.move(leftMove);
    backRightUp.move(rightMove);
    backLeftUp.move(leftMove);

    //Intake and Roller code
    if(controller.get_digital(DIGITAL_L1))
    {
      intake.move_voltage(12000);
    }
    else if(controller.get_digital(DIGITAL_R1))
    {
      intake.move_voltage(-12000);
    }
    else
    {
      intake.move_velocity(0);
    }

    //Flywheel Code
    if(controller.get_digital(DIGITAL_R2))
    {
      flywheel.move_velocity(-300);
    }
    else if(controller.get_digital(DIGITAL_Y))
    {
      flywheel.move_velocity(-400);
    }
    else if(controller.get_digital(DIGITAL_X))
    {
      flywheel.move_velocity(0);
    }



}
