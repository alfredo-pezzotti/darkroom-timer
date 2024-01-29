# darkroom-timer

code for an ATMEGA328-powered darkroom timer

# building
Just run<br>
`    make`
<br>
To compile the default target for ATMEGA328P.
<br>
To clean the target (i.e.: to remove all build artifacts):<br>
`   make clean`
<br>

To download the generated code to the chip:<br>
`   make BURN`
<br>

In order to run this on qEmu's emulator:<br>
`    make blinky_SIM`
<br>


# Notes on implementation
## Timer prescaler:
If using a 20Mhz crystal:<br>
`    XTAL_FREQ=20e6`

And setting the prescaler to 64, the following computations holds (to compute
the interrupt timeframe):<br>
`    time_s = (Increments / (XTAL_FREQ / 64))`
<br>

In order to obtain a 1/100th of a second timeframe:<br>
`    Increments = 0.01 \* XTAL_FREQ / 64 = 3125`
<br>
So, Timer/Counter1 needs to be set to:<br>
`    TCNT1H/L = 62411`
<br>
Thus, Timer0 will naturally overflow with the frequency:<br>
`    XTAL_FREQ / (64 \* 256) ~= 1221Hz`
<br>
Which, in fast PWM mode with simple OC0A pin inversion, will generate a 50%
duty cycle square wave with frequency:<br>
`    610 Hz`
<br>

