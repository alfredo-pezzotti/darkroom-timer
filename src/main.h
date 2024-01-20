#ifndef MAIN_H
#define MAIN_H



// PIN offsets:
#define LED_PIN (0)

#define PLAYSTOP_INPUT          PINB
#define PB_INPUT_MASK           0x3Eu
#define PB_LED_MODE             0u
#define PB_BTN_FOOT             1u
#define PB_BTN_PLAY             2u
#define PB_BTN_STOP             3u
#define PB_BTN_NEXT             4u
#define PB_BTN_PREV             5u

#define SHIFTREG_PORT           PORTC
#define SHR_CLR                 0u
#define SHR_CLK                 1u
#define SHR_STRCLK              2u
#define SHR_OUTENABLE           3u
#define SHR_DATA                4u
#define PC_UNASSIGNED_5         5u
#define PC_UNASSIGNED_6         6u

#define TIMESET_PORT            PIND
#define PD_INPUT_MASK           0x3Fu
#define PD_BTN_INCMIN           0u
#define PD_BTN_DECMIN           1u
#define PD_BTN_INCSEC           2u
#define PD_BTN_DECSEC           3u
#define PD_BTN_INCCENT          4u
#define PD_BTN_DECCENT          5u
#define PD_PWM_BUZZER           6u
#define PD_OUT_RELAY            7u

#define EXECUTE_FOREVER         0xA5
#define INPUT_PIN               0
#define OUTPUT_PIN              1
#define BUTTON_PRESSED          1
#define OUT_HIGH                1
#define OUT_LOW                 0

#define DISPLAY_DIGITS          6
#define DISPLAY_NUMBER          3
#define DISPLAY_DIGITS_PER_VAL  2
#define DISPLAY_MINUTES         0
#define DISPLAY_SECONDS         1
#define DISPLAY_CENTS           2

// generics:
#define BYTE_BITS               8
#define MSb                     7


// exported variables:
#ifdef MOCK
    extern int     mock_portb;
    extern uint8_t mock_portc;
    #define LED_PORT            mock_portb
    #define SHR_PORT            mock_portc
#else
    #define LED_PORT            PORTB
    #define SHR_PORT            PORTC
#endif


#endif
