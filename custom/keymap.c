/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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
#include "version.h"

// New macro for my own keycodes. Using CUSTOM_SAFE_RANGE as lang_shift module requires it.
#define CUSTOM_SAFE_RANGE SAFE_RANGE

// Use modules
#include "lang_shift/include.h"

// Handy macro for better (not-so-wide) layout definition
#define MY_layout( \
    k00, k01, k02, k03, k04, k05, k06, \
    k10, k11, k12, k13, k14, k15, k16, \
    k20, k21, k22, k23, k24, k25, k26, \
    k30, k31, k32, k33, k34, k35,      \
    k40, k41, k42, k43, k44,           \
    k53, \
    k50, k51, k52, \
    \
    k60, k61, k62, k63, k64, k65, k66, \
    k70, k71, k72, k73, k74, k75, k76, \
    k80, k81, k82, k83, k84, k85, k86, \
    k91, k92, k93, k94, k95, k96, \
    ka2, ka3, ka4, ka5, ka6, \
    kb3,\
    kb4, kb5, kb6 \
) \
LAYOUT_moonlander( \
    k00, k01, k02, k03, k04, k05, k06,   k60, k61, k62, k63, k64, k65, k66, \
    k10, k11, k12, k13, k14, k15, k16,   k70, k71, k72, k73, k74, k75, k76, \
    k20, k21, k22, k23, k24, k25, k26,   k80, k81, k82, k83, k84, k85, k86, \
    k30, k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, k96, \
    k40, k41, k42, k43, k44,      k53,   kb3,      ka2, ka3, ka4, ka5, ka6, \
                        k50, k51, k52,   kb4, kb5, kb6 \
)

// List of keyboard layers
enum layers {
    // Next 4 layers are required exactly in this order for lang_shift module to work
    L_EN = 0,  // Base English
    L_EN_S,    // English with Shift
    L_RU,      // Base Russian
    L_RU_S,    // Russian with Shift

    // Here new layers can be added

    L_SPECIAL, // The special layer: various configuration keycodes
};

// Macro for layer modificators
#define MO_SPCL MO(L_SPECIAL)

enum custom_keycodes {
    VRSN = CUSTOM_SAFE_RANGE,
    LANG_M,
};

// List of keymaps for each layer
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    // Base English
    [L_EN] = MY_layout( 
        /* LEFT HALF */ 
        KC_ESC,  AG_EXCL, EN_AT,   EN_HASH, EN_DLR,  AG_PERC, AG_DQUO, 
        KC_TAB,  EN_Q,    EN_W,    EN_E,    EN_R,    EN_T,    KC_GRV, 
        SFT_N_O, EN_A,    EN_S,    EN_D,    EN_F,    EN_G,    EN_EQL, 
        SFT_N,   EN_Z,    EN_X,    EN_C,    EN_V,    EN_B, 
        KC_LCTL, KC_LGUI, KC_LALT, _______, _______, 
        KC_DEL, /* LEFT RED THUMB KEY */ 
        SFT_N,   KC_BSPC, KC_LCTL, /* LEFT THUMB KEYS */ 
        
        /* RIGHT HALF */ 
        EN_CIRC, AG_SCLN, EN_AMPR, AG_ASTR, AG_COLN, AG_QUES, EN_SLSH, 
        AG_PLUS, EN_Y,    EN_U,    EN_I,    EN_O,    EN_P,    EN_BSLS, 
        AG_MINS, EN_H,    EN_J,    EN_K,    EN_L,    EN_SCLN, EN_QUOT, 
                 EN_N,    EN_M,    EN_COMM, EN_DOT,  EN_SLSH, XXXXXXX, 
                          _______, _______, WIN_EN,  _______, MO_SPCL, 
                          KC_LALT, /* RIGHT RED THUMB KEY */ 
                          KC_ENT,  LA_CHNG, KC_SPC /* RIGHT THUMB KEYS */ 
    ),

    // English with Shift
    [L_EN_S] = MY_layout( 
        /* LEFT HALF */ 
        KC_ESC,  AG_EXCL, EN_AT,   RU_NUME, EN_DLR,  AG_PERC, EN_QUOT, 
        KC_TAB,  EN_S_Q,  EN_S_W,  EN_S_E,  EN_S_R,  EN_S_T,  KC_GRV, 
        SFT_N_O, EN_S_A,  EN_S_S,  EN_S_D,  EN_S_F,  EN_S_G,  EN_EQL, 
        SFT_N,   EN_S_Z,  EN_S_X,  EN_S_C,  EN_S_V,  EN_S_B, 
        KC_LCTL, KC_LGUI, KC_LALT, _______, _______, 
        KC_DEL, /* LEFT RED THUMB KEY */ 
        SFT_N,   KC_BSPC, KC_LCTL, /* LEFT THUMB KEYS */ 
        
        /* RIGHT HALF */ 
        EN_TILD, AG_SCLN, EN_AMPR, AG_ASTR, AG_COLN, AG_QUES, EN_BSLS, 
        AG_PLUS, EN_S_Y,  EN_S_U,  EN_S_I,  EN_S_O,  EN_S_P,  EN_PIPE, 
        AG_MINS, EN_S_H,  EN_S_J,  EN_S_K,  EN_S_L,  EN_COLN, EN_DQUO, 
                 EN_S_N,  EN_S_M,  EN_LT,   EN_GT,   EN_QUES, XXXXXXX, 
                          _______, _______, WIN_EN,  _______, MO_SPCL, 
                          KC_LALT, /* RIGHT RED THUMB KEY */ 
                          KC_ENT,  LA_CHNG, KC_SPC /* RIGHT THUMB KEYS */ 
    ),
    
    // Base Russian
    [L_RU] = MY_layout( 
        /* LEFT HALF */ 
        KC_ESC,  AG_EXCL, EN_AT,   EN_HASH, EN_DLR,  AG_PERC, AG_DQUO, 
        KC_TAB,  RU_J,    RU_TS,   RU_U,    RU_K,    RU_JE,   KC_GRV, 
        SFT_N_O, RU_F,    RU_Y,    RU_V,    RU_A,    RU_P,    RU_EQL, 
        SFT_N,   RU_JA,   RU_CH,   RU_S,    RU_M,    RU_I, 
        KC_LCTL, KC_LGUI, KC_LALT, _______, _______, 
        KC_DEL, /* LEFT RED THUMB KEY */ 
        SFT_N,   KC_BSPC, KC_LCTL, /* LEFT THUMB KEYS */ 
        
        /* RIGHT HALF */ 
        EN_CIRC, AG_SCLN, EN_AMPR, AG_ASTR, AG_COLN, AG_QUES, EN_SLSH, 
        AG_PLUS, RU_N,    RU_G,    RU_SH,   RU_SC,   RU_Z,    RU_H, 
        AG_MINS, RU_R,    RU_O,    RU_L,    RU_D,    RU_ZH,   RU_E, 
                 RU_T,    RU_SF,   RU_B,    RU_JU,   RU_DOT,  XXXXXXX, 
                          _______, _______, WIN_EN,  _______, MO_SPCL, 
                          KC_LALT, /* RIGHT RED THUMB KEY */ 
                          KC_ENT,  LA_CHNG, KC_SPC /* RIGHT THUMB KEYS */ 
    ),

    // Russian with Shift
    [L_RU_S] = MY_layout( 
        /* LEFT HALF */ 
        KC_ESC,  AG_EXCL, EN_AT,   RU_NUME, EN_DLR,  AG_PERC, EN_QUOT, 
        KC_TAB,  RU_S_J,  RU_S_TS, RU_S_U,  RU_S_K,  RU_S_JE, KC_GRV, 
        SFT_N_O, RU_S_F,  RU_S_Y,  RU_S_V,  RU_S_A,  RU_S_P,  RU_EQL, 
        SFT_N,   RU_S_JA, RU_S_CH, RU_S_S,  RU_S_M,  RU_S_I, 
        KC_LCTL, KC_LGUI, KC_LALT, _______, _______, 
        KC_DEL, /* LEFT RED THUMB KEY */ 
        SFT_N,   KC_BSPC, KC_LCTL, /* LEFT THUMB KEYS */ 
        
        /* RIGHT HALF */ 
        EN_TILD, AG_SCLN, EN_AMPR, AG_ASTR, AG_COLN, AG_QUES, EN_BSLS, 
        AG_PLUS, RU_S_N,  RU_S_G,  RU_S_SH, RU_S_SC, RU_S_Z,  RU_S_H, 
        AG_MINS, RU_S_R,  RU_S_O,  RU_S_L,  RU_S_D,  RU_S_ZH, RU_S_E, 
                 RU_S_T,  RU_S_SF, RU_S_B,  RU_S_JU, RU_COMM, XXXXXXX, 
                          _______, _______, WIN_EN,  _______, MO_SPCL, 
                          KC_LALT, /* RIGHT RED THUMB KEY */ 
                          KC_ENT,  LA_CHNG, KC_SPC /* RIGHT THUMB KEYS */ 
    ),

    // Special layer mostly for configuration keycodes
    [L_SPECIAL] = LAYOUT_moonlander(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};

const uint16_t PROGMEM test_combo1[] = {AG_PLUS, AG_MINS, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {LA_CHNG, KC_SPC, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, MO_SPCL),
    COMBO(test_combo2, LA_SYNC),
};

void press_arbitrary_keycode(uint16_t keycode, bool down) {
	keyrecord_t record = {
	  .event = {
	    .key = {
	      .col = 255,
	      .row = 0,
	    },
	    .pressed = down,
	    .time = timer_read(),
	  },
      .keycode = keycode,
	};

	process_record(&record);
}

// Main keycode press/release handling function
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!lang_shift_process_record(keycode, record))
        return false;

    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}

// "Timer" handling function - for quick reaction for events when we can't rely on keypresses.
// (E.g. automatic key release after timeout, "forget" recent keypresses in sequences)
void user_timer(void) {
    lang_shift_user_timer();
}

// Main keyboard matrix scan function.
// It is called often and regularly, so we use it for our "timers".
void matrix_scan_user(void) {
    user_timer();
}
