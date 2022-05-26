#include "main.h"

double leftY;
double leftX;
double rightY;
double rightX;
double deadzone(double value, double deadzone);
void setDriveVoltage(double voltage);
void resetDriveMotors();
double convert(double inches);
void setDrive(double kP, double kI, double kD);
double curveControls(double value, double min, int exponent);

PID drive;