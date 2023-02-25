#include "main.h"
#include "pros/motors.h"
#include "subsystemHeaders/autonomous.h"
#include "subsystemHeaders/driver.h"
#include "subsystemHeaders/globals.h"
#include "subsystemHeaders/autonmethods.h"
#include <ostream>
#include <string>


void setTurnVoltage(int voltage)
{
  backRight.move_voltage(-voltage);
  frontRight.move_voltage(-voltage);
  backLeft.move_voltage(voltage);
  frontLeft.move_voltage(voltage);
}

int deadzone(int value, int deadzone)
{
  if(abs(value)<deadzone)
  {
    return 0;
  }
  return value;
}

int curveControls(int value, double min, int exponent)
{
  if(value>0)
  {
    return ((1-(min/127))*pow((value/127.0),exponent)+(min/127.0))*127.0;
  }
  else if(exponent%2==0 && value<0)
  {
    return (((min/127.0)-1)*pow((value/127.0),exponent)-(min/127.0))*127.0;
  }
  else if(value<0)
  {
    return ((1-(min/127.0))*pow((value/127.0),exponent)-(min/127.0))*127.0;
  }
  return 0;
}

void align()
{
  vision_object_s_t rtn = visionSensor.get_by_sig(0, 1);
  while(rtn.left_coord != 50)
  {
    if(rtn.left_coord < 50)
    {
      setTurnVoltage(2000);
    }
    else if(rtn.left_coord > 50)
    {
      setTurnVoltage(-2000);
    }
  }
}


void setDriverControls()
{

    int position = (frontRight.get_position()+backRight.get_position()+frontLeft.get_position()+frontLeft.get_position())/4;
    std::string pos = std::to_string(position);

    double heading = inertial.get_heading();
    std::string hed = std::to_string(heading);

    int leftY = deadzone(controller.get_analog(ANALOG_LEFT_Y),10);
    int leftX = deadzone(controller.get_analog(ANALOG_LEFT_X),10);
    int rightY = deadzone(controller.get_analog(ANALOG_RIGHT_Y),10);
    int rightX = deadzone(controller.get_analog(ANALOG_RIGHT_X),10);

    int power = curveControls(leftY, 10, 2);
    int turn = curveControls(rightX, 10, 2);
    int leftMove = power + turn;
    int rightMove = power - turn;

    flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);


    //Set drive power
    double m = 0.8;
    frontRight.move(m*rightMove);
    frontLeft.move(m*leftMove);
    backRight.move(m*rightMove);
    backLeft.move(m*leftMove);

    controller.set_text(2, 0, pos);
    controller.set_text(2, 9, hed);

    //Intake code
    if(controller.get_digital(DIGITAL_L1))
    {
      intake.move_voltage(12000);
    }
    else if(controller.get_digital(DIGITAL_L2))
    {
      intake.move_voltage(-12000);
    }
    else
    {
      intake.move_velocity(0);
    }

    if(flywheel.is_over_temp())
    {
      controller.rumble(".");
      controller.set_text(0, 0, "FLYWHEEL OVERHEATING");
    }

    if(intake.is_over_temp())
    {
      controller.rumble(".");
      controller.set_text(1, 0, "INTAKE OVERHEATING");
    }

    if(backLeft.is_over_temp() || frontLeft.is_over_temp() || backRight.is_over_temp() || frontRight.is_over_temp())
    {
      controller.rumble(".");
      controller.set_text(2, 0, "DRIVE OVERHEATING");
    }

    //Flywheel Code
    if(controller.get_digital(DIGITAL_R2))
    {
      flywheel.move_voltage(7000);
    }
    else if(controller.get_digital(DIGITAL_Y))
    {
      flywheel.move_voltage(12000);
    }
    else if(controller.get_digital(DIGITAL_X))
    {
      flywheel.move_voltage(0);
    }

    //Indexer code
    if(controller.get_digital(DIGITAL_R1))
    {
      pros::delay(20);
      indexer.move_relative(600, 600);
      pros::delay(300);
      flywheel.move_voltage(10000);
      pros::delay(20);
      indexer.move_relative(600, 600);
      pros::delay(300);
      flywheel.move_voltage(12000);
      pros::delay(20);
      indexer.move_relative(1000, 600);
      pros::delay(20);
      flywheel.move_voltage(7000);
    }

    

    //Roller Code
    if(controller.get_digital(DIGITAL_UP))
    {
      roller.move_voltage(9000);
    }
    else if(controller.get_digital(DIGITAL_DOWN))
    {
      roller.move_voltage(-9000);
    }
    else 
    {
      roller.move_voltage(0);
    }

    //Pneumatics Code
    if(controller.get_digital(DIGITAL_B))
    {
      piston.set_value(true);
    }


    
    if(controller.get_digital(DIGITAL_A))
    {
      indexer.move_relative(400, 600);
    }
}
