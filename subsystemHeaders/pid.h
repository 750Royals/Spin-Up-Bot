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
void moveIntake(int direction, double seconds);
void moveRoller(int direction, double seconds);
void moveFlywheel(int speed);
extern int integralBound;
