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
    return ((1-(min/127.0))*pow((value/127.0),exponent)+(min/127.0))*127.0;
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
    leftFlywheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    rightFlywheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    double leftY = deadzone(controller.get_analog(ANALOG_LEFT_Y),10);
    double leftX = deadzone(controller.get_analog(ANALOG_LEFT_X),10);
    double rightY = deadzone(controller.get_analog(ANALOG_RIGHT_Y),10);
    double rightX = deadzone(controller.get_analog(ANALOG_RIGHT_X),10);
  
  
    frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    backleft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    frontright.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    frontleft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    double power = curveControls(leftY, 10, 3);
    double turn = curveControls(rightX, 10, 3);
    int leftMove = power + turn;
    int rightMove = power - turn;
    frontLeft.move(leftMove);
    backLeft.move(leftMove);
    frontRight.move(rightMove);
    backRight.move(rightMove);
 
    //Constant Itake
    //Toggle Switch for Intake Speed
    bool highSpeed = true;
    if(highSpeed) 
    {
      intake.move_velocity(300);
    }
    else
    {
      intake.move_velocity(150);

    }
  
    if(master.get_digital(DIGITAL_A))
    {
      highSpeed != highSpeed;
    }
     
    
  
    //Flywheel Code
    if(master.get_digital(DIGITAL_X))
    {  
      leftFlywheel.move_velocity(110);
      rightFlywheel.move_velocity(110);
    }
    else if(master.get_digital(DIGITAL_B))
    {
      leftFlywheel.move_velocity(0);
      rightFlywheel.move_velocity(0);
    }
    else
    {
      leftFlywheel.move_velocity(0);
      rightFlywheel.move_velocity(0);
    }
  
    // Indexer Code
   if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
   {
     indexer.move_absolute(-30,100);
     pros::delay(500);
     indexer.move_absulute(30,10);
   }
     
    
}



