
#include "HAL_mcuSetup.h"
#include "../main.h"
#include <avr/io.h>
#include <util/delay.h>


void HAL_mcuSetup_init(void)
{
    // PERIPHERALS SETUP

    // disables all of the interrupt modules:
    SREG &= ~(1 << SREG_I);

    // enables IVSEL writing (sect. 9.5.2 of datasheet):
    MCUCR |= (1 << IVCE);

    // sets interrupt vectors to beginning of flash section:
    MCUCR &= ~(1 << IVSEL);

    // disables external interrupts:
    EIMSK &= ~((1 << INT1) | (1 << INT0));

    // disables pin change interrupts:
    PCICR &= ~((1 << PCIE2) | (1 << PCIE1) | (1 << PCIE0));

    // disables the corresponding pin masks:
    PCMSK2 = 0;
    PCMSK1 = 0;
    PCMSK0 = 0;

    // Watch Dog Timer flag is cleared:
    MCUSR &= ~(1 << WDRF);

    // Keeps old prescaler setting to prevent unintentional time-out (code
    // taken from atmega328P's datasheet, sect. 8.8.2):
    WDTCSR |= (1 << WDCE) | ( 1<< WDE);

    // finally, turns off the WDT:
    WDTCSR = 0x00u;

    // disables sleep mode by setting SE bit to 0 (along with everything else)
    // (cfr. sect. 7.11.1 of the ATMEGA328P's datasheet):
    SMCR = 0x00u;

    // Power reduction register settings - turns off USART0, ADC and Timer2:
    PRR = (1 << PRUSART0) | (1 << PRADC) | (1 << PRTIM2);

    // Turns off the ADC:
    ADCSRA &= (0 << ADEN);

    // TIMER0:

    // configures Timer/Counter 0 to toggle OC0A pin on compare match and
    // sets the output mode to FAST PWM.
    // In order to disconnect OC0A from the output pin (e.g.: to stop the PWM)
    // we should clear COM0A0 bit (please cfr sect. 12.9.1 of datasheet):
    TCCR0A = (1 << COM0A0) | (1 << WGM01) | (1 << WGM00);

    // completes the FAST PWM setting and selects the clock source as the
    // prescaler's CLK_IO/64 output:
    TCCR0B = (1 << WGM02)  | (1 << CS01)  | (1 << CS00);

    // sets the output compare A register to 0 to generate a 50% duty cycle
    // fast PWM signal, as per sect. 12.7.3:
    OCR0A = 0;

    // disables all interrupts related to Timer/Counter0:
    TIMSK0 = 0;

    // TIMER1:

    // disables all output-related features of Timer/Counter1:
    TCCR1A = 0;

    // selects CLK_IO/8 as Timer/Counter1 clock source (cfr. Table 13-5)
    // (Please note that this will require TCNT1 to be initialised to 40536u!):
    TCCR1B = (1 << CS11);

    // enables Timer/Counter1 overflow interrupt - please cfr. sect. 10.3 of
    // avr-libc manual to correctly use the ISRs!
    TIMSK1 = (1 << TOIE1);

    // deactivates Timer/Counter Synchronization mode:
    GTCCR &= ~(1 << TSM);


    // PINOUT SETUP

    // portB
    DDRB = OUTPUT_PIN << PB_LED_MODE   | INPUT_PIN << PB_BTN_PLAY |
           INPUT_PIN  << PB_BTN_STOP   | INPUT_PIN << PB_BTN_FOOT |
           INPUT_PIN  << PB_BTN_NEXT   | INPUT_PIN << PB_BTN_PREV;

    // disables pull up resistors for input pins:
    PORTB &= ~((1 << PB_BTN_PLAY) | (1 << PB_BTN_STOP) | (1 << PB_BTN_FOOT) |
               (1 << PB_BTN_NEXT) | (1 << PB_BTN_PREV));
    //TODO: PB_LED_MODE should be initialized with the value retrieved from
    //      EEPROM!

    // shift register communication portC:
    DDRC = OUTPUT_PIN << SHR_CLR    | OUTPUT_PIN << SHR_CLK         |
           OUTPUT_PIN << SHR_STRCLK | OUTPUT_PIN << SHR_OUTENABLE   |
           OUTPUT_PIN << SHR_DATA   | INPUT_PIN << PC_UNASSIGNED_5  |
           INPUT_PIN  << PC_UNASSIGNED_6;

    // initialises PORTC to low outputs while setting PC5 and PC6 to Hi-Z:
    PORTC = 0;

    // sets PORTD directions:
    DDRD = INPUT_PIN << PD_BTN_INCMIN  | INPUT_PIN << PD_BTN_DECMIN  |
           INPUT_PIN << PD_BTN_INCSEC  | INPUT_PIN << PD_BTN_DECSEC  |
           INPUT_PIN << PD_BTN_INCCENT | INPUT_PIN << PD_BTN_DECCENT |
           OUTPUT_PIN << PD_PWM_BUZZER | OUTPUT_PIN << PD_OUT_RELAY;

    // disables all pull ups, plus initializes the relay pin as OFF:
    PORTD = 0;


    // Finally, enables the interrupt modules:
    SREG |= (1 << SREG_I);
}
