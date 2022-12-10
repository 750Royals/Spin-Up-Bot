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



void setDriverControls()
{
    double leftY = deadzone(controller.get_analog(ANALOG_LEFT_Y),10);
    double leftX = deadzone(controller.get_analog(ANALOG_LEFT_X),10);
    double rightY = deadzone(controller.get_analog(ANALOG_RIGHT_Y),10);
    double rightX = deadzone(controller.get_analog(ANALOG_RIGHT_X),10);

    double power = curveControls(leftY, 10, 3);
    double turn = curveControls(rightX, 10, 3);
    int leftMove = power + turn;
    int rightMove = power - turn;


    frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    backRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

    //Set drive power
    frontRight.move(rightMove);
    frontLeft.move(leftMove);
    backRight.move(rightMove);
    backLeft.move(leftMove);

    //Piston Code
    /*if(controller.get_digital(DIGITAL_A))
    {
      piston.set_value(HIGH);
      pros::delay(500);
      piston.set_value(LOW);
    }
    else
    {
      piston.set_value(LOW);
    }*/

    //Intake code
    if(controller.get_digital(DIGITAL_L1))
    {
      intake.move_velocity(-335);
    }
    else if(controller.get_digital(DIGITAL_L2))
    {
      intake.move_velocity(335);
    }
    else
    {
      intake.move_velocity(0);
    }

    //Flywheel Code
    if(controller.get_digital(DIGITAL_R2))
    {
      flywheel.move_voltage(-7000);
    }
    else if(controller.get_digital(DIGITAL_Y))
    {
      flywheel.move_voltage(-12000);
    }
    else if(controller.get_digital(DIGITAL_X))
    {
      flywheel.move_voltage(0);
    }

    //Roller code
    if(controller.get_digital(DIGITAL_UP))
    {
      roller.move_velocity(-350);
    }
    else if(controller.get_digital(DIGITAL_DOWN))
    {
      roller.move_velocity(350);
    }
    else
    {
      roller.move_velocity(0);
    }

    //Indexer Code
    //Indexer retracts when X is pressed and extends when X is let go
    if(controller.get_digital(DIGITAL_R1))
    {
      indexer.move_relative(45, 100);
      pros::delay(50);
    }

    //Piston Code
    if(controller.get_digital(DIGITAL_A))
    {
      piston.set_value(LOW);
      pros::delay(50);
    }
}
