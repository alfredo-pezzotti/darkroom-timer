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

And setting the prescaler to 16, the following computations holds (to compute
the interrupt timeframe):
    time_s = (Increments / (XTAL_FREQ / 16))

In order to obtain a 1/100th of a second timeframe:
    Increments = 0.01 \* XTAL_FREQ / 16 = 12500

So, Timer/Counter1 needs to be set to:
    TCNT1H/L = 53036

Thus, Timer0 will naturally overflow with the frequency:
    XTAL_FREQ / (16 \* 256) ~= 4883Hz

Which, in fast PWM mode with simple OC0A pin inversion, will generate a 50%
duty cycle square wave with frequency:
    2441.5 Hz
