# StopWatch_Atmega32
# Program Flow
        1.User should set a time to count down i.e. [01:23] = 1 minutes and 23
        seconds..\
            
        2.User should Press '=', to make the stop watch to work.\
        NOTE:  if u wrote a wronge setup time, press 'C/ON' to re-Setup it.\
               User MUST write 4 digits first.\

# The hardware that has been used is:
    AVR-Atmega32.
    Keypad.
    LCD Display.

# Architecture Layer Applied:
        APP Folder has the Main Application --> main.c

        # HAL Folder has :
          Keypad Driver.
          LCD Display Driver.
        # MCAL Folder has:
          DIO Driver. (which is needed because HAL Layer Connecting to MCAL Layer).
          TIMERS Driver.
        # LIB Folder has .h Files has:
          useful Macros to make the code easier and more readable.
