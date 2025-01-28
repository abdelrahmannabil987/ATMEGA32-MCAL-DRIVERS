
## Description
The **AVR Timer Module** is designed for AVR microcontrollers to manage precise timing operations, including setting intervals, generating PWM signals, and handling interrupts. This module offers a flexible API that enables developers to easily incorporate time-based functionalities into their embedded applications.

Whether you're developing for real-time systems, implementing periodic tasks, or requiring precise signal generation, this module serves as a reliable foundation for time management in embedded applications.

## Features
- **Multiple Timer Modes**: Supports various operational modes for Timer/Counter0 and Timer/Counter1 including:
  - Normal Mode
  - CTC (Clear Timer on Compare Match)
  - Fast PWM
  - Phase Correct PWM
- **PWM Generation**: Allows configuration of PWM signals with adjustable duty cycles to control devices like motors and LEDs.
- **Delay Mechanism**: Provides non-blocking delay functions that allow periodic execution of user-defined callback functions.
- **Interrupt Management**: Offers a structured approach to handling timer interrupts for overflow and compare match events.
- **Input Capture Unit (ICU)**: Enables precise measurement of external events based on clock cycles.
- **Watchdog Timer Support**: Ensures system reliability by automatically resetting the microcontroller in case of software malfunctions or hangs.

## Architecture
The module is organized into the following key components:
1. **Timer Initialization**: Functions to initialize various timer modes.
2. **PWM Control**: Functions to manage PWM settings and adjustments.
3. **Delay Functions**: Implementation of time delays with callback functionality.
4. **Interrupt Management**: Set up and manage ISR (Interrupt Service Routines) for timer interrupts.
5. **ICU Management**: Handles external events captured by the Input Capture Unit.
6. **Watchdog Timer Control**: Functions to configure the watchdog timer for safety measures.

## Getting Started

### Prerequisites
To effectively use this Timer Module, you should have:
- An AVR microcontroller (e.g., ATmega series).
- An AVR development environment (like AVR Studio, Atmel Studio, or PlatformIO).
- An appropriate GCC compiler tailored for AVR microcontrollers.
- Basic understanding of C programming, particularly in embedded systems.
