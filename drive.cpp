#include "main.h"



double leftY = deadzone(controller.get_analog(ANALOG_LEFT_Y),10);
double leftX = deadzone(controller.get_analog(ANALOG_LEFT_X),10);
double rightY = deadzone(controller.get_analog(ANALOG_RIGHT_Y),10);
double rightX = deadzone(controller.get_analog(ANALOG_RIGHT_X),10);


void setDriveVoltage(double voltage)
{
  backRight.move_voltage(voltage);
  frontRight.move_voltage(voltage);
  backLeft.move_voltage(voltage);
  frontLeft.move_voltage(voltage);
}

void resetDriveMotors()
{
  backRight.tare_position();
  frontRight.tare_position();
  backLeft.tare_position();
  frontLeft.tare_position();
}

double convert(double inches)
{
  double diameter = 4.00;
  double circumference = diameter*M_PI;
  return (300*inches)/circumference;
}

double deadzone(double value, double deadzone)
{
  if(fabs(value)<deadzone)
  {
    return 0;
  }
  return value;
}


void PID::moveDistance(double distance)
{
  while(fabs(error)>0.0001)
  {
    target = convert(distance);
    current = (backLeft.get_position()+backRight.get_position()+frontLeft.get_position()+frontRight.get_position())/4;
    error = current - target;
    derivative = error - prevError;
    integral += error;
    setDriveVoltage(kP*error+kI*integral+kD*derivative);
    prevError = error;
    pros::delay(20);
  }
  resetDriveMotors();
}



void setLinearDrive(double kP, double kI, double kD)
{
  linearDrive.kP = kP;
  linearDrive.kI = kI;
  linearDrive.kD = kD;
}

void setRotationalDrive(double kP, double kI, double kD)
{
  rotationalDrive.kP = kP;
  rotationalDrive.kI = kI;
  rotationalDrive.kD = kD;
}


double curveControls(double value, double min, int exponent)
{
  if(value>0)
  {
    return ((1-(min/127))*pow((value/127),exponent)+(min/127))*127;
  }
  else if(exponent%2==0 && value<0)
  {
    return (((min/127)-1)*pow((value/127),exponent)-(min/127))*127;
  }
  else if(value<0)
  {
    return ((1-(min/127))*pow((value/127),exponent)-(min/127))*127;
  }
  return 0;
}

void setDriveControls()
{
    int power = curveControls(leftY, 10, 3);
		int turn = curveControls(rightX, 10, 3);
		int leftMove = power + turn;
		int rightMove = power - turn;
		frontLeft.move(leftMove);
		backLeft.move(leftMove);
		frontRight.move(rightMove);
		backRight.move(rightMove);
}
