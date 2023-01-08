#include "main.h"


void left_auton_pid()
{
  resetDriveEncoders();
  pros::delay(50);
  turn(2400); //180 degree turn
  pros::delay(50);
  moveDistance(1337); //2 feet distance
}
