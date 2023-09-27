# Yrkesakademin Trollhättan
# Software Developer Electrical & Autonomous Vehicles

## SV23TR E. Programmering och utveckling av inbyggda system
## YH00260-2020-3

## Individual Project
## Handheld Gaming Console

# 2023-09-08
Rocky start!
After deciding late what I wanted to do, I was quick to decide to develop this project on the STM32F303RE development board. It is fast, has plenty of memory, and uses a version of Eclipse (STM32CubeIDE) that is fantastic for some things and frustrating for many other things. The board itself feels like cheating sometimes, but it was just what I had at home.

Link to an overview of the board: https://doc.riot-os.org/group__boards__nucleo-f303re.html
Datasheet is available there as well as reference manual, programming manual and board manual.

The first thing I did was try to figure out how button inputs works on the STM32 and in STM32CubeIDE (henceforth known as "the IDE"). That was amazingly simple, as many things are with this board and IDE. Toggle the right pins in the pin overview and just write simple code for it. Same with toggling an LED on and off. The IDE generates all the relevant code to set it up, which is fantastic.

After seeing how the buttons worked I set about to find a good library for the display I had decided on, the SSD1306 0.96" OLED. I found a great library.
Link to library: https://github.com/afiskon/stm32-ssd1306
It is even MIT licensed! Incredible!
I used this youtube video as a guide to set it up: https://www.youtube.com/watch?v=z1Px6emHIeg
Not that it was difficult. Just copy the files to the right folders and change a comment in a header file.
The display worked almost immediately. However, I used a 1.3" OLED display that I thought was the same as the SSD1306 but slightly larger. It turns out that this larger display is in fact a different model, the SH1106. The SH1106 supposedly has a larger screen area. However after testing it seems that it can only use the same 128x64 as the SSD1306 and the screen is centered on the x-axis so the left-most pixels are coordinates (2.y). This is fine for my use and it was interesting to figure all this out. It still works great with the library I found (read more in notes_on_display.txt).

The library contains functions to draw pretty much anything one would want. The example image is of Garfield, and there are a lot of tests that can be fun to run. To run all tests, use the function ssd1306_TestAll().
This video uses the same library and shows how to create fun animations: https://www.youtube.com/watch?v=97_Vyph9EzM

Having tried to understand button debouncing and how to use it for several buttons at once, and having decided to only use one joystick instead of two, I think today was alright.

## 2023-09-15
After a long long time I have finally managed to sync this project with Github through Eclipse/STM32CubeIDE and I can't wait to start working for real so I don't have to do annoying setups like that ever again.

Properly tested my hardware debouncing and it seems to be more or less fixed. Could not get any bounces. I will consider the issue solved and if someone making a game for the console notices bouncing then that should be easily fixed in software.

Currently aiming to install the joystick, and after that I can finally set up a small console menu and implement Snake. When that is done I should be able to add some sounds, and then finally set up a function to compress button inputs to bits and transfer via UART. And finally make a small game on a second microcontroller that takes input from the console microcontroller via UART.

When all that is done it is time to learn power supplies and try to switch to a TFT LCD display. Then it's done I think.

## 2023-09-18
Let's get some stuff done!
Finished a menu in the console. It can currently display a message that says "No snek yet", it can test controls (will see if I can make it look a bit better), run the display tests, and show the trademark/license screen where I threaten offenders.
The control test works very well. The user can press any number of buttons which I tested before adding a button combination to go back to the menu. Pressing Yellow, Green and Shoulder buttons at the same time jumps you back to the main menu.
The display tests are the ones provided in the library. Credits is the just mentioned trademark screen.
It was a bit tricky to get the code to display the menu as I wanted but got a useful tip:
The colours used, Black and White, are defined as 0 and 1 respectively. The function for writing out text is ssd1306_WriteString(str, font, colour). I will use the same font for everything. And colour accepts 0 and 1 as arguments. So using enums (in this case) I can compare the current menu selection to the menu item being written out on the screen.
Had some issues with thinking backwards with
(selection == i)
at first. What it does is set the TEXT colour to black or white, not the background. But since the background is what my brain focused on I wrote it that way at first and only thought about it when my whole menu was the wrong colour.
Now I am going to try to implement unit testing if I can find the guide for it. I'm sure that's just as easy as everything else in Eclipse.

## 2023-09-22
After being made aware of PlatformIO, I switched the entire project to VS Code because Eclipse/STM32CubeIDE gives me a headache and requires substantial updates to be way more user friendly.
Got unit testing working fantastically within an hour. It was so easy and there were guides for it UNLIKE ECLIPSE.

## 2023-09-23
Uploaded project to a new Github repo. Will use that new repo for the console itself, and then make individual repos for any games I make.
Started messing around with UART. It seems simple enough. However, I also learned that typedefinitions are not global. Had to put them in main.h to get them to work everywhere.
Cleaning up the autogenerated code that STM32CubeIDE gave me will be a mess.

The UART transmit function compiled fine, but it's late and I will need to try receiving tomorrow. It should work.
My plan is to send a byte with button states (8 buttons total), then read the bits in the game and go from there. The first thing I will try is the console's control test. If that works, everything is going really well.

## 2023-09-27
After struggling for several days with UART and DMA, I decided to just use a polling transmit on the console, and an interrupt to receive on the game. This means that the UART on the console is blocking. However, sending controls to the game is the only thing the console unit does, and it is only 1 byte of data every 16 milliseconds at most. In practice, this will not happen as the console will only transmit new data if the controls change. Normal human behaviour should not push buttons that fast.
On the game side, receiving with interrupts seems to work very well. Will try to construct a game and test everything.
It might have been premature but I have put the UART test I wrote down as a game template since it does seem like it can receive the correct controls.
Will have to start working on unit testing as well so I can use that through game development.