
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

    // Power reduction register settings - turns off USART0 and ADC:
    PRR = (1 << PRUSART0) | (1 << PRADC);

    // Turns off the ADC:
    ADCSRA &= (0 << ADEN);


    // PINOUT SETUP

    // portB
    DDRB = OUTPUT_PIN << PB_LED_MODE   | INPUT_PIN << PB_BTN_PLAY   |
           INPUT_PIN  << PB_BTN_STOP   | INPUT_PIN << PB_BTN_PREV   |
           INPUT_PIN  << PB_BTN_NEXT   | OUTPUT_PIN << PB_PWM_BUZZER;

    // disables pull up resistors for input pins:
    PORTB &= ~((1 << PB_BTN_PLAY) | (1 << PB_BTN_STOP) |
               (1 << PB_BTN_NEXT) | (1 << PB_BTN_PREV));
    //TODO: PB_LED_MODE should be initialized with the value retrieved from
    //      EEPROM!

    // shift register communication portC:
    DDRC = OUTPUT_PIN << PC_SHR_CLR    | OUTPUT_PIN << PC_SHR_CLK       |
           OUTPUT_PIN << PC_SHR_STRCLK | OUTPUT_PIN << PC_SHR_OUTENABLE |
           OUTPUT_PIN << PC_SHR_DATA   | INPUT_PIN  << PC_UNASSIGNED_6;

    // initialises PORTC to low outputs while setting PC6 to Hi-Z:
    PORTC = 0 << PC_UNASSIGNED_6;

    // sets PORTD directions:
    DDRD = INPUT_PIN << PD_BTN_INCMIN  | INPUT_PIN << PD_BTN_DECMIN  |
           INPUT_PIN << PD_BTN_INCSEC  | INPUT_PIN << PD_BTN_DECSEC  |
           INPUT_PIN << PD_BTN_INCCENT | INPUT_PIN << PD_BTN_DECCENT |
           INPUT_PIN << PD_BTN_FOOT    | OUTPUT_PIN << PD_OUT_RELAY;

    // disables all pull ups, plus initializes the relay pin as OFF:
    PORTD = 0;

    // disables Timer0 interrupts:
    TIMSK0 &= ~(1 << TOIE0);


    // Finally, enables the interrupt modules:
    SREG |= (1 << SREG_I);
}
