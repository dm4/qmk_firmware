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
    _0,
    _1,
    _2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_0] = LAYOUT_all(
        KC_MPRV,
        LT(_1, KC_MPLY),
        KC_MNXT,
        KC_MUTE,
        LT(_2, KC_MUTE),
        // Knob
        KC_MUTE
    ),
    [_1] = LAYOUT_all(
        LSFT(KC_LEFT),
        _______,
        LSFT(KC_RIGHT),
        _______,
        _______,
        // Knob
        _______
    ),
    [_2] = LAYOUT_all(
        _______,
        _______,
        QK_MAKE,
        QK_BOOT,
        _______,
        // Knob
        _______
    )
};

bool encoder_update_user(uint8_t index, bool counterclockwise) {
    if (index == 0) {
        if (get_highest_layer(layer_state|default_layer_state) > 0) {
            /* Layer > 0 */
            if (counterclockwise) {
                register_code(KC_LSFT);
                tap_code(KC_LEFT);
                unregister_code(KC_LSFT);
            } else {
                register_code(KC_LSFT);
                tap_code(KC_RIGHT);
                unregister_code(KC_LSFT);
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
