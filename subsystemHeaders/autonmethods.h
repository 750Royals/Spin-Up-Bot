#include "main.h"

extern double kP;
extern double kI;
extern double kD;
extern double tkP;
extern double tkI;
extern double tkD;
void moveDistance(double value);
void turn(double value);
void setDriveVoltage(int leftVoltage, int rightVoltage);
int convert(double inches);
void resetDriveEncoders();
int convertAngle(double angle);
void intakeOn(int direction);
void intakeOff();
void flywheelOn(int voltage);
void flywheelOff();
void moveRoller(int direction, double seconds);
extern int integralBound;
extern int turnIntegralBound;
