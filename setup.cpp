#include "main.h"

pros::Motor backRight(2, true);
pros::Motor frontRight(9, true);
pros::Motor backLeft(10);
pros::Motor frontLeft(1);
pros::Motor fourBar (5);
pros::Motor clamp(15);
pros::Motor twoBar(17);
pros::Motor intake(8);

pros::Controller master(CONTROLLER_MASTER);

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
  double diameter = 4.125;
  double circumference = diameter*M_PI;
  return (circumference*inches)/360;
}

class PID
{
 public:
   double kP;
   double kI;
   double kD;
   double target;
   double current;
   double error;
   double prevError;
   double derivative;
   double integral;
   void moveDistance(double distance);
};

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


PID drive;

void setDrive(double kP, double kI, double kD)
{
  drive.kP = kP;
  drive.kI = kI;
  drive.kD = kD;
}
