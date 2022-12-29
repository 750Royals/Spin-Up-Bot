#include "main.h"

double kP = 0.1;
double kI = 0.1;
double kD = 0.1;

void setDriveVoltage(int leftVoltage, int rightVoltage)
{
  backRight.move_voltage(rightVoltage);
  frontRight.move_voltage(rightVoltage);
  backLeft.move_voltage(leftVoltage);
  frontLeft.move_voltage(leftVoltage);
}

int convert(double inches)
{
  double diameter = 4.00;
  double circumference = diameter*M_PI;
  double gearRatio = 1.0;
  return (int)((300*inches*7)/(circumference*3));
}


void resetDriveEncoders()
{
  backRight.tare_position();
  frontRight.tare_position();
  backLeft.tare_position();
  frontLeft.tare_position();
}


void moveDistance(double distance)
{
  while(fabs(error)>0.0001)
  {
    target = convert(distance);
    int leftMotorValues = (backLeft.get_position() + frontLeft.get_position() + backLeftUp.get_position())/3;
    int rightMotorValues = (backRight.get_position() + frontRight.get_position() + backRightUp.get_position())/3;
    current = (leftMotorValues + rightMotorValues)/2;
    error = target - current;
    derivative = error - prevError;
    integral += error;
    int leftVoltage = (int) (1000*(kP*error+kI*integral+kD*derivative));
    int rightVoltage = (int) (1000*(kP*error+kI*integral+kD*derivative));
    setDriveVoltage(leftVoltage, rightVoltage);
    prevError = error;
    pros::delay(20);
  }
  resetDriveEncoders();
}
