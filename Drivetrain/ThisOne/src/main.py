# --------------------------------------------------------------------------------- #
#                                                                                   #
#    Project:           Right Arcade                                                #
#    Module:            main.py                                                     #
#    Author:            VEX                                                         #
#    Description:       The Right up/down Controller Axis (2) will drive            #
#                       the robot forward and backwards.                            #
#                       The Right left/right Controller Axis (1) will turn          #
#                       the robot left and right.                                   #
#                       The deadband variable prevents drift when                   #
#                       the Controller's joystick is released.                      #
#                                                                                   #
#    Configuration:     Left Motor in Port 6                                        #
#                       Right Motor in Port 10                                      #
#                       Controller                                                  #
#                                                                                   #
# --------------------------------------------------------------------------------- #

# Library imports
from vex import *

# Brain should be defined by default
brain = Brain()

# Robot configuration code
brain_inertial = Inertial()
left_motor = Motor(Ports.PORT6, False)
right_motor = Motor(Ports.PORT10, True)
controller = Controller()

# Begin project code
# Set the deadband variable
dead_band = 5

while True:
    # Get the positions of axis 2 and axis 1
    axis_2_pos = controller.axis2.position()
    axis_1_pos = controller.axis1.position()

    if abs(axis_2_pos) + abs(axis_1_pos) > dead_band:
        left_motor.set_velocity((axis_2_pos + axis_1_pos), PERCENT)
        right_motor.set_velocity((axis_2_pos - axis_1_pos), PERCENT)
    else:
        left_motor.set_velocity(0, PERCENT)
        right_motor.set_velocity(0, PERCENT)
    left_motor.spin(FORWARD)
    right_motor.spin(FORWARD)

    wait(20, MSEC)
