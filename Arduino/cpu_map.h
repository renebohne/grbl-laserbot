/*
  cpu_map.h - CPU and pin mapping configuration file
  Part of Grbl

  Copyright (c) 2012-2016 Sungeun K. Jeon for Gnea Research LLC

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

/* The cpu_map.h files serve as a central pin mapping selection file for different
   processor types or alternative pin layouts. This version of Grbl supports only the
   Arduino Mega2560. */

#ifndef cpu_map_h
#define cpu_map_h


#ifdef CPU_MAP_2560_INITIAL // (Arduino Mega 2560) Working @EliteEng

// Serial port interrupt vectors
#define SERIAL_RX USART0_RX_vect
#define SERIAL_UDRE USART0_UDRE_vect

// Define step pulse output pins. NOTE: All step bit pins must be on the same port.
#define STEP_DDR      DDRA
#define STEP_PORT     PORTA
#define STEP_PIN      PINA
#define X_STEP_BIT    2 // MEGA2560 Digital Pin 24
#define Y_STEP_BIT    3 // MEGA2560 Digital Pin 25
#define Z_STEP_BIT    4 // MEGA2560 Digital Pin 26
#define STEP_MASK ((1<<X_STEP_BIT)|(1<<Y_STEP_BIT)|(1<<Z_STEP_BIT)) // All step bits

// Define step direction output pins. NOTE: All direction pins must be on the same port.
#define DIRECTION_DDR     DDRC
#define DIRECTION_PORT    PORTC
#define DIRECTION_PIN     PINC
#define X_DIRECTION_BIT   7 // MEGA2560 Digital Pin 30
#define Y_DIRECTION_BIT   6 // MEGA2560 Digital Pin 31
#define Z_DIRECTION_BIT   5 // MEGA2560 Digital Pin 32
#define DIRECTION_MASK ((1<<X_DIRECTION_BIT)|(1<<Y_DIRECTION_BIT)|(1<<Z_DIRECTION_BIT)) // All direction bits

// Define stepper driver enable/disable output pin.
#define STEPPERS_DISABLE_DDR   DDRB
#define STEPPERS_DISABLE_PORT  PORTB
#define STEPPERS_DISABLE_BIT   7 // MEGA2560 Digital Pin 13
#define STEPPERS_DISABLE_MASK (1<<STEPPERS_DISABLE_BIT)

// Define homing/hard limit switch input pins and limit interrupt vectors.
// NOTE: All limit bit pins must be on the same port
#define LIMIT_DDR       DDRB
#define LIMIT_PORT      PORTB
#define LIMIT_PIN       PINB
#define X_LIMIT_BIT     4 // MEGA2560 Digital Pin 10
#define Y_LIMIT_BIT     5 // MEGA2560 Digital Pin 11
#define Z_LIMIT_BIT     6 // MEGA2560 Digital Pin 12
#define LIMIT_INT       PCIE0  // Pin change interrupt enable pin
#define LIMIT_INT_vect  PCINT0_vect
#define LIMIT_PCMSK     PCMSK0 // Pin change interrupt register
#define LIMIT_MASK ((1<<X_LIMIT_BIT)|(1<<Y_LIMIT_BIT)|(1<<Z_LIMIT_BIT)) // All limit bits

// Define spindle enable and spindle direction output pins.
#define SPINDLE_ENABLE_DDR      DDRH
#define SPINDLE_ENABLE_PORT     PORTH
#define SPINDLE_ENABLE_BIT      3 // MEGA2560 Digital Pin 6
#define SPINDLE_DIRECTION_DDR   DDRE
#define SPINDLE_DIRECTION_PORT  PORTE
#define SPINDLE_DIRECTION_BIT   3 // MEGA2560 Digital Pin 5

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_DDR   DDRH
#define COOLANT_FLOOD_PORT  PORTH
#define COOLANT_FLOOD_BIT   5 // MEGA2560 Digital Pin 8
#define COOLANT_MIST_DDR    DDRH
#define COOLANT_MIST_PORT   PORTH
#define COOLANT_MIST_BIT    6 // MEGA2560 Digital Pin 9

// Define user-control CONTROLs (cycle start, reset, feed hold) input pins.
// NOTE: All CONTROLs pins must be on the same port and not on a port with other input pins (limits).
#define CONTROL_DDR       DDRK
#define CONTROL_PIN       PINK
#define CONTROL_PORT      PORTK
#define CONTROL_RESET_BIT         0  // MEGA2560 Analog Pin 8
#define CONTROL_FEED_HOLD_BIT     1  // MEGA2560 Analog Pin 9
#define CONTROL_CYCLE_START_BIT   2  // MEGA2560 Analog Pin 10
#define CONTROL_SAFETY_DOOR_BIT   3  // MEGA2560 Analog Pin 11
#define CONTROL_INT       PCIE2  // Pin change interrupt enable pin
#define CONTROL_INT_vect  PCINT2_vect
#define CONTROL_PCMSK     PCMSK2 // Pin change interrupt register
#define CONTROL_MASK      ((1<<CONTROL_RESET_BIT)|(1<<CONTROL_FEED_HOLD_BIT)|(1<<CONTROL_CYCLE_START_BIT)|(1<<CONTROL_SAFETY_DOOR_BIT))

// Define probe switch input pin.
#define PROBE_DDR       DDRK
#define PROBE_PIN       PINK
#define PROBE_PORT      PORTK
#define PROBE_BIT       7  // MEGA2560 Analog Pin 15
#define PROBE_MASK      (1<<PROBE_BIT)

// Advanced Configuration Below You should not need to touch these variables
// Set Timer up to use TIMER4B which is attached to Digital Pin 7
#define SPINDLE_PWM_MAX_VALUE     1024.0 // Translates to about 1.9 kHz PWM frequency at 1/8 prescaler
#ifndef SPINDLE_PWM_MIN_VALUE
#define SPINDLE_PWM_MIN_VALUE   1   // Must be greater than zero.
#endif
#define SPINDLE_PWM_OFF_VALUE     0
#define SPINDLE_PWM_RANGE         (SPINDLE_PWM_MAX_VALUE-SPINDLE_PWM_MIN_VALUE)
#define SPINDLE_TCCRA_REGISTER		TCCR4A
#define SPINDLE_TCCRB_REGISTER		TCCR4B
#define SPINDLE_OCR_REGISTER	  	OCR4B
#define SPINDLE_COMB_BIT			    COM4B1

// 1/8 Prescaler, 16-bit Fast PWM mode
#define SPINDLE_TCCRA_INIT_MASK ((1<<WGM40) | (1<<WGM41))
#define SPINDLE_TCCRB_INIT_MASK ((1<<WGM42) | (1<<WGM43) | (1<<CS41))
#define SPINDLE_OCRA_REGISTER   OCR4A // 16-bit Fast PWM mode requires top reset value stored here.
#define SPINDLE_OCRA_TOP_VALUE  0x0400 // PWM counter reset value. Should be the same as PWM_MAX_VALUE in hex.

// Define spindle output pins.
#define SPINDLE_PWM_DDR		DDRH
#define SPINDLE_PWM_PORT  PORTH
#define SPINDLE_PWM_BIT		4 // MEGA2560 Digital Pin 7

#endif

#ifdef CPU_MAP_2560_RAMPS_BOARD // (Arduino Mega 2560) with Ramps 1.4 Board
#include "nuts_bolts.h"

// Serial port interrupt vectors
#define SERIAL_RX USART0_RX_vect
#define SERIAL_UDRE USART0_UDRE_vect




// Define ports and pins
#define DDR(port) DDR##port
#define _DDR(port) DDR(port)
#define PORT(port) PORT##port
#define _PORT(port) PORT(port)
#define PIN(pin) PIN##pin
#define _PIN(pin) PIN(pin)

// Define step pulse output pins.

#define STEP_PORT_0 B
#define STEP_PORT_1 H
#define STEP_PORT_2 H
#define STEP_BIT_0 6
#define STEP_BIT_1 5
#define STEP_BIT_2 6
#define _STEP_BIT(i) STEP_BIT_##i
#define STEP_BIT(i) _STEP_BIT(i)
#define STEP_DDR(i) _DDR(STEP_PORT_##i)
#define _STEP_PORT(i) _PORT(STEP_PORT_##i)
#define STEP_PORT(i) _STEP_PORT(i)
#define STEP_PIN(i) _PIN(STEP_PORT_##i)

// Define step direction output pins.
#define DIRECTION_PORT_0 B
#define DIRECTION_PORT_1 H
#define DIRECTION_PORT_2 H
#define DIRECTION_BIT_0 5
#define DIRECTION_BIT_1 4
#define DIRECTION_BIT_2 3
#define _DIRECTION_BIT(i) DIRECTION_BIT_##i
#define DIRECTION_BIT(i) _DIRECTION_BIT(i)
#define DIRECTION_DDR(i) _DDR(DIRECTION_PORT_##i)
#define _DIRECTION_PORT(i) _PORT(DIRECTION_PORT_##i)
#define DIRECTION_PORT(i) _DIRECTION_PORT(i)
#define DIRECTION_PIN(i) _PIN(DIRECTION_PORT_##i)

// Define stepper driver enable/disable output pin.
#define STEPPER_ENABLE_PORT_0 C
#define STEPPER_ENABLE_PORT_1 C
#define STEPPER_ENABLE_PORT_2 L
#define STEPPER_ENABLE_BIT_0 2
#define STEPPER_ENABLE_BIT_1 1
#define STEPPER_ENABLE_BIT_2 7
#define STEPPER_ENABLE_BIT(i) STEPPER_ENABLE_BIT_##i
#define STEPPER_ENABLE_DDR(i) _DDR(STEPPER_ENABLE_PORT_##i)
#define STEPPER_ENABLE_PORT(i) _PORT(STEPPER_ENABLE_PORT_##i)
#define STEPPER_ENABLE_PIN(i) _PIN(STEPPER_ENABLE_PORT_##i)

// Define stepper driver sleep output pin.
#define STEPPER_SLEEP_PORT_0 D
#define STEPPER_SLEEP_PORT_1 D
#define STEPPER_SLEEP_PORT_2 E
#define STEPPER_SLEEP_BIT_0 3
#define STEPPER_SLEEP_BIT_1 2
#define STEPPER_SLEEP_BIT_2 5
#define STEPPER_SLEEP_BIT(i) STEPPER_SLEEP_BIT_##i
#define STEPPER_SLEEP_DDR(i) _DDR(STEPPER_SLEEP_PORT_##i)
#define STEPPER_SLEEP_PORT(i) _PORT(STEPPER_SLEEP_PORT_##i)
#define STEPPER_SLEEP_PIN(i) _PIN(STEPPER_SLEEP_PORT_##i)

// Define stepper driver reset output pin.
#define STEPPER_RESET_PORT_0 C
#define STEPPER_RESET_PORT_1 D
#define STEPPER_RESET_PORT_2 L
#define STEPPER_RESET_BIT_0 6
#define STEPPER_RESET_BIT_1 7
#define STEPPER_RESET_BIT_2 0
#define STEPPER_RESET_BIT(i) STEPPER_RESET_BIT_##i
#define STEPPER_RESET_DDR(i) _DDR(STEPPER_RESET_PORT_##i)
#define STEPPER_RESET_PORT(i) _PORT(STEPPER_RESET_PORT_##i)
#define STEPPER_RESET_PIN(i) _PIN(STEPPER_RESET_PORT_##i)


// Define homing/hard limit switch input pins and limit interrupt vectors.
#define MIN_LIMIT_PORT_0 F
#define MIN_LIMIT_PORT_1 F
#define MIN_LIMIT_PORT_2 A
#define MIN_LIMIT_BIT_0 6
#define MIN_LIMIT_BIT_1 7
#define MIN_LIMIT_BIT_2 7
#define _MIN_LIMIT_BIT(i) MIN_LIMIT_BIT_##i
#define MIN_LIMIT_BIT(i) _MIN_LIMIT_BIT(i)
#define MIN_LIMIT_DDR(i) _DDR(MIN_LIMIT_PORT_##i)
#define MIN_LIMIT_PORT(i) _PORT(MIN_LIMIT_PORT_##i)
#define MIN_LIMIT_PIN(i) _PIN(MIN_LIMIT_PORT_##i)


#define MAX_LIMIT_PORT_0 A
#define MAX_LIMIT_PORT_1 A
#define MAX_LIMIT_PORT_2 A
#define MAX_LIMIT_BIT_0 3
#define MAX_LIMIT_BIT_1 0
#define MAX_LIMIT_BIT_2 6
#define _MAX_LIMIT_BIT(i) MAX_LIMIT_BIT_##i
#define MAX_LIMIT_BIT(i) _MAX_LIMIT_BIT(i)
#define MAX_LIMIT_DDR(i) _DDR(MAX_LIMIT_PORT_##i)
#define MAX_LIMIT_PORT(i) _PORT(MAX_LIMIT_PORT_##i)
#define MAX_LIMIT_PIN(i) _PIN(MAX_LIMIT_PORT_##i)


//  #define LIMIT_INT       PCIE0  // Pin change interrupt enable pin
//  #define LIMIT_INT_vect  PCINT0_vect
//  #define LIMIT_PCMSK     PCMSK0 // Pin change interrupt register
//  #define LIMIT_MASK ((1<<X_LIMIT_BIT)|(1<<Y_LIMIT_BIT)|(1<<Z_LIMIT_BIT)) // All limit bits
#define DISABLE_HW_LIMITS

// Define user-control CONTROLs (cycle start, reset, feed hold) input pins.
// NOTE: All CONTROLs pins must be on the same port and not on a port with other input pins (limits).
#define CONTROL_DDR       DDRK
#define CONTROL_PIN       PINK
#define CONTROL_PORT      PORTK
#define CONTROL_RESET_BIT         3  // MEGA2560 Analog Pin 11
#define CONTROL_FEED_HOLD_BIT     4  // MEGA2560 Analog Pin 12
#define CONTROL_CYCLE_START_BIT   5  // MEGA2560 Analog Pin 13
#define CONTROL_SAFETY_DOOR_BIT   6  // MEGA2560 Analog Pin 14
#define CONTROL_INT       PCIE2  // Pin change interrupt enable pin
#define CONTROL_INT_vect  PCINT2_vect
#define CONTROL_PCMSK     PCMSK2 // Pin change interrupt register
#define CONTROL_MASK      ((1<<CONTROL_RESET_BIT)|(1<<CONTROL_FEED_HOLD_BIT)|(1<<CONTROL_CYCLE_START_BIT)|(1<<CONTROL_SAFETY_DOOR_BIT))

// Define probe switch input pin.
#define PROBE_DDR       DDRK
#define PROBE_PIN       PINK
#define PROBE_PORT      PORTK
#define PROBE_BIT       7  // MEGA2560 Analog Pin 15
#define PROBE_MASK      (1<<PROBE_BIT)


// Advanced Configuration Below You should not need to touch these variables
// Set Timer up to use TIMER4B which is attached to Digital Pin 8 - Ramps 1.4 12v output with heat sink
#define SPINDLE_PWM_MAX_VALUE     1024.0 // Translates to about 1.9 kHz PWM frequency at 1/8 prescaler
#ifndef SPINDLE_PWM_MIN_VALUE
#define SPINDLE_PWM_MIN_VALUE   1   // Must be greater than zero.
#endif
#define SPINDLE_PWM_OFF_VALUE     0
#define SPINDLE_PWM_RANGE         (SPINDLE_PWM_MAX_VALUE-SPINDLE_PWM_MIN_VALUE)

//rb THIS HAS TO BE CHANGED TO A DIFFERENT PIN! OC2A is for D10 (PB4)
//Control Digital Pin 6 which is Servo 2 signal pin on Ramps 1.4 board
//#define SPINDLE_TCCRA_REGISTER    TCCR4A
//#define SPINDLE_TCCRB_REGISTER    TCCR4B
//#define SPINDLE_OCR_REGISTER      OCR4C
//#define SPINDLE_COMB_BIT          COM4C1
#define SPINDLE_TCCRA_REGISTER    TCCR2A
#define SPINDLE_TCCRB_REGISTER    TCCR2B
#define SPINDLE_OCR_REGISTER      OCR2A
#define SPINDLE_COMB_BIT          COM2A1

// 1/8 Prescaler, 16-bit Fast PWM mode
#define SPINDLE_TCCRA_INIT_MASK ((1<<WGM40) | (1<<WGM41))
#define SPINDLE_TCCRB_INIT_MASK ((1<<WGM42) | (1<<WGM43) | (1<<CS41))
#define SPINDLE_OCRA_REGISTER   OCR4A // 16-bit Fast PWM mode requires top reset value stored here.
#define SPINDLE_OCRA_TOP_VALUE  0x0400 // PWM counter reset value. Should be the same as PWM_MAX_VALUE in hex.

// Define spindle output pins.
#define SPINDLE_PWM_DDR   DDRB
#define SPINDLE_PWM_PORT  PORTB
#define SPINDLE_PWM_BIT   4 // MEGA2560 Digital Pin 10 - 12v output

// Define flood and mist coolant enable output pins.
#define SPINDLE_ENABLE_DDR   DDRF
#define SPINDLE_ENABLE_PORT  PORTF
#define SPINDLE_ENABLE_BIT   0 // MEGA2560 Analog Pin 0 - 12v output
#define SPINDLE_DIRECTION_DDR    DDRG
#define SPINDLE_DIRECTION_PORT   PORTG
#define SPINDLE_DIRECTION_BIT    2// MEGA2560 Digital Pin 39 - MegaPi P15 5x2 pin1


// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_DDR   DDRA
#define COOLANT_FLOOD_PORT  PORTA
#define COOLANT_FLOOD_BIT   2 // MEGA2560 Digital Pin 24
#define COOLANT_MIST_DDR    DDRA
#define COOLANT_MIST_PORT   PORTA
#define COOLANT_MIST_BIT    0 // MEGA2560 Digital Pin 22


#endif
/*
  #ifdef CPU_MAP_CUSTOM_PROC
  // For a custom pin map or different processor, copy and edit one of the available cpu
  // map files and modify it to your needs. Make sure the defined name is also changed in
  // the config.h file.
  #endif
*/

#endif