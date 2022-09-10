#include "main.h"

int deadzone(int value, int deadzone);
void setDriveVoltage(double voltage);
void resetDriveMotors();
double convert(double inches);
double curveControls(int value, double min, int exponent);
void setDriverControls();
void indexerControl();
