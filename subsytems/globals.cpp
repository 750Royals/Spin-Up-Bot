#include "lemlib/api.hpp"
#include "main.h"
#include "subsystemHeaders/globals.h"
#include "subsystemHeaders/driver.h"
#include "subsystemHeaders/autonomous.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::Motor backRight(6, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor frontRight(1, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backLeft(5, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor frontLeft(11, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intake(4, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor flywheel(10, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor indexer(9, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor roller(8, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::ADIDigitalOut piston ('A', false);

pros::ADIEncoder back_enc('A', 'B', false); // ports A and B, reversed
pros::Imu inertial(7);

pros::MotorGroup leftMotors({frontLeft, backLeft});
pros::MotorGroup rightMotors({frontRight, backRight});

lemlib::Drivetrain_t drivetrain 
{
    &leftMotors, // left drivetrain motors
    &rightMotors, // right drivetrain motors
    10, // track width
    4.125, // wheel diameter
    257 // wheel rpm
};

lemlib::TrackingWheel back_tracking_wheel(&back_enc, 4.125, 4.5); // 4.125" wheel diameter, 4.5" offset from tracking center

// odometry struct
lemlib::OdomSensors_t sensors 
{
    nullptr, // vertical tracking wheel 1
    nullptr, // vertical tracking wheel 2
    &back_tracking_wheel, // horizontal tracking wheel 1
    nullptr, // we don't have a second tracking wheel, so we set it to nullptr
    &inertial // inertial sensor
};

// forward/backward PID
lemlib::ChassisController_t lateralController 
{
    10, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};
 
// turning PID
lemlib::ChassisController_t angularController 
{
    2, // kP
    10, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);
