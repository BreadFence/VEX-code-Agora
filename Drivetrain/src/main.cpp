/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  SDV Template (Drivetrain)                                 */
/*                                                                            */
/*    Name:                                                                   */
/*    Date:                                                                   */
/*    Class:                                                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2            
// Vision5              vision        5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // read percent from controller axis
int leftSpeed  = Controller1.Axis3.position();
int rightSpeed = Controller1.Axis2.position();
// deadband
if( abs(leftSpeed)  < 10 ) leftSpeed  = 0;
if( abs(rightSpeed) < 10 ) rightSpeed = 0;
// send to motors
LeftMo.spin( forward, leftSpeed, percent );
rightDrive.spin( forward, rightSpeed, percent );
 }
}
