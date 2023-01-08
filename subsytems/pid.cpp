#include "main.h"

double kP = 0.78;
double kI = 0.00021;
double kD = 0.21;

double tkP = 0.56;
double tkI = 0.0;
double tkD = 0.13;


void setDriveVoltage(int leftVoltage, int rightVoltage)
{
  backRight.move_voltage(rightVoltage);
  frontRight.move_voltage(rightVoltage);
  backRightUp.move_voltage(rightVoltage);
  backLeft.move_voltage(leftVoltage);
  frontLeft.move_voltage(leftVoltage);
  backLeftUp.move_voltage(leftVoltage);
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
  backLeftUp.tare_position();
  backRightUp.tare_position();
}


void moveDistance(int value)
{
  int target = value;
  int error = value;
  int integral = 0;
  int derivative = 0;
  int current = 0;
  int prevError = 0;
  while(fabs(error)>1)
  {
    int leftMotorValues = (backLeft.get_position() + frontLeft.get_position() + backLeftUp.get_position())/3;
    int rightMotorValues = (backRight.get_position() + frontRight.get_position() + backRightUp.get_position())/3;
    current = (leftMotorValues + rightMotorValues)/2;
    error = target - current;
    derivative = error - prevError;
    integral += error;
    int leftVoltage = (int) (15*(kP*error+kI*integral+kD*derivative));
    int rightVoltage = (int) (15*(kP*error+kI*integral+kD*derivative));
    setDriveVoltage(leftVoltage, rightVoltage);
    prevError = error;
    pros::delay(20);
  }
  setDriveVoltage(0,0);
  resetDriveEncoders();
  pros::delay(20);
}


void turn(int value)
{
  int target = value;
  int error = value;
  int integral = 0;
  int derivative = 0;
  int current = 0;
  int prevError = 0;
  while(fabs(error)>1)
  {
    int leftMotorValues = (backLeft.get_position() + frontLeft.get_position() + backLeftUp.get_position())/3;
    int rightMotorValues = (backRight.get_position() + frontRight.get_position() + backRightUp.get_position())/3;
    current = leftMotorValues - rightMotorValues;
    error = target - current;
    derivative = error - prevError;
    integral += error;
    int leftVoltage = (int) (15*(tkP*error+tkI*integral+tkD*derivative));
    int rightVoltage = (int) (15*(tkP*error+tkI*integral+tkD*derivative));
    setDriveVoltage(leftVoltage, -rightVoltage);
    prevError = error;
    pros::delay(20);
  }
  setDriveVoltage(0,0);
  resetDriveEncoders();
}
