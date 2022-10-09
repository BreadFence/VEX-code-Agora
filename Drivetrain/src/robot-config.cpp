#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftMo = motor(PORT1, ratio18_1, false);
motor RightMo = motor(PORT2, ratio18_1, true);
drivetrain Drivetrain = drivetrain(LeftMo, RightMo, 200, 145, 0, mm, 1);
controller Controller1 = controller(primary);
/*vex-vision-config:begin*/
vision Vision5 = vision (PORT5, 50);
/*vex-vision-config:end*/

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}