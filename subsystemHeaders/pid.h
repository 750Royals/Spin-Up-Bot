#include "main.h"

extern double kP;
extern double kI;
extern double kD;
extern int target;
extern int current;
extern int error;
extern int prevError;
extern int derivative;
extern int integral;
extern void moveDistance(double distance);
extern void setDriveVoltage(int leftVoltage, int rightVoltage);
extern int convert(double inches);
