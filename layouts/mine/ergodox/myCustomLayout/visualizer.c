
/*
 Copyright 2017 Fred Sundvik
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 2 of the License, or
 (at your option) any later version.
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "simple_visualizer.h"
#include "util.h"
#include "lcd_keyframes.h"
#include "lcd_backlight_keyframes.h"

enum ergodox_layers { _QWERTY, _COLEMAK, _FUNCTIONS, _NUMPAD, _GAMING };

// This function should be implemented by the keymap visualizer
// Don't change anything else than state->target_lcd_color and state->layer_text as that's the only thing
// that the simple_visualizer assumes that you are updating
// Also make sure that the buffer passed to state->layer_text remains valid until the previous animation is
// stopped. This can be done by either double buffering it or by using constant strings
static void get_visualizer_layer_and_color(visualizer_state_t* state) {
    uint8_t saturation = 123;
    uint8_t brightness = 123;
    uint8_t layer      = biton32(state->status.layer);

    lcd_backlight_brightness(255);

    switch(layer){
        case _QWERTY:
          state->layer_text = "QWERTY";
          state->target_lcd_color = LCD_COLOR(0, saturation, 0);
          break;
        case _FUNCTIONS:
          state->layer_text = "FUNCTION";
          state->target_lcd_color = LCD_COLOR(0, saturation, brightness);
          break;
        case _NUMPAD:
          state->layer_text = "NUMPAD";
          state->target_lcd_color = LCD_COLOR(150, saturation, brightness);
          break;
        case _GAMING:
          state->layer_text = "GAMING";
          state->target_lcd_color = LCD_COLOR(84, saturation, brightness);
          break;
        case _COLEMAK:
          state->layer_text = "COLEMAK";
          state->target_lcd_color = LCD_COLOR(40, saturation, brightness);
          break;
        default:
          state->layer_text = "NONE";
    }

    if (state->status.leds & (1u << USB_LED_CAPS_LOCK)) {
      state->target_lcd_color = LCD_COLOR(190, 200, brightness);
    }
}
