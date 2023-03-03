#include "main.h"

extern double kP;
extern double kI;
extern double kD;
extern double tkP;
extern double tkI;
extern double tkD;
void moveDistance(double value, int time);
void turn(double value, int time);
void setDriveVoltage(int leftVoltage, int rightVoltage);
int convert(double inches);
void resetDriveEncoders();
int convertAngle(double angle);
void intakeOn(int direction);
void intakeOff();
void flywheelOn(int voltage);
void flywheelOff();
void moveRoller(int direction, double seconds);
void turnInertial(double angle);
extern int integralBound;
extern int turnIntegralBound;
