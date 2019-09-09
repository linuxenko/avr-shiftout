/*********************************************************************************
* File Name     : shiftout.h
* Created By    : Svetlana Linuxenko
* Creation Date : [2019-09-07 19:57]
* Last Modified : [2019-09-09 17:04]
* Description   : Shiftout implementation for avr-gcc
**********************************************************************************/

/*
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _SHIFTOUT_H_
#define _SHIFTOUT_H_

#include <inttypes.h>

#ifndef LSBFIRST
#define LSBFIRST 0
#define MBFIRST 1
#endif

enum _SHIFT_IC_TYPE {
  IC_TYPE_HC164,
  IC_TYPE_HC595
};

typedef struct _shift_ic {
  volatile uint8_t *dataPort;
  uint8_t dataPin;
  uint8_t clockPin;
  uint8_t enablePin;
  uint8_t type;
} ShiftIC;

/*
 * Creates a 3 wire IC object that has an enable/latch/MR pin if you're
 * intended to use it.
 */
ShiftIC * createShift(ShiftIC *ic,
    volatile uint8_t *dirPort, volatile uint8_t *dataPort,
    uint8_t dataPin, uint8_t clockPin, uint8_t enablePin);

/*
 * The object for a two wire IC
 */
ShiftIC * createShift2(ShiftIC *ic,
    volatile uint8_t *dirPort, volatile uint8_t *dataPort,
    uint8_t dataPin, uint8_t clockPin);

/*
 * An interface to the IC.
 */
void shiftOut(ShiftIC *ic, uint8_t bitOrder, uint8_t val);

/* Depending on the IC type and its usage it could be extremely
 * helpful to control the MR/latch/enable pin externally.
 *
 * Please note ! By default it is always OFF so you should consider to enable
 * the pin before starting to use an IC.
 */
void shiftOn(ShiftIC *ic);
void shiftOff(ShiftIC *ic);

#endif
