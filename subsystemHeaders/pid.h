#include "main.h"

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

extern PID drive;

void setDriveGains(double kP, double kI, double kD);