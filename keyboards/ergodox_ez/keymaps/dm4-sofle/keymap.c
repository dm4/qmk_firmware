#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    _0,  // default layer
    _1,  // layer 1
    _2,  // layer 2
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
    EMAIL,
};

// clang-format off
// Ergodox EZ Default Layout: https://configure.zsa.io/ergodox-ez/layouts/default/latest/0
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc/`  |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |  L2  | LAlt | LGui |                                       |  L1  | L1Sh |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Space|  BS  |------|       |------|  Enter |Space |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_0] = LAYOUT_ergodox_pretty(
  // left hand
  QK_GESC, KC_1,    KC_2,     KC_3,    KC_4,    KC_5,  _______,  /**/  _______,  KC_6,  KC_7,   KC_8,     KC_9,    KC_0,              KC_MINS,
  KC_TAB,  KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,  _______,  /**/  _______,  KC_Y,  KC_U,   KC_I,     KC_O,    KC_P,              KC_BSLS,
  KC_LCTL, KC_A,    KC_S,     KC_D,    KC_F,    KC_G,            /**/            KC_H,  KC_J,   KC_K,     KC_L,    LT(_2, KC_SCLN), GUI_T(KC_QUOT),
  KC_LSFT, KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,  _______,  /**/  _______,  KC_N,  KC_M,   KC_COMM,  KC_DOT,  CTL_T(KC_SLSH),    KC_RSFT,
  _______, _______, MO(_2),   KC_LALT, KC_LGUI,                  /**/                   MO(_1), LM(_1, MOD_LSFT), _______, _______,   _______,
                                              _______, _______,  /**/  _______, _______,
                                                       _______,  /**/  _______,
                                      KC_SPC, KC_BSPC, _______,  /**/  _______, KC_ENT, KC_SPC
),
/* Keymap 1: Layer 1
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |    `    |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |    =   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      | Lclk |  MUp | Rclk |      |      |           |      |      |      |  Up  |   [  |   ]  |    =   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      | MLeft| MDown|MRight| Home |------|           |------| PgUp | Left | Down | Right|      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      | End  |      |           |      | PgDn | Prev | Play | Next |  F11 |  F12   |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Bootl | Make |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |  Del |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_1] = LAYOUT_ergodox_pretty(
  // left hand
  KC_GRAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_EQL,
  _______,  _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,     _______, _______, _______, KC_UP,   KC_LBRC,  KC_RBRC,  KC_EQL,
  _______,  _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_HOME,                       KC_PGUP, KC_LEFT, KC_DOWN, KC_RIGHT, _______,  _______,
  _______,  _______, _______, _______, _______, KC_END,  _______,     _______, KC_PGDN, KC_MPRV, KC_MPLY, KC_MNXT,  KC_F11,   KC_F12,
  QK_BOOT,  QK_MAKE, QK_BOOT, QK_MAKE, _______,                                         _______, _______, _______,  _______,  _______,
                                                _______, _______,     _______, _______,
                                                         _______,     _______,
                                       _______, KC_DEL,  _______,     _______, _______, _______
),
/* Keymap 2
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |   +  |   -  |   *  |   /  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   .  |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_2] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_7,    KC_8,    KC_9,    _______, _______,
  _______, _______, _______, _______, _______, _______,                       _______, KC_4,    KC_5,    KC_6,    _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,
  _______, _______, _______, _______, _______,                                         KC_0,    KC_PDOT, _______, _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
            case EMAIL:
                SEND_STRING("sunrisedm4@gmail.com");
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
