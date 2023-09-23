#ifndef __CONTROLLER_TRANSMIT_H
#define __CONTROLLER_TRANSMIT_H

#define SET_CONTROLLER (DPAD_UP << 7) | (DPAD_DOWN << 6) | (DPAD_RIGHT << 5) | (DPAD_LEFT << 4) | \
        (BUTTON_SHOULDER << 3) | (BUTTON_YELLOW << 2) | (BUTTON_RED << 1) | (BUTTON_GREEN << 0);

void transmitController();

#endif