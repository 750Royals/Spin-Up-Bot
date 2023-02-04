#include "main.h"
#include "pros/rtos.hpp"
#include "subsystemHeaders/autonomous.h"
#include "subsystemHeaders/driver.h"
#include "subsystemHeaders/globals.h"
#include "subsystemHeaders/autonmethods.h"

double kP = 10.25;
double kI = 0.0089;
double kD = 0.7;

double tkP = 10.4;
double tkI = 0.017;
double tkD = 0.71;

int integralBound = 2674;
int turnIntegralBound = 767;

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

int convertAngle(double angle)
{
  return (int)(angle*2250/180);
}

void resetDriveEncoders()
{
  backRight.tare_position();
  frontRight.tare_position();
  backLeft.tare_position();
  frontLeft.tare_position();
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
  while(abs(error)>5)
  {
    if(error < integralBound)
    {
      kI = 0.0085;
    }
    else if(error > integralBound)
    {
      kI = 0;
    }
    int leftMotorValues = (backLeft.get_position() + frontLeft.get_position())/2;
    int rightMotorValues = (backRight.get_position() + frontRight.get_position())/2;
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
    if(fabs(value) <= 10 && time > 500)
    {
      break;
    }
    if(fabs(value) <= 30 && fabs(value) > 10 && time > 1500)
    {
      break;
    }
    if(fabs(value) <= 50 && fabs(value) > 30 && time > 2000)
    {
      break;
    }
    if(time > 2500)
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
  int time = 0;
  int target = convertAngle(value);
  int error = convertAngle(value);
  int integral = 0;
  int derivative = 0;
  int current = 0;
  int prevError = 0;
  while(abs(error)>100)
  {
    if(error < turnIntegralBound)
    {
      kI = 0.017;
    }
    else if(error > turnIntegralBound)
    {
      kI = 0;
    }
    int leftMotorValues = (backLeft.get_position() + frontLeft.get_position())/2;
    int rightMotorValues = (backRight.get_position() + frontRight.get_position())/2;
    current = leftMotorValues - rightMotorValues;
    error = target - current;
    derivative = error - prevError;
    integral += error;
    int leftVoltage = (int) ((tkP*error+tkI*integral+tkD*derivative));
    int rightVoltage = (int) (-(tkP*error+tkI*integral+tkD*derivative));
    setDriveVoltage(leftVoltage, rightVoltage);
    prevError = error;
    pros::delay(20);
    time += 20;
    if(time > 1000)
    {
      break;
    }
  }
  setDriveVoltage(0,0);
  resetDriveEncoders();
}


void intakeOn(int direction)
{
  intake.move_voltage(direction*12000);
  pros::delay(20);
}

void intakeOff()
{
  intake.move_voltage(0);
}

void moveRoller(int direction, double seconds)
{
  roller.move_voltage(direction*12000);
  pros::delay(seconds*1000);
  roller.move_voltage(0);
}

void flywheelOn(int voltage)
{
  flywheel.move_voltage(voltage);
}

void flywheelOff()
{
  flywheel.move_voltage(0);
}
