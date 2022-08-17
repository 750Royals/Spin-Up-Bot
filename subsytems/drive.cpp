#include "main.h"

bool move = false;
bool move1 = false;


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


    frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    backRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    indexer.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    flywheelOne.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    flywheelTwo.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);


    double a = frontRight.get_actual_velocity();
    double b = backRight.get_actual_velocity();
    double c = frontLeft.get_actual_velocity();
    double d = backLeft.get_actual_velocity();



    frontRight.move(rightMove);
    frontLeft.move(leftMove);
    backRight.move(rightMove);
    backLeft.move(leftMove);



    //Flywheel Code
    if(controller.get_digital(DIGITAL_L2))
    {
      move = !move;
    }
    if(move)
    {
      flywheelOne.move_velocity(250);
      flywheelTwo.move_velocity(250);
    }
    else{
      flywheelOne.move_velocity(0);
      flywheelTwo.move_velocity(0);
    }


    // intake code
    if(controller.get_digital(DIGITAL_L1))
    {
      move1 = !move1;
    }
    if(move1)
    {
    intake.move_velocity(-500);
    }
    else{
      intake.move_velocity(0);
    }

    // Indexer Code
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A))
    {
      indexer.move_absolute(-15,100);
      pros:: delay(500);
      indexer.move_absolute(-15,10);
    }


}
