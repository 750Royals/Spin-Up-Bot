#include "main.h"
#include "subsystemHeaders/autonomous.h"
#include "subsystemHeaders/driver.h"
#include "subsystemHeaders/globals.h"
#include "subsystemHeaders/autonmethods.h"

double kP = 10.85;
double kI = 0.0085;
double kD = 0.9;

double tkP = 10.4;
double tkI = 0.017;
double tkD = 0.81;

int integralBound = 2674;

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

int convertAngle(double angle)
{
  return (int)(angle*2300/180);
}

void resetDriveEncoders()
{
  backRight.tare_position();
  frontRight.tare_position();
  backLeft.tare_position();
  frontLeft.tare_position();
  backLeftUp.tare_position();
  backRightUp.tare_position();
  pros::delay(20);
}


void moveDistance(double value)
{
  int time = 0;
  int target = convert(value);
  int error = convert(value);
  int integral = 0;
  int derivative = 0;
  int current = 0;
  int prevError = 0;
  int x = 0;
  while(abs(error)>50)
  {
    int leftMotorValues = (backLeft.get_position() + frontLeft.get_position() + backLeftUp.get_position())/3;
    int rightMotorValues = (backRight.get_position() + frontRight.get_position() + backRightUp.get_position())/3;
    current = (leftMotorValues + rightMotorValues)/2;
    error = target - current;
    derivative = error - prevError;
    integral += error;
    int leftVoltage = (int) ((kP*error+kI*integral+kD*derivative));
    int rightVoltage = (int) ((kP*error+kI*integral+kD*derivative));
    setDriveVoltage(leftVoltage, rightVoltage);
    prevError = error;
    pros::delay(20);
    time += 20;
    if(value < 20 && time > 1000)
    {
      break;
    }
  }
  setDriveVoltage(0,0);
  resetDriveEncoders();
  pros::delay(20);
}


void turn(double value)
{
  int target = convertAngle(value);
  int error = convertAngle(value);
  int integral = 0;
  int derivative = 0;
  int current = 0;
  int prevError = 0;
  while(abs(error)>100)
  {
    if(error < integralBound)
    {
      kI = 0.0085;
    }
    else if(error > integralBound)
    {
      kI = 0;
    }
    int leftMotorValues = (backLeft.get_position() + frontLeft.get_position() + backLeftUp.get_position())/3;
    int rightMotorValues = (backRight.get_position() + frontRight.get_position() + backRightUp.get_position())/3;
    current = leftMotorValues - rightMotorValues;
    error = target - current;
    derivative = error - prevError;
    integral += error;
    int leftVoltage = (int) ((tkP*error+tkI*integral+tkD*derivative));
    int rightVoltage = (int) (-(tkP*error+tkI*integral+tkD*derivative));
    setDriveVoltage(leftVoltage, rightVoltage);
    prevError = error;
    pros::delay(20);
  }
  setDriveVoltage(0,0);
  resetDriveEncoders();
}


void moveIntake(int direction, double seconds)
{
  intake.move_voltage(direction*12000);
  pros::delay(seconds*1000);
  intake.move_voltage(0);
}

void moveRoller(int direction, double seconds)
{
  intake.move_voltage(direction*12000);
  pros::delay(seconds*1000);
  intake.move_voltage(0);
}

void moveFlywheel(int speed)
{
  flywheel.move_velocity(speed);
}
