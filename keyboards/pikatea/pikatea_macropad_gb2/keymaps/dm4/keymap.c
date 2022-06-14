/* Copyrigh 2022 Jack Kester
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_number {
    _BASE,
    _LOWER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_all(
        KC_1,
        KC_2,
        KC_3,
        KC_4,
        LT(_LOWER, KC_5),
        // Knob
        KC_MUTE
    ),
    [_LOWER] = LAYOUT_all(
        KC_BRMD,
        KC_BRMU,
        LSFT(KC_3),
        RESET,
        _______,
        // Knob
        _______
    )
};

bool encoder_update_user(uint8_t index, bool counterclockwise) {
    if (index == 0) {
        if (get_highest_layer(layer_state|default_layer_state) > 0) {
            /* Layer 1 */
            if (counterclockwise) {
                tap_code_delay(KC_BRMD, 10);
            } else {
                tap_code_delay(KC_BRMU, 10);
            }
        } else {
            /* Layer 0 */
            if (counterclockwise) {
                tap_code_delay(KC_VOLD, 10);
            } else {
                tap_code_delay(KC_VOLU, 10);
            }
        }
        return false;
    }

    return true;
}
