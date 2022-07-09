#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

enum anne_pro_layers {
  _BASE_LAYER_NEO,
  _BASE_LAYER_QWERTY,
  _FN1_LAYER,
  _FN2_LAYER,
  _NEO_LAYER_3_LAYER,
  _NEO_LAYER_4_LAYER,
};

/**
 * The Purpose of this keymap is to be able to use the neo 2.0 Layout on computers that might not
 * have software support.
 *
 * For this Purpose, you should set your computer to use a qwertz keyboard.
 *
 * Because we are limited to the keys that are physically present on such a board (and media keys)
 * I have chosen to omit Layers 5 and 6.
 *
 * If you would like the board to pretend to be a qwerty board, you have to swap KC_Z and KC_Y
 * in the base mapping. (Also you will have to redo the mappings of layer 3/4 because the german boards are weird a.f.)
 *
 * This keymap includes two base mappings: One for neo, used by default and one for qwerty.
 * You can switch to neo by using FN1+BACKSLASH and to qwerty by using FN2+BACKSLASH
 *
 */

/*
* Layer _BASE_LAYER_NEO
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | NEO4   |  x  |  v  |  l  |  c  |  w  |  k  |  h  |  g  |  f  |  q  |  ß  |  ´  |   \    |
* |-----------------------------------------------------------------------------------------+
* | NEO3    |  u  |  i  |  a  |  e  |  o  |  s  |  n  |  r  |  t  |  d  |  y  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  ü  |  ö  |  ä  |  p  |  z  |  b  |  m  |  ,  |  .  |  j  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  NEO4  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in _BASE_LAYER_NEO
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |  TAB   |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE_LAYER_NEO] = KEYMAP( /* Base */
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    LT(_NEO_LAYER_4_LAYER, KC_TAB), KC_X, KC_V, KC_L, KC_C, KC_W, KC_K, KC_H, KC_G, KC_F, KC_Q, KC_MINS, KC_EQL, KC_NUHS,
    MO(_NEO_LAYER_3_LAYER), KC_U, KC_I, KC_A, KC_E, KC_O, KC_S, KC_N, KC_R, KC_T, KC_D, KC_Z, KC_ENT,
    KC_LSFT, KC_LBRC, KC_SCLN, KC_QUOT, KC_P, KC_Y, KC_B, KC_M, KC_COMM, KC_DOT, KC_J, RSFT_T(KC_UP),
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(_NEO_LAYER_4_LAYER), LT(_FN1_LAYER,KC_LEFT), LT(_FN2_LAYER,KC_DOWN), RCTL_T(KC_RGHT)
),
/*
* Layer _BASE_LAYER_QWERTY
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Caps    |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in _BASE_LAYER_QWERTY
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 [_BASE_LAYER_QWERTY] = KEYMAP( /* Base */
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP),
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, LT(_FN1_LAYER,KC_LEFT), LT(_FN2_LAYER,KC_DOWN), RCTL_T(KC_RGHT)
),
  /*
  * Layer _FN1_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END | TO_NEO |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |V-UP |V-DWN|MUTE |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN1_LAYER] = KEYMAP( /* Base */
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
    KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END, DF(_BASE_LAYER_NEO),
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS,
    KC_TRNS, KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN2_LAYER), KC_TRNS
),
  /*
  * Layer _FN2_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  ~  | BT1 | BT2 | BT3 | BT4 |  F5 |  F6 |  F7 |LEDOF|LEDON| F10 | F11 | F12 |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END | QWERTY |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN2_LAYER] = KEYMAP( /* Base */
    KC_TRNS, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, KC_TRNS, KC_TRNS, KC_TRNS, KC_AP_LED_OFF, KC_AP_LED_ON, KC_AP_LED_NEXT_INTENSITY, KC_AP_LED_SPEED, KC_TRNS, KC_TRNS,
    MO(_FN2_LAYER), KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END, DF(_BASE_LAYER_QWERTY),
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN1_LAYER), MO(_FN2_LAYER), KC_TRNS
 ),
 /*
  * Now we get to the really interesting bits:
  * The Braces and Brackets Layer beloved by Programmers.
  * Keys not Present on a normal ISO-Qwertz board were omitted.
  *
  * Layer _NEO_LAYER_3_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |  _  |  [  |  ]  |  ^  |  !  |  <  |  >  |  =  | &  |      |     |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |  \  |  /  |  {  |  }  |  *  |  ?  |  (  |  )  |  -  |  :  |  @  |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |  #  |  $  |  |  |  ~  |  `  |  +  |  %  |  "  |  '  |  ;  |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_NEO_LAYER_3_LAYER] = KEYMAP( /* Base */
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, S(KC_SLSH), RALT(KC_8), RALT(KC_9), KC_GRAVE, S(KC_1), KC_NUBS, S(KC_NUBS), S(KC_0), S(KC_6), KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, RALT(KC_MINS), S(KC_7), RALT(KC_7), RALT(KC_0), S(KC_RBRC), S(KC_MINS), S(KC_8), S(KC_9), KC_SLSH, S(KC_DOT), RALT(KC_Q), KC_TRNS,
    KC_TRNS, KC_NUHS, S(KC_4), RALT(KC_NUBS), RALT(KC_RBRC), S(KC_EQL), KC_RBRC, S(KC_5), S(KC_2), S(KC_NUHS), S(KC_COMM), KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
 ),
 /*
  * Again we only implement the keys that are present on a normal keyboard.
  * Who needs those greek letters anyway, right?
  *
  * Additionally, I have added media keys on fn 1-6 on layer 4 instead of some estoteric keys
  *
  * Layer _NEO_LAYER_4_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |     | MUTE|V-DWN| V-UP|PAUSE|PREV | NEXT|     | tab |  /  |  *  |  -  |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        | PGUP| BKSP| UP  | DEL |PGDWN|     |  7  |  8  |  9  |  + |  -   |     |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |HOME | LFT | DWN |RGHT | END  |    |  4  |  5  |  6  |  ,  |  .  |             |
  * |-----------------------------------------------------------------------------------------+
  * |            | ESC | TAB | INS | ENT |     |  :  |  1  |  2  |  3  |  ;  |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                 0               |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_NEO_LAYER_4_LAYER] = KEYMAP( /* Base */
    KC_TRNS, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_TRNS, KC_TAB, S(KC_7), S(KC_RBRC), KC_SLSH, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_PGUP, KC_BSPC, KC_UP, KC_DEL, KC_PGDN, KC_TRNS, KC_7, KC_8, KC_9, KC_RBRC, KC_SLSH, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, KC_TRNS, KC_4, KC_5, KC_6, KC_COMM, KC_DOT, KC_TRNS,
    KC_TRNS, KC_ESC, KC_TAB, KC_INS, KC_ENT, KC_TRNS, S(KC_DOT), KC_1, KC_2, KC_3, S(KC_COMM), KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
 ),
};
const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void keyboard_post_init_user(void)
{
    annepro2LedEnable();
    annepro2LedSetProfile(12);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DF(_BASE_LAYER_QWERTY):
            annepro2LedSetProfile(13);
            break;
        case DF(_BASE_LAYER_NEO):
            annepro2LedSetProfile(12);
            break;
    }
    return true;
}

// void suspend_power_down_user(void)
// {
//     if (AP2_LED_ENABLED)
//         annepro2LedDisable();
// }

layer_state_t layer_state_set_user(layer_state_t layer) {
    return layer;
}
