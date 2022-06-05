#include "main.h"

extern PID linearDrive;
extern PID rotationalDrive;

extern double leftY;
extern double leftX;
extern double rightY;
extern double rightX;
double deadzone(double value, double deadzone);
void setDriveVoltage(double voltage);
void resetDriveMotors();
double convert(double inches);
void setLinearDrive(double kP, double kI, double kD);
void setAngularDrive(double kP, double kI, double kD);
double curveControls(double value, double min, int exponent);
void setDriveControls();


