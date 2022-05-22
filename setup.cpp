#include "main.h"

pros::Motor back_right(2);
pros::Motor front_right(9);
pros::Motor back_left(10);
pros::Motor front_left(1);
pros::Motor four_bar (5);
pros::Motor clamp(15);
pros::Motor two_bar(17);
pros::Motor intake(8);

pros::Controller master(CONTROLLER_MASTER);

void setDriveVoltage(double voltage)
{
  back_right.move_voltage(voltage);
  front_right.move_voltage(voltage);
  back_left.move_voltage(voltage);
  front_left.move_voltage(voltage);
}

void resetDriveMotors()
{
  back_right.tare_position();
  front_right.tare_position();
  back_left.tare_position();
  front_left.tare_position();
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
   void translate(double distance);
};

void PID::translate(double distance)
{
  while(fabs(error)>0.0001)
  {
    target = convert(distance);
    current = (back_left.get_position()+back_right.get_position()+front_left.get_position()+front_right.get_position())/4;
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
