#include "lemlib/api.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "main.h"

extern pros::Controller controller;

extern pros::Motor backRight;
extern pros::Motor frontRight;
extern pros::Motor backLeft;
extern pros::Motor frontLeft;
extern pros::Motor intake;
extern pros::Motor flywheel;
extern pros::Motor indexer;
extern pros::Motor roller;
extern pros::ADIDigitalOut piston;

extern pros::ADIEncoder back_enc;
extern pros::Imu inertial;

extern pros::MotorGroup leftMotors;
extern pros::MotorGroup rightMotors;

extern lemlib::Drivetrain_t drivetrain;

extern lemlib::TrackingWheel back_tracking_wheel;

extern lemlib::OdomSensors_t sensors; 

extern lemlib::ChassisController_t lateralController;
extern lemlib::ChassisController_t angularController;

extern lemlib::Chassis chassis;

