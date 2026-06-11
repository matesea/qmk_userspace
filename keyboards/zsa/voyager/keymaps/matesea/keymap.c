#include QMK_KEYBOARD_H
#include "version.h"
#include "layout.h"

#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE
#define DIRECTION_LAYER_ENABLE

enum custom_keycodes {
  ARROW = ML_SAFE_RANGE,    // -> =>
  SWIME,   // switch ime
  CLOSAPP, // close app, alt-f4/gui-q according to OS
  APPPREV, // swap forground app to previous
  APPNEXT, // swap forground app to next
  RGBHRND, // random select effect

  // dummy keycode for C(KC_A)/C(KC_S)/C(KC_D)/C(KC_F)
  CA,
  CS,
  CD,
  CF,

#ifdef DIRECTION_LAYER_ENABLE
  /* vim navigation */
  /* the LBRC/RBRC keys must be both defined and in same order */
  /* shift + RBRC_* = LBRC_* */
  LBRC_A, // previous functon with aerial.nvim
  LBRC_B, // previous buffer
  LBRC_C, // previous hunk
  LBRC_D, // previous diagnostics
  LBRC_E,
  LBRC_F, // jump to highlight under cursor backward
  LBRC_G, // jump to any highlight backward
  LBRC_H,
  LBRC_I,
  LBRC_J,
  LBRC_K,
  LBRC_L,
  LBRC_M,
  LBRC_N,
  LBRC_O,
  LBRC_P,
  LBRC_Q, // previous item in quickfix
  LBRC_R,
  LBRC_S,
  LBRC_T, // previous tab
  LBRC_U,
  LBRC_V,
  LBRC_W,
  LBRC_X,
  LBRC_Y,
  LBRC_Z,

  RBRC_A,
  RBRC_B,
  RBRC_C,
  RBRC_D,
  RBRC_E,
  RBRC_F,
  RBRC_G,
  RBRC_H,
  RBRC_I,
  RBRC_J,
  RBRC_K,
  RBRC_L,
  RBRC_M,
  RBRC_N,
  RBRC_O,
  RBRC_P,
  RBRC_Q,
  RBRC_R,
  RBRC_S,
  RBRC_T,
  RBRC_U,
  RBRC_V,
  RBRC_W,
  RBRC_X,
  RBRC_Y,
  RBRC_Z,
#endif /* DIRECTION_LAYER_ENABLE */

  UPDIR, // input ../ per press
  KEYSTR_MIN = UPDIR,
  USRNAME, // input username
  TMUXESC,  // c-a esc: copy mode
  TMUXPAST, // c-a ]  : paste in tmux

  KEYSTR_MAX = TMUXPAST,
};

struct keystring_t {
    const char *str;
};

enum {
    QWERTY = 0,
    SYM,
    EXT,
    NAV,
    FN,
#ifdef DIRECTION_LAYER_ENABLE
    DIR,
#endif
};

enum keycode_aliases {
    HRM_A   = LGUI_T(KC_A),
    HRM_S   = LALT_T(KC_S),
    HRM_D   = LCTL_T(KC_D),
    HRM_F   = LSFT_T(KC_F),

    HRM_V   = LT(SYM, KC_V),

    // EXT
    HRM_G   = LT(EXT, KC_G),        // EXT
    HRM_UNDS = LT(EXT, KC_UNDS),    // drag scroll

    HRM_J    = RSFT_T(KC_J),
    HRM_K    = RCTL_T(KC_K),
    HRM_L    = LALT_T(KC_L),
    HRM_SCLN = RGUI_T(KC_SCLN),

    HRM_M   = LT(SYM, KC_M),
#ifdef DIRECTION_LAYER_ENABLE
    HRM_COMM = LT(DIR, KC_COMM),
    HRM_DOT = LT(DIR, KC_DOT),
#else
    HRM_COMM = KC_COMM,
    HRM_DOT = KC_DOT,
#endif

    // HRM_REP  = LT(NAV, QK_REP),
    HRM_ENT  = LT(NAV, KC_ENT),
    HRM_BSPC = LT(FN, KC_BSPC),

    OSM_SFT  = OSM(MOD_LSFT),

    NAV_A = LGUI_T(CA),
    NAV_S = LALT_T(CS),
    NAV_D = LCTL_T(CD),
    NAV_F = LSFT_T(CF),
};

static bool isMacOS = false;
#if defined(COMMUNITY_MODULE_SELECT_WORD_ENABLE) && defined(SELECT_WORD_OS_DYNAMIC)
bool select_word_host_is_mac(void) {
    return isMacOS;
}
#endif /* defined(COMMUNITY_MODULE_SELECT_WORD_ENABLE) && defined(SELECT_WORD_OS_DYNAMIC) */
#ifdef OS_DETECTION_ENABLE
bool process_detected_host_os_user(os_variant_t os) {
    isMacOS = (os == OS_MACOS || os == OS_IOS);
    return true;
}
#endif /* OS_DETECTION_ENABLE */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT_LR(
            KC_ESC,   KC_1,  KC_2,  KC_3,  KC_4,    KC_5,
            KC_TAB,   KC_Q,  KC_W,  KC_E,  KC_R,    KC_T,
            HRM_UNDS, HRM_A, HRM_S, HRM_D, HRM_F,   HRM_G,
            SWIME,    KC_Z,  KC_X,  KC_C,  HRM_V,   KC_B,
                                           OSM_SFT, HRM_ENT,

                        KC_6,     KC_7,  KC_8,     KC_9,    KC_0,     KC_EQL,
                        KC_Y,     KC_U,  KC_I,     KC_O,    KC_P,     KC_MINS,
                        KC_H,     HRM_J, HRM_K,    HRM_L,   HRM_SCLN, KC_QUOT,
                        KC_N,     HRM_M, HRM_COMM, HRM_DOT, KC_SLSH,  KC_BSLS,
                        HRM_BSPC, KC_SPC
    ),

      /* getreuer's symbol layer
         ' < > - |
         ! * / = &
         ~ + [ ] %
                 X

              ^ { } $ X
              # ( ) ; "
              @ : , . '
              X
         split symbol layer to two hands to reduce finger travel distance
       */
    [SYM] = LAYOUT_LR(
            _______,  _______, _______, _______, _______, _______,
            KC_BSLS,  KC_GRV , KC_LABK, KC_RABK, KC_MINS, KC_PIPE,
            TMUXESC,  KC_EXLM, KC_ASTR, KC_SLSH, KC_EQL,  KC_AMPR,
            TMUXPAST, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,
                                                 USRNAME, _______,

                     _______, _______,  _______, _______, _______, _______,
                     KC_CIRC, KC_LCBR,  KC_RCBR, KC_DLR,  ARROW  , KC_MINS,
                     KC_HASH, KC_LPRN,  KC_RPRN, KC_SCLN, KC_DQUO, UPDIR,
                     KC_AT,   KC_COLN,  KC_COMM, KC_DOT,  KC_QUOT, KC_BSLS,
                     _______, _______
    ),

    // mouse keycodes and those often used together
    [EXT] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            NV_TAIM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            NV_TSCR, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                MS_BTN2, MS_BTN1,

                     _______, _______, _______, _______, _______, QK_LLCK,
                     _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______,
                     _______, _______
            ),

    // shortcuts that can be done with one-hand
    // navigation layer
    [NAV] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            NV_TAIM, CLOSAPP, C(KC_W), G(KC_E), G(KC_R), C(KC_T),
            NV_TSCR, NAV_A,   NAV_S,   NAV_D,   NAV_F,   C(KC_G),
            XXXXXXX, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_B),
                                                XXXXXXX, _______,

                     SELWBAK,   SELLINE, SELLUP,  SELWORD, XXXXXXX, QK_LLCK,
                     KC_HOME,   KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_BRK,
                     KC_LEFT,   KC_DOWN, KC_UP,   KC_RGHT, CW_TOGG, KC_PSCR,
                     G(KC_TAB), APPPREV, APPNEXT, KC_APP,  KC_DEL,  KC_SCRL,
                     _______,   _______
     ),

    [FN] = LAYOUT_LR(
            QK_LLCK, KC_MPLY, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
            QK_BOOT, KC_F12,  KC_F9,   KC_F8,   KC_F7,   DB_TOGG,
            QK_RBT,  KC_F11,  KC_F6,   KC_F5,   KC_F4,   LUMINO,
            XXXXXXX, KC_F10,  KC_F3,   KC_F2,   KC_F1,   RGBHRND,
                                                XXXXXXX, _______,

                     _______, _______, _______, _______, _______, _______,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
                     XXXXXXX, NV_CPID, NV_CPIU, XXXXXXX, XXXXXXX, _______,
                     _______, _______
            ),

#ifdef DIRECTION_LAYER_ENABLE
    [DIR] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            XXXXXXX, RBRC_Q,  RBRC_W,  RBRC_E,  RBRC_R,  RBRC_T,
            XXXXXXX, RBRC_A,  RBRC_S,  RBRC_D,  RBRC_F,  RBRC_G,
            XXXXXXX, RBRC_Z,  RBRC_X,  RBRC_C,  RBRC_V,  RBRC_B,
                                                XXXXXXX, _______,

                     _______, _______, _______, _______, _______, _______,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                     _______, _______
            ),
#endif /* DIRECTION_LAYER_ENABLE */
};

#if defined(COMBO_ENABLE)
const uint16_t PROGMEM combo_cv[] = {KC_C, HRM_V, COMBO_END};
const uint16_t PROGMEM combo_fg[] = {HRM_F, HRM_G, COMBO_END};
const uint16_t PROGMEM combo_hj[] = {KC_H, HRM_J, COMBO_END};
const uint16_t PROGMEM combo_m_comm[] = {HRM_M, HRM_COMM, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_cv, CW_TOGG),
    // COMBO(combo_fg, TOGGLE_SCROLL), // NV_TSCR
#if defined(REPEAT_KEY_ENABLE) && !defined(NO_ALT_REPEAT_KEY)
    COMBO(combo_hj, QK_AREP),
#endif
    COMBO(combo_m_comm, SWIME),
};
#endif /* COMBO_ENABLE */

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HRM_F: case HRM_J:
        case HRM_M: case HRM_V:
            return TAPPING_TERM - 70; /* 180ms */
    }
    return TAPPING_TERM; /* 250ms */
}
#endif /* TAPPING_TERM_PER_KEY */

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // disable permissive hold for gui on windows
        // ; is frequently used in vim as leader key
        case HRM_A: case HRM_SCLN:
            return isMacOS;
        // disable permissive hold for alt
        case HRM_S: case HRM_L:
            return false;
    }
    return true;
}
#endif /* PERMISSIVE_HOLD_PER_KEY */

#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HRM_ENT:
            return true;
    }
    return false;
}
#endif

#ifdef QUICK_TAP_TERM_PER_KEY
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning 0 means we
  // instead want to "force hold" and disable key repeating.
  switch (keycode) {
    case HRM_J:
    case HRM_K:
    case HRM_L:
    case HRM_ENT:
    case HRM_BSPC:
#ifdef DIRECTION_LAYER_ENABLE
    case HRM_COMM:
    case HRM_DOT:
#endif
      return QUICK_TAP_TERM;  // Enable key repeating.
  }
  return 0;
}
#endif /* QUICK_TAP_TERM_PER_KEY */

#ifdef COMMUNITY_MODULE_PALETTEFX_ENABLE
static uint8_t myrand(void) {
  static uint16_t state = 1;
#ifdef __CHIBIOS__  // Use high-res timer on ChibiOS.
  state += (uint16_t)chVTGetSystemTimeX();
#else
  state += timer_read();
#endif
  state *= UINT16_C(36563);
  return state >> 8;
}

static void lighting_set_palette(uint8_t palette) {
  if (lumino_get_value() == 0) {
    lumino_cycle_3_state();
  }
  rgb_matrix_enable_noeeprom();
  rgb_matrix_sethsv_noeeprom(
      RGB_MATRIX_HUE_STEP * palette, 255, rgb_matrix_get_val());
}

static void lighting_preset(uint8_t effect, uint8_t palette) {
  lighting_set_palette(palette);
  rgb_matrix_mode_noeeprom(effect);
  rgb_matrix_set_speed_noeeprom(80);
}

void keyboard_post_init_user(void) {
  lighting_preset(RGB_MATRIX_CUSTOM_PALETTEFX_FLOW + (myrand() % 4), myrand());
}
#endif /* COMMUNITY_MODULE_PALETTEFX_ENABLE */

#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
  LAYOUT_LR(
        'L'    , 'L'    , 'L'    , 'L'    , 'L'    , 'L'    ,
        'L'    , 'L'    , 'L'    , 'L'    , 'L'    , 'L'    ,
        'L'    , 'L'    , 'L'    , 'L'    , 'L'    , 'L'    ,
        'L'    , 'L'    , 'L'    , 'L'    , 'L'    , 'L'    ,
                                            '*'    , '*'    ,

                 'R'    , 'R'    , 'R'    , 'R'    , 'R'    , 'R'    ,
                 'R'    , 'R'    , 'R'    , 'R'    , 'R'    , 'R'    ,
                 'R'    , 'R'    , 'R'    , 'R'    , 'R'    , 'R'    ,
                 'R'    , 'R'    , 'R'    , 'R'    , 'R'    , 'R'    ,
                 '*'    , '*'
);

bool get_chordal_hold(
        uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
        uint16_t other_keycode, keyrecord_t* other_record) {
    /*
    switch (tap_hold_keycode) {
        case HRM_A:
            switch (other_keycode) {
                // gui+E: explorer/gui+R: run
                case KC_E:
                case KC_R:
                    return true;
            }
            break;
        case HRM_Z:
            switch (other_keycode) {
                // mouse keys
                case KC_C:
                case HRM_V:
                    return true;
            }
            break;
    }
    */
    return get_chordal_hold_default(tap_hold_record, other_record);
}
#endif  // CHORDAL_HOLD

#ifdef FLOW_TAP_TERM
static bool is_typing(uint16_t keycode) {
  switch (get_tap_keycode(keycode)) {
      case KC_A ... KC_Z:
      case KC_COMM:
      case KC_DOT:
      case KC_SCLN:
      case KC_SLSH:
      case KC_QUOT:
      case SWIME:
      case KC_BSLS:
      case KC_MINS:
      // case KC_UNDS: // XXX: get_tap_keycode(HRM_UNDS) returns KC_MINS
      // thumb
      case KC_SPC:
      // case KC_BSPC:
          return true;
  }
  return false;
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
    const uint8_t all_mods = (get_mods() | get_weak_mods());
    if (is_typing(prev_keycode) &&
            (all_mods & MOD_MASK_CAG) == 0) {
        // determine FLOW_TAP_TERM per key
        switch (keycode) {
            /*
             * XXX: tried investigating proper FLOW_TAP_TERM with qmk module dave-thompson/lumberjack
             *      the most suitable value for me should be around 60ms
             */
            // case HRM_D: case HRM_K: // ctrl
            //    return FLOW_TAP_TERM - 40; // 60ms

#ifdef DIRECTION_LAYER_ENABLE
            case HRM_COMM: case HRM_DOT:    // LT(DIR)
#endif
            case HRM_G:                     // LT(EXT)
            case HRM_UNDS:                  // drag scroll
                 return FLOW_TAP_TERM;      // 100ms

            case HRM_A: case HRM_SCLN:      // gui
                 if (isMacOS)
                     return FLOW_TAP_TERM;  // 100ms
            case HRM_S: case HRM_L:         // alt
                return FLOW_TAP_TERM + 50;  // 150ms
        }
    }
    return 0;
}
#endif /* FLOW_TAP_TERM */

#if defined(REPEAT_KEY_ENABLE)
bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    /*
    // do not remember repeat key
    switch (keycode) {
        case HRM_REP:
            return false;
    }
    */

    // Unpack tapping keycode for tap-hold keys.
    keycode = get_tap_keycode(keycode);

    // Forget Shift on most letters when Shift or AltGr are the only mods. Some
    // letters are excluded, e.g. for "NN" and "ZZ" in Vim.
    // NN, SS, ZZ are excluded
    switch (keycode) {
      case KC_A ... KC_Y:
        if ((*remembered_mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
            *remembered_mods &= ~MOD_MASK_SHIFT;
        }
        break;

      case MS_BTN1 ... MS_BTN2: // no need to remember any modifiers for mouse keys
#ifdef DIRECTION_LAYER_ENABLE
      case LBRC_A ... RBRC_Z:
#endif
      case KEYSTR_MIN ... KEYSTR_MAX: // forget all mods
        *remembered_mods = 0;
        break;
    }

    return true;
}

#ifndef NO_ALT_REPEAT_KEY
uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    if (keycode == KC_TAB) {
        // ctrl+tab <=> ctrl+shift+tab
        if ((mods & ~MOD_MASK_CS) == 0 && (mods & MOD_MASK_CTRL)) {
            if (mods & MOD_MASK_SHIFT)
                return C(KC_TAB);
            return C(S(KC_TAB));
        }
    } else if ((mods & ~MOD_MASK_SHIFT) == 0) {
        switch (keycode) {
#ifdef DIRECTION_LAYER_ENABLE
            /* reverse vim navigation */
            case LBRC_A ... LBRC_Z:
                return keycode - LBRC_A + RBRC_A;

            case RBRC_A ... RBRC_Z:
                return keycode - RBRC_A + LBRC_A;
#endif
        }
    }
    return KC_TRNS;
}
#endif /* NO_ALT_REPEAT_KEY */
#endif /* REPEAT_KEY_ENABLE */

#define TAP_LONG_DELAY 10
static const struct keystring_t keystrings[] = {
    [UPDIR - KEYSTR_MIN]     = {"../"},
    [USRNAME - KEYSTR_MIN]   = {"wenlongy"},
    [TMUXESC - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_TAP(X_ESC)},
    [TMUXPAST - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_TAP(X_RBRC)},
};

#ifndef NO_DEBUG
#pragma message "dlog_record enabled."
#include "print.h"

static void dlog_record(uint16_t keycode, keyrecord_t* record) {
  if (!debug_enable) { return; }
  uint8_t layer = read_source_layers_cache(record->event.key);
  bool is_tap_hold = IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode);
  xprintf("L%-2u ", layer);  // Log the layer.
  if (IS_COMBOEVENT(record->event)) {  // Combos don't have a position.
    xprintf("combo   ");
  } else {  // Log the "(row,col)" position.
    xprintf("(%2u,%2u) ", record->event.key.row, record->event.key.col);
  }
  xprintf("%-4s %-7s %s\n",  // "(tap|hold) (press|release) <keycode>".
      is_tap_hold ? (record->tap.count ? "tap" : "hold") : "",
      record->event.pressed ? "press" : "release",
      get_keycode_string(keycode));
}
#else
#pragma message "dlog_record disabled."
#define dlog_record(keycode, record)
#endif  // NO_DEBUG

// customize tap behavior
// returning true means already handled
__attribute__((weak)) bool process_tap(keyrecord_t *record, uint16_t tap) {
    if (!record->tap.count)
        return false;
    // tap
    if (record->event.pressed) {
        tap_code16_delay(tap, TAP_CODE_DELAY);
     }
     return true;
}

__attribute__((weak)) bool add_mod_when_held(keyrecord_t *record, uint8_t mod) {
    if (record->tap.count)
        return false;
    if (record->event.pressed)
        register_mods(mod);
    else
        unregister_mods(mod);
    return true;
}

#if  defined(STATUS_LED_4) && !defined(NO_ACTION_ONESHOT)
// LED 4 indicate OSM_SFT status
void oneshot_mods_changed_user(uint8_t mods) {
    STATUS_LED_4(!!(mods & MOD_MASK_SHIFT));
}
#endif

extern bool set_scrolling;
extern bool navigator_aim;

/*****
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_layer(EXT);
    set_auto_mouse_enable(true);
}
bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
  // Treat all keys as mouse keys when in the automouse layer so that any key set resets the timeout without leaving the layer.
  if (!layer_state_is(AUTO_MOUSE_TARGET_LAYER)){
    // When depressing a mouse key with a LT key at the same time, the mouse key tracker is not decremented.
    // This is a workaround to fix that
    return (IS_MOUSE_KEYCODE(keycode) && !record->event.pressed);
  }
  return false;
}
#endif // POINTING_DEVICE_AUTO_MOUSE_ENABLE
*****/

static uint8_t swapp_mod = 0; // record app switch mod key status, alt for WIN, gui for MAC

// layer mask for which layers APPPREV/APPNEXT on
#define SWAPP_LAYER_MASK ((1 << NAV))
layer_state_t layer_state_set_user(layer_state_t state) {
#define max(x, y) ((x) > (y) ? (x) : (y))
    // LED indicates SYM or above layer is on
    uint8_t layer = max(get_highest_layer(state), SYM - 1) + 1 - SYM;
    // release swapp_mod when the layer is released
    if (swapp_mod && !(state & SWAPP_LAYER_MASK)) {
        unregister_mods(swapp_mod);
        wait_ms(TAP_CODE_DELAY);
        swapp_mod = 0;
    }
#ifndef NO_ACTION_ONESHOT
    // automatically cancel oneshot shift in non-typing layer
    if ((get_oneshot_mods() & MOD_MASK_SHIFT) && layer > QWERTY) {
        del_oneshot_mods(MOD_MASK_SHIFT);
    }
#endif
#if defined(STATUS_LED_1) && defined(STATUS_LED_2) && defined(STATUS_LED_3)
    STATUS_LED_1(layer & (1 << 0));
    STATUS_LED_2(layer & (1 << 1));
    STATUS_LED_3(layer & (1 << 2));
#endif
    return state;
}

#ifdef COMMUNITY_MODULE_AUTOMOUSE_ENABLE
/**********************
   similar to is_mouse_record_user for auto mouse feature
   but for automouse module
**********************/
static bool stay_mouse_layer(uint16_t keycode, keyrecord_t *record) {
    if (is_layer_locked(EXT) || keycode == QK_LLCK)
        return true;
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode)))
        return true;
    // stay in mouse layer while modifiers at left hand side are held
    switch (keycode) {
        case HRM_A:
        case HRM_S:
        case HRM_D:
        case HRM_F:
            return record->event.pressed;
    }
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  const uint8_t mods = get_mods();
  const uint8_t all_mods = (mods | get_weak_mods());
  const uint8_t alt_mods = all_mods & MOD_MASK_ALT;
  const uint8_t layer = read_source_layers_cache(record->event.key);

  dlog_record(keycode, record);

  // XXX: WA to address unintended shift
  if (layer == SYM && record->event.pressed) {
      clear_weak_mods();
      send_keyboard_report();
  }

  if (swapp_mod) {
    // release swapp mod when the layer where APPPREV/APPNEXT are on
    // any tap/hold key pressed other than APPPREV/APPNEXT
    if ((keycode != APPPREV && keycode != APPNEXT && record->event.pressed)) {
        unregister_mods(swapp_mod);
        wait_ms(TAP_CODE_DELAY);
        swapp_mod = 0;
    }
  }

#ifdef COMMUNITY_MODULE_AUTOMOUSE_ENABLE
  if (layer_state_is(EXT) && !stay_mouse_layer(keycode, record)) {
      layer_off(EXT);
      // automouse_deactivate();
  }
#endif

#if 0
  // XXX: import from oryx
  // no MT(mouse key) on my keymap
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse keys with modifiers work inconsistently across operating systems, this makes sure that modifiers are always
    // applied to the mouse key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode)) || IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
    if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;
  }
#endif

  switch (keycode) {
    case APPPREV:
    case APPNEXT:
        if (record->event.pressed) {
          if (!swapp_mod) {
              swapp_mod = (isMacOS ? MOD_BIT_LGUI : MOD_BIT_LALT);
              wait_ms(TAP_CODE_DELAY);
              register_mods(swapp_mod);
              wait_ms(TAP_LONG_DELAY);
          }
          tap_code16((keycode == APPNEXT ? KC_TAB : S(KC_TAB)));
        }
        return false;

    /* switch IME */
    case SWIME:
        if (record->event.pressed) {
#ifdef CAPS_WORD_ENABLE
            caps_word_off();
#endif /* CAPS_WORD_ENABLE */
            if (isMacOS) {
                /* send global key */
                host_consumer_send(AC_NEXT_KEYBOARD_LAYOUT_SELECT);
                wait_ms(TAP_CODE_DELAY);
                host_consumer_send(0);
            } else {
                register_mods(MOD_BIT_LGUI);
                wait_ms(TAP_LONG_DELAY);
                tap_code16_delay(KC_SPC, TAP_CODE_DELAY);
                unregister_mods(MOD_BIT_LGUI);
            }
        }
        return false;

    /*
     * close app
     * gui+q in MacOS
     * alt+f4 in Windows
     */
    case CLOSAPP:
        {
            uint8_t hold_mod = (isMacOS ? MOD_BIT_LGUI : MOD_BIT_LALT);
            uint16_t tap_key = (isMacOS ? KC_Q : KC_F4);
            if (record->event.pressed) {
                register_mods(hold_mod);
                wait_ms(TAP_LONG_DELAY);
                tap_code16_delay(tap_key, TAP_CODE_DELAY);
                unregister_mods(hold_mod);
            }
        }
        return false;

    case NAV_A:
         if (process_tap(record, isMacOS ? G(KC_A) : C(KC_A)))
             return false;
         break;
    case NAV_S:
         if (process_tap(record, isMacOS ? G(KC_S) : C(KC_S)))
             return false;
         break;
    case NAV_D:
         if (process_tap(record, isMacOS ? G(KC_D) : C(KC_D)))
             return false;
         break;

    case NAV_F:
         if (process_tap(record, isMacOS ? G(KC_F) : C(KC_F)))
             return false;
         break;

#ifdef DIRECTION_LAYER_ENABLE
    case HRM_COMM:
         add_mod_when_held(record, MOD_BIT_LSHIFT);
         break;
#endif

    case C(KC_A) ... C(KC_Z):
        // convert ctrl-<key> shortcuts to gui-<key> on MacOS
        if (isMacOS && record->event.pressed) {
            keycode = QK_MODS_GET_BASIC_KEYCODE(keycode);
            tap_code16_delay(G(keycode), TAP_CODE_DELAY);
            return false;
        }
        break;

    /*
    case HRM_REP:
        if (record->tap.count) {
            repeat_key_invoke(&record->event);
            return false;
        }
        break;
    */

    case HRM_UNDS:
      if (process_tap(record, KC_UNDS))
            return false;
      set_scrolling = !!record->event.pressed;
      break;
  }

  if (record->event.pressed) {
#ifdef DIRECTION_LAYER_ENABLE
    // opposite directional movement when shift pressed
    if (all_mods & MOD_MASK_SHIFT) {
        switch (keycode) {
          case RBRC_A ... RBRC_Z:
              keycode += LBRC_A - RBRC_A;
#ifdef REPEAT_KEY_ENABLE
              set_last_keycode(keycode);
#endif
              break;
        }
    }
#endif /* DIRECTION_LAYER_ENABLE */

    switch (keycode) {
#if !defined(NO_ACTION_ONESHOT) || defined(COMMUNITY_MODULE_AUTOMOUSE_ENABLE)
        /* cancel OSM shift/auto mouse layer with BSPC */
        case HRM_BSPC:
            if (record->tap.count && record->event.pressed) {
                if ((get_oneshot_mods() & MOD_MASK_SHIFT)) {
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    return false;
                }
#ifdef COMMUNITY_MODULE_AUTOMOUSE_ENABLE
                if (layer_state_is(EXT) && !is_layer_locked(EXT)) {
                    // automouse_deactivate();
                    layer_off(EXT);
                    return false;
                }
#endif
            }
            break;
#endif

        case ARROW:
          clear_mods();
          SEND_STRING((all_mods & MOD_MASK_CTRL) ?
                  (alt_mods ?
                      "<=>" :
                      "=>") :
                  (alt_mods ?
                      "<->" :
                      "->"));
          set_mods(mods);
          return false;

#ifdef DIRECTION_LAYER_ENABLE
        case LBRC_A ... LBRC_Z:
          {
              const char buf[] = {'[', (keycode - LBRC_A) + 'a', '\0'};
              clear_mods();
              SEND_STRING_DELAY(buf, TAP_CODE_DELAY);
              set_mods(mods);
              return false;
          }
        case RBRC_A ... RBRC_Z:
          {
              const char buf[] = {']', (keycode - RBRC_A) + 'a', '\0'};
              clear_mods();
              SEND_STRING_DELAY(buf, TAP_CODE_DELAY);
              set_mods(mods);
              return false;
          }

#endif /* DIRECTION_LAYER_ENABLE */
        case UPDIR ... TMUXPAST:
          {
              const struct keystring_t *p = &keystrings[keycode - KEYSTR_MIN];
              clear_mods();
              SEND_STRING_DELAY(p->str, TAP_CODE_DELAY);
              set_mods(mods);
          }
          return false;

#ifdef COMMUNITY_MODULE_PALETTEFX_ENABLE
        case RGBHRND:
          lighting_preset(RGB_MATRIX_CUSTOM_PALETTEFX_FLOW + (myrand() % 4), myrand());
          return false;
#endif /* COMMUNITY_MODULE_PALETTEFX_ENABLE */
    }
  }
  return true;
}

///////////////////////////////////////////////////////////////////////////////
// Caps word (https://docs.qmk.fm/features/caps_word)
///////////////////////////////////////////////////////////////////////////////
#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
      add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}
#endif  // CAPS_WORD_ENABLE
