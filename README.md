# bomb_defuse_game.ino

An embedded systems project built using Arduino Uno that simulates a timed “bomb defusal” game using a keypad, LCD display, and LED indicators.

## Overview
The user must enter a secret 4-digit code using a 4x4 keypad before the countdown timer reaches zero. The system provides real-time feedback through a 16x2 LCD screen and LED indicators.

If the correct code is entered in time, the system is “defused.” If the timer runs out, the system triggers a “game over” state.

## Features
- 4x4 matrix keypad input system
- 16x2 LCD real-time display
- Countdown timer logic (60 seconds)
- Code validation system
- LED indicators for success and failure states
- Win/lose game logic

## Hardware Used
- Arduino Uno
- 16x2 LCD display
- 4x4 matrix keypad
- Red LED (failure indicator)
- Green LED (success indicator)
- Breadboard and resistors

## How It Works
1. System starts with a 60-second countdown
2. User enters a 4-digit code using keypad
3. Press `#` to submit code or `*` to reset input
4. If code is correct → system defuses (green LED)
5. If code is wrong → red LED flashes and user retries
6. If timer reaches zero → system triggers explosion state

## Code
All logic is implemented in a single Arduino `.ino` file using the Keypad and LiquidCrystal libraries.

## Author
Jacob Mettle
