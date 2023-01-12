#include "main.h"
#include "subsystemHeaders/autonomous.h"
#include "subsystemHeaders/driver.h"
#include "subsystemHeaders/globals.h"
#include "subsystemHeaders/autonmethods.h"


void left_auton_pid()
{
  resetDriveEncoders();
  /*moveIntake(1,0.25);
  moveDistance(20);
  turn(90);
  moveDistance(-23);
  moveIntake(1,0.25);*/
  //moveDistance(21);
  turn(90);
  //turn(-45);
  moveDistance(21);
}
