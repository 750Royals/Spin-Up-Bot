#include "main.h"
#include "pros/rtos.hpp"
#include "subsystemHeaders/autonomous.h"
#include "subsystemHeaders/driver.h"
#include "subsystemHeaders/globals.h"
#include "subsystemHeaders/autonmethods.h"

double kP = 7.25;
double kI = 0.0012;
double kD = 1.02;

double tkP = 7.06;
double tkI = 0.0012;
double tkD = 1.02;

int integralBound = 0;
int turnIntegralBound = 90;

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
  return (int)(angle*2500/180);
}

void resetDriveEncoders()
{
  backRight.tare_position();
  frontRight.tare_position();
  backLeft.tare_position();
  frontLeft.tare_position();
  pros::delay(20);
}


void moveDistance(double value, int time)
{
  int x = 0;
  int target = convert(value);
  int error = convert(value);
  int integral = 0;
  int derivative = 0;
  int current = 0;
  int prevError = 0;
  while(abs(error)>5)
  {
    if(error > integralBound)
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
    x += 20;
    if(x > time)
    {
      break;
    }
  }
  setDriveVoltage(0,0);
  resetDriveEncoders();
  pros::delay(20);
}


void turn(double value, int time)
{
  int x = 0;
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
      tkI = 0.017;
    }
    else if(error > turnIntegralBound)
    {
      tkI = 0;
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
    x += 20;
    if(x > time)
    {
      break;
    }
  }
  setDriveVoltage(0,0);
  resetDriveEncoders();
}

void turnInertial(double angle)
{
  int time = 0;
  double target = angle;
  double error = angle;
  double integral = 0;
  double derivative = 0;
  double current = inertial.get_heading();
  double prevError = 0;
  while(fabs(error)>1)
  {
    if(error < turnIntegralBound)
    {
      tkI = 0.000;
    }
    else if(error > turnIntegralBound)
    {
      tkI = 0;
    }
    current = inertial.get_heading();
    error = target - current;
    derivative = error - prevError;
    integral += error;
    int leftVoltage = (int) ((tkP*error+tkI*integral+tkD*derivative));
    int rightVoltage = (int) (-(tkP*error+tkI*integral+tkD*derivative));
    setDriveVoltage(leftVoltage, rightVoltage);
    prevError = error;
    pros::delay(20);
    time += 20;
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
