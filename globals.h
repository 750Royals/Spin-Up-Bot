#include "main.h"

extern pros::Controller controller;

extern pros::Motor backRight;
extern pros::Motor frontRight;
extern pros::Motor backLeft;
extern pros::Motor frontLeft;

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