#include "main.h"

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



void setDriveGains(double kP, double kI, double kD)
{
  drive.kP = kP;
  drive.kI = kI;
  drive.kD = kD;
}
