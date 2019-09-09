## Shiftout for AVR

An `shiftout` implementation for AVR microcontrollers with `avr-gcc` support for multiple ICs.

[![GPL Licence](https://badges.frapsoft.com/os/gpl/gpl.png?v=103)](https://opensource.org/licenses/GPL-3.0/)


## Why ?

I've noticed there're many implementations available but neither one of them are suitable for
an issue I faced into. I wanted to have a relly small codebase with support of multiple hardware implementations. It had to be something that I can optimize and understand well enough to get rid of some parts of code any time I need it. Then I've decided to make a single library with simple but powerful codebase that I can share with everyone who could have the same problem I had.

## Features

  * AVR-GCC support
  * Small codebase and as a result - tiny/shiny binary
  * Different hardware implementations support (tested with 74HC164 and 74HC595)
  * Multiple ICS in a single runtime support (on different ports of an AVR)
  * Support three and two wire connections

## Known issues

  * Every IC should be configured individualy if you're intended to use two or
  more of them on a single port.
  * To keep codebase really small and simple it has no support of series, I mean,
  ICs connected in series. It is the idea for another project.

## Installation

Installation process is pretty simple, just copy `shiftout.c` and `shiftout.h` into your
projct's folder.
Don't forget to configure your build system to use the new files you've copied.

## Usage


## License

  This program is free software: you can redistribute it and/or modify<br>
  it under the terms of the GNU General Public License as published by<br>
  the Free Software Foundation, either version 3 of the License, or<br>
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,<br>
  but WITHOUT ANY WARRANTY; without even the implied warranty of<br>
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the<br>
  GNU General Public License for more details.<br>

  You should have received a copy of the GNU General Public License<br>
  along with this program.  If not, see <https://www.gnu.org/licenses/>.




