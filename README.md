# darkroom-timer
code for an ATMEGA328-powered darkroom timer

# building
Just run
    make

To compile the default target for ATMEGA328P.

In order to run this on qEmu's emulator:
    make blinky_SIM

# Notes on implementation
## Timer prescaler:
If using a 20Mhz crystal:
    XTAL_FREQ=20e6

And setting the prescaler to 64, the following computations holds (to compute
the interrupt timeframe):
    time_s = (Increments / (XTAL_FREQ / 64))

In order to obtain a 1/100th of a second timeframe:
    Increments = 0.01 \* XTAL_FREQ / 64 = 3125

So, Timer/Counter1 needs to be set to:
    TCNT1H/L = 62411

Thus, Timer0 will naturally overflow with the frequency:
    XTAL_FREQ / (64 \* 256) ~= 1221Hz

Which, in fast PWM mode with simple OC0A pin inversion, will generate a 50%
duty cycle square wave with frequency:
    610 Hz
