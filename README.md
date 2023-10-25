## This project uses the SH1106 1.3" OLED display and an 8 button setup
To make games or tools for this project, the following is needed:
* Receive UART. The console transmits controls as a single byte every 16 milliseconds. The game should receive the controls and use them as needed.
* Be able to run the SH1106.

The transmitted byte is interpreted like this:

```
0b10101010
  ^^^^^^^^
  ||||||||
  |||||||\--> Green button
  ||||||\-->  Red button
  |||||\-->   Yellow button
  ||||\-->    Shoulder button
  |||\-->     D-Pad Left
  ||\-->      D-pad Right
  |\-->       D-pad Down
  \-->        D-pad Up

```
Unit testing is done in the Tests environment with PlatformIO.