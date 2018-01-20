/*
  Matrix.h - Max7219 LED Matrix library for Arduino & Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef Matrix_h
#define Matrix_h

#include <inttypes.h>

/******************************************************************************
 * Definitions
 ******************************************************************************/

// Matrix registers
#define REG_NOOP   0x00
#define REG_DIGIT0 0x01
#define REG_DIGIT1 0x02
#define REG_DIGIT2 0x03
#define REG_DIGIT3 0x04
#define REG_DIGIT4 0x05
#define REG_DIGIT5 0x06
#define REG_DIGIT6 0x07
#define REG_DIGIT7 0x08
#define REG_DECODEMODE  0x09
#define REG_INTENSITY   0x0A
#define REG_SCANLIMIT   0x0B
#define REG_SHUTDOWN    0x0C
#define REG_DISPLAYTEST 0x0F

class Sprite;

class Matrix
{
  private:
    uint8_t _pinData;
    uint8_t _pinClock;
    uint8_t _pinLoad;

    uint8_t* _buffer;
    uint8_t _screens;
    uint8_t _maximumX;

    void putByte(uint8_t);
    void syncRow(uint8_t);

  public:
    Matrix(uint8_t, uint8_t, uint8_t, uint8_t = 1);
    void setRegister(uint8_t, uint8_t);
    void setBrightness(uint8_t);
    void setScanLimit(uint8_t);
    void buffer(uint8_t, uint8_t, uint8_t);
    void write(uint8_t, uint8_t, uint8_t);
    void write(uint8_t, uint8_t, Sprite);
    void clear(void);
};

#endif


