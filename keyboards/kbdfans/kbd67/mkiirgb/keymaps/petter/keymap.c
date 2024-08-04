#include QMK_KEYBOARD_H

#define _LAYER0 0
#define _LAYER1 1

/********************************
 * KEYS AND UNICODE CODE POINTS *
 ********************************/

// Lozenge (◊) -- bind to Fn+L (in _LAYER)
#define LOZ 0x25CA

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Backspc│ ` │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┬───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │PgU│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │PgD|
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┼───┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │Shift | ↑ │Del|
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴──┬───┬───┼───┤
     * │Ctrl│Win │Alt │         space          │ Alt│MO(1) │ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴────┴──────┴───┴───┴───┘
     */
    [_LAYER0] = LAYOUT_65_ansi_blocker( /* Base */
        QK_GESC,       KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_GRAVE,
        KC_TAB,        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,   KC_PGUP,
        CTL_T(KC_CAPS),KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,
        KC_LSFT,       KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,     KC_DEL,
        KC_LCTL,       KC_LGUI,  KC_LALT,                  KC_SPC,                 KC_RALT,            MO(1),    KC_LEFT,                     KC_DOWN,   KC_RIGHT),
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │Esc│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│Delete │   │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┬───┤
     * │     │TOG│MOD│HU+│HU-│SA+│SA-│VA+│VA-│   │   │   │   │BOOT │Hom│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │ Caps │SP+│SP-│   │   │   │   │   │   │ ◊ │   │   │ EE_CLR │End|
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┼───┤
     * │ Shift  │   │   │   │   │   │   │   │   │   │   │      |Ply│   |
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴──┬───┬───┼───┤
     * │    │    │    │                        │    │      │Prv│Stp│Nxt│
     * └────┴────┴────┴────────────────────────┴────┴──────┴───┴───┴───┘
     */
    [_LAYER1] = LAYOUT_65_ansi_blocker( /* FN */
        QK_GESC,       KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,   KC_F12,   KC_DEL,   _______,
        _______,       RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  _______,  _______,   _______,  _______,  QK_BOOT,  KC_HOME,
        CTL_T(KC_CAPS),RGB_SPI,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  UC(LOZ),  _______,   _______,            EE_CLR,   KC_END,
        KC_LSFT,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,            KC_MPLY,  _______,
        _______,       _______,  _______,                  _______,                _______,            _______,  KC_MPRV,                       KC_MSTP,  KC_MNXT),
};

#ifdef RGB_MATRIX_ENABLE
    #define INDEX_LED_CAPSLOCK 30

    // When caps lock is engaged, set the LED to white
    bool rgb_matrix_indicators_user(void) {
        if (host_keyboard_led_state().caps_lock) {
            rgb_matrix_set_color(INDEX_LED_CAPSLOCK, RGB_WHITE);
        } else {
            rgb_matrix_set_color(INDEX_LED_CAPSLOCK, RGB_OFF);
        }

        return false;
    }

    // If you want to just use RGB indicators without RGB matrix effect,
    // it is not possible to disable the latter because toggling RGB off
    // will disable everything. You can workaround it with solid effect
    // and colors off using this init function:
    void keyboard_post_init_user(void) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_sethsv_noeeprom(HSV_OFF);
    }
#endif // RGB_MATRIX_ENABLE
