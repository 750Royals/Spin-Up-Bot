#include "main.h"
#include "pros/motors.h"
#include "subsystemHeaders/autonomous.h"
#include "subsystemHeaders/driver.h"
#include "subsystemHeaders/globals.h"
#include "subsystemHeaders/autonmethods.h"


int deadzone(int value, int deadzone)
{
  if(abs(value)<deadzone)
  {
    return 0;
  }
  return value;
}

int curveControls(int value, double min, int exponent)
{
  if(value>0)
  {
    return ((1-(min/127))*pow((value/127.0),exponent)+(min/127.0))*127.0;
  }
  else if(exponent%2==0 && value<0)
  {
    return (((min/127.0)-1)*pow((value/127.0),exponent)-(min/127.0))*127.0;
  }
  else if(value<0)
  {
    return ((1-(min/127.0))*pow((value/127.0),exponent)-(min/127.0))*127.0;
  }
  return 0;
}

void setDriverControls()
{
    int leftY = deadzone(controller.get_analog(ANALOG_LEFT_Y),10);
    int leftX = deadzone(controller.get_analog(ANALOG_LEFT_X),10);
    int rightY = deadzone(controller.get_analog(ANALOG_RIGHT_Y),10);
    int rightX = deadzone(controller.get_analog(ANALOG_RIGHT_X),10);

    int power = curveControls(leftY, 10, 2);
    int turn = curveControls(rightX, 10, 2);
    int leftMove = power + turn;
    int rightMove = power - turn;

    flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);


    //Set drive power
    frontRight.move(rightMove);
    frontLeft.move(leftMove);
    backRight.move(rightMove);
    backLeft.move(leftMove);

    //Intake code
    if(controller.get_digital(DIGITAL_L1))
    {
      intake.move_voltage(12000);
    }
    else if(controller.get_digital(DIGITAL_L2))
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
      flywheel.move_voltage(8800);
    }
    else if(controller.get_digital(DIGITAL_Y))
    {
      flywheel.move_voltage(12000);
    }
    else if(controller.get_digital(DIGITAL_X))
    {
      flywheel.move_voltage(0);
    }

    //Indexer code
    if(controller.get_digital(DIGITAL_R1))
    {
      indexer.move_relative(600, 600);
    }

    //Roller Code
    if(controller.get_digital(DIGITAL_UP))
    {
      roller.move_voltage(12000);
    }
    else if(controller.get_digital(DIGITAL_DOWN))
    {
      roller.move_voltage(-12000);
    }
    else 
    {
      roller.move_voltage(0);
    }

    //Pneumatics Code
    if(controller.get_digital(DIGITAL_B))
    {
      piston.set_value(true);
    }

}
