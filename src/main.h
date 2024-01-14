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
#define PC_SHR_CLR              0u
#define PC_SHR_CLK              1u
#define PC_SHR_STRCLK           2u
#define PC_SHR_OUTENABLE        3u
#define PC_SHR_DATA             4u
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

#define DISPLAY_NUMBER          3
#define DISPLAY_MINUTES         0
#define DISPLAY_SECONDS         1
#define DISPLAY_CENTS           2

#endif
