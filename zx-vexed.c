/*  Vexed - Vexed.c "The Main Stuff, i.e. event handlers, loops, etc"
    Copyright (C) 1999 James McCombe (cybertube@earthling.net)
	 Copyright (C) 2006 The Vexed Source Forge Project Team

    This file is part of Vexed.

    Vexed is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Vexed is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Vexed; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

//
// This version rewritten for ZX Spectrum in z88dk / sdcc C
// R. Lesley; Feb 2025
//

#include <arch/zx.h>

#include <input.h>

#include "zxspectrum/screen.h"
#include "zxspectrum/keyboard.h"

void DrawWelcomeScreen(void);
void DrawWelcomeScreen(void)
{
	// turn off keyboard repeat
	set_keyboard_repeat_delay(0);
	set_keyboard_repeat(0);

    zx_border(INK_BLACK);
	zx_cls(INK_WHITE | PAPER_BLACK);

    /*
    // single-width logo
    print_string_attr_at(3, 7, INK_BLACK | PAPER_WHITE, "V V EEE X X EEE DD ");
    print_string_attr_at(4, 7, INK_BLACK | PAPER_WHITE, "V V E   X X E   D D");
    print_string_attr_at(5, 7, INK_BLACK | PAPER_WHITE, "V V EE   X  EE  D D");
    print_string_attr_at(6, 7, INK_BLACK | PAPER_WHITE, "V V E   X X E   D D");
    print_string_attr_at(7, 7, INK_BLACK | PAPER_WHITE, " V  EEE X X EEE DD ");
    */

    print_string_attr_at(10, 2, INK_WHITE | PAPER_BLACK, "VV VV EEEEE XX XX EEEEE DDDD ");
    print_string_attr_at(11, 2, INK_WHITE | PAPER_BLACK, "VV VV E     XX XX E     D   D");
    print_string_attr_at(12, 2, INK_WHITE | PAPER_BLACK, "VV VV E     XX XX E     D   D");
    print_string_attr_at(13, 2, INK_WHITE | PAPER_BLACK, "VV VV EEE    XXX  EEE   D   D");
    print_string_attr_at(14, 2, INK_WHITE | PAPER_BLACK, "VV VV E     XX XX E     D   D");
    print_string_attr_at(15, 2, INK_WHITE | PAPER_BLACK, " VVV  E     XX XX E     D   D");
    print_string_attr_at(16, 2, INK_WHITE | PAPER_BLACK, "  V   EEEEE XX XX EEEEE DDDD ");

}

void main(void);
void main(void)
{
    ubyte keypress = 0;

    print_string_at(20, 2, "Press ENTER");
    while (keypress != (ubyte)INKEY_ENTER) {
        keypress = in_inkey();
    };
    DrawWelcomeScreen();
}
