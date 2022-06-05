#include "main.h"

extern PID linearDrive;
extern PID rotationalDrive;

int deadzone(int value, int deadzone);
void setDriveVoltage(double voltage);
void resetDriveMotors();
double convert(double inches);
void setLinearDrive(double kP, double kI, double kD);
void setAngularDrive(double kP, double kI, double kD);
double curveControls(int value, double min, int exponent);
void setDriveControls();


