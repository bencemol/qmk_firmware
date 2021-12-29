/* Copyright 2015-2021 Jack Humbert
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
#include "keymap_steno.h"

// Tap Dance declarations
enum {
    TD_LBRC_RBRC_BSLS,
};

void dance_lbrc_rbrc_bsls(qk_tap_dance_state_t *state, void *user_data) {
    switch(state->count) {
        case 1:
            tap_code(KC_LBRC);
            break;
        case 2:
            tap_code(KC_RBRC);
            break;
        case 3:
            tap_code(KC_BSLS);
            break;
        default:
            break;
    }
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LBRC_RBRC_BSLS] = ACTION_TAP_DANCE_FN(dance_lbrc_rbrc_bsls),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_5x12(
        KC_ESC, KC_1,    KC_2,    KC_3,  KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    TD(TD_LBRC_RBRC_BSLS),
        KC_DEL,  KC_A,    KC_S,    KC_D,  KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, TT(2), MO(3), KC_SPC, KC_SPC, MO(2), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
	[1] = LAYOUT_ortho_5x12(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_BSLS,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(4), KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),
	[2] = LAYOUT_ortho_5x12(
        KC_GRV,  KC_1,    KC_2,    KC_3,  KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TRNS, KC_1,    KC_2,    KC_3,  KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_MINS, KC_EQL,  KC_LBRC, KC_NO,   KC_NO,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NUHS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, MO(4), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
    ),
	[3] = LAYOUT_ortho_5x12(
        KC_F1, KC_F2,  KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10, KC_F11, KC_F12,
        KC_NO, RESET,  DEBUG,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   TERM_ON, TERM_OFF, KC_NO,  KC_NO,  KC_NO,
        KC_NO, KC_NO,  RGB_TOG, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, DF(0),   DF(4),    KC_NO,  KC_NO,  KC_NO,
        KC_NO, MUV_DE, MUV_IN, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  KC_NO,   KC_NO,    KC_NO,  KC_NO,  KC_NO,
        KC_NO, KC_NO,  KC_NO,  KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,  KC_NO
    ),
    [4] = LAYOUT_ortho_5x12(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
        STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
        XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
        XXXXXXX, XXXXXXX, DF(0),   STN_A,   XXXXXXX, STN_O,   XXXXXXX, STN_E,   STN_U,   STN_PWR, STN_RE1, STN_RE2
    )
};
