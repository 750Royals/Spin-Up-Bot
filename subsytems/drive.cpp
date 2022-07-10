#include "main.h"



double convert(double inches)
{
  double diameter = 4.00;
  double circumference = diameter*M_PI;
  return (300*inches)/circumference;
}

int deadzone(int value, int deadzone)
{
  if(abs(value)<deadzone)
  {
    return 0;
  }
  return value;
}

double curveControls(int value, double min, int exponent)
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

void setDriveControls()
{
    double leftY = deadzone(controller.get_analog(ANALOG_LEFT_Y),10);
    double leftX = deadzone(controller.get_analog(ANALOG_LEFT_X),10);
    double rightY = deadzone(controller.get_analog(ANALOG_RIGHT_Y),10);
    double rightX = deadzone(controller.get_analog(ANALOG_RIGHT_X),10);

    double power = curveControls(leftY, 10, 3);
    double turn = curveControls(rightX, 10, 3);
    int leftMove = power + turn;
    int rightMove = power - turn;
    frontLeft.move(leftMove);
    backLeft.move(leftMove);
    frontRight.move(rightMove);
    backRight.move(rightMove);
  
    //Constant Itake
    intake.move_velocity(250);
  
    //Flywheel Code
    if(master.get_digital(DIGITAL_X))
    {  
      flywheel.move_velocity(110);
    }
    else if(master.get_digital(DIGITAL_B))
    {
      flywheel.move_velocity(0);
    }
    else
    {
      flywheel.move_velocity(0);
    }
}



