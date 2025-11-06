#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>
#include <BleKeyboard.h>

// Native global variables
extern BleKeyboard ble_Keyboard;
extern String profiles;

// Button label globals
extern char lbl_btn_11[8];
extern char lbl_btn_12[8];
extern char lbl_btn_13[8];
extern char lbl_btn_11_1[8];
extern char lbl_btn_12_1[8];
extern char lbl_btn_13_1[8];
extern char lbl_btn_21[8];
extern char lbl_btn_22[8];
extern char lbl_btn_23[8];
extern char lbl_btn_21_1[8];
extern char lbl_btn_22_1[8];
extern char lbl_btn_23_1[8];

inline constexpr size_t MAX_LABEL_LEN = 8;   // adjust as needed

/* --------------------------------------------------------------------
 *  Button binding globals (new)
 * -------------------------------------------------------------------- */
extern char bind_btn_11[4];
extern char bind_btn_12[4];
extern char bind_btn_13[4];
extern char bind_btn_11_1[4];
extern char bind_btn_12_1[4];
extern char bind_btn_13_1[4];
extern char bind_btn_21[4];
extern char bind_btn_22[4];
extern char bind_btn_23[4];
extern char bind_btn_21_1[4];
extern char bind_btn_22_1[4];
extern char bind_btn_23_1[4];

inline constexpr size_t MAX_BIND_LEN = 4;   // 1 digit + NUL + possible future use

/* --------------------------------------------------------------------
 *  Inline accessors (getters / setters)
 *  ---------------------------------------------------------------*/
// ------------------------------------------------------------------
//  Button 12, 13, and the remaining button label arrays
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//  Button 11
// ------------------------------------------------------------------
inline const char* get_lbl_btn_11() noexcept  { return lbl_btn_11; }
inline void set_lbl_btn_11(const char* v) noexcept
{
    // copy from the JSON value into a safe, bounded buffer
    strncpy(lbl_btn_11, v, MAX_LABEL_LEN - 1);
    lbl_btn_11[MAX_LABEL_LEN - 1] = '\0';   // ensure null‑termination
}

// Getter / Setter for lbl_btn_12
inline const char* get_lbl_btn_12() noexcept  { return lbl_btn_12; }
inline void set_lbl_btn_12(const char* v) noexcept
{
    strncpy(lbl_btn_12, v, MAX_LABEL_LEN - 1);
    lbl_btn_12[MAX_LABEL_LEN - 1] = '\0';
}

// Getter / Setter for lbl_btn_13
inline const char* get_lbl_btn_13() noexcept  { return lbl_btn_13; }
inline void set_lbl_btn_13(const char* v) noexcept
{
    strncpy(lbl_btn_13, v, MAX_LABEL_LEN - 1);
    lbl_btn_13[MAX_LABEL_LEN - 1] = '\0';
}

// Getter / Setter for lbl_btn_11_1
inline const char* get_lbl_btn_11_1() noexcept  { return lbl_btn_11_1; }
inline void set_lbl_btn_11_1(const char* v) noexcept
{
    strncpy(lbl_btn_11_1, v, MAX_LABEL_LEN - 1);
    lbl_btn_11_1[MAX_LABEL_LEN - 1] = '\0';
}

// Getter / Setter for lbl_btn_12_1
inline const char* get_lbl_btn_12_1() noexcept  { return lbl_btn_12_1; }
inline void set_lbl_btn_12_1(const char* v) noexcept
{
    strncpy(lbl_btn_12_1, v, MAX_LABEL_LEN - 1);
    lbl_btn_12_1[MAX_LABEL_LEN - 1] = '\0';
}

// Getter / Setter for lbl_btn_13_1
inline const char* get_lbl_btn_13_1() noexcept  { return lbl_btn_13_1; }
inline void set_lbl_btn_13_1(const char* v) noexcept
{
    strncpy(lbl_btn_13_1, v, MAX_LABEL_LEN - 1);
    lbl_btn_13_1[MAX_LABEL_LEN - 1] = '\0';
}

// Getter / Setter for lbl_btn_21
inline const char* get_lbl_btn_21() noexcept  { return lbl_btn_21; }
inline void set_lbl_btn_21(const char* v) noexcept
{
    strncpy(lbl_btn_21, v, MAX_LABEL_LEN - 1);
    lbl_btn_21[MAX_LABEL_LEN - 1] = '\0';
}

// Getter / Setter for lbl_btn_22
inline const char* get_lbl_btn_22() noexcept  { return lbl_btn_22; }
inline void set_lbl_btn_22(const char* v) noexcept
{
    strncpy(lbl_btn_22, v, MAX_LABEL_LEN - 1);
    lbl_btn_22[MAX_LABEL_LEN - 1] = '\0';
}

// Getter / Setter for lbl_btn_23
inline const char* get_lbl_btn_23() noexcept  { return lbl_btn_23; }
inline void set_lbl_btn_23(const char* v) noexcept
{
    strncpy(lbl_btn_23, v, MAX_LABEL_LEN - 1);
    lbl_btn_23[MAX_LABEL_LEN - 1] = '\0';
}

// Getter / Setter for lbl_btn_21_1
inline const char* get_lbl_btn_21_1() noexcept  { return lbl_btn_21_1; }
inline void set_lbl_btn_21_1(const char* v) noexcept
{
    strncpy(lbl_btn_21_1, v, MAX_LABEL_LEN - 1);
    lbl_btn_21_1[MAX_LABEL_LEN - 1] = '\0';
}

// Getter / Setter for lbl_btn_22_1
inline const char* get_lbl_btn_22_1() noexcept  { return lbl_btn_22_1; }
inline void set_lbl_btn_22_1(const char* v) noexcept
{
    strncpy(lbl_btn_22_1, v, MAX_LABEL_LEN - 1);
    lbl_btn_22_1[MAX_LABEL_LEN - 1] = '\0';
}

// Getter / Setter for lbl_btn_23_1
inline const char* get_lbl_btn_23_1() noexcept  { return lbl_btn_23_1; }
inline void set_lbl_btn_23_1(const char* v) noexcept
{
    strncpy(lbl_btn_23_1, v, MAX_LABEL_LEN - 1);
    lbl_btn_23_1[MAX_LABEL_LEN - 1] = '\0';
}
void   set_selected_str(const char *str);
const char *get_selected_str(void);   // returns a `const char*`

/* --------------------------------------------------------------------
 *  Binding getters / setters (new)
 * -------------------------------------------------------------------- */
inline const char* get_bind_btn_11() noexcept  { return bind_btn_11; }
inline void set_bind_btn_11(const char* v) noexcept
{
    strncpy(bind_btn_11, v, MAX_BIND_LEN - 1);
    bind_btn_11[MAX_BIND_LEN - 1] = '\0';
}

inline const char* get_bind_btn_12() noexcept  { return bind_btn_12; }
inline void set_bind_btn_12(const char* v) noexcept
{
    strncpy(bind_btn_12, v, MAX_BIND_LEN - 1);
    bind_btn_12[MAX_BIND_LEN - 1] = '\0';
}

inline const char* get_bind_btn_13() noexcept  { return bind_btn_13; }
inline void set_bind_btn_13(const char* v) noexcept
{
    strncpy(bind_btn_13, v, MAX_BIND_LEN - 1);
    bind_btn_13[MAX_BIND_LEN - 1] = '\0';
}

inline const char* get_bind_btn_11_1() noexcept  { return bind_btn_11_1; }
inline void set_bind_btn_11_1(const char* v) noexcept
{
    strncpy(bind_btn_11_1, v, MAX_BIND_LEN - 1);
    bind_btn_11_1[MAX_BIND_LEN - 1] = '\0';
}

inline const char* get_bind_btn_12_1() noexcept  { return bind_btn_12_1; }
inline void set_bind_btn_12_1(const char* v) noexcept
{
    strncpy(bind_btn_12_1, v, MAX_BIND_LEN - 1);
    bind_btn_12_1[MAX_BIND_LEN - 1] = '\0';
}

inline const char* get_bind_btn_13_1() noexcept  { return bind_btn_13_1; }
inline void set_bind_btn_13_1(const char* v) noexcept
{
    strncpy(bind_btn_13_1, v, MAX_BIND_LEN - 1);
    bind_btn_13_1[MAX_BIND_LEN - 1] = '\0';
}

inline const char* get_bind_btn_21() noexcept  { return bind_btn_21; }
inline void set_bind_btn_21(const char* v) noexcept
{
    strncpy(bind_btn_21, v, MAX_BIND_LEN - 1);
    bind_btn_21[MAX_BIND_LEN - 1] = '\0';
}

inline const char* get_bind_btn_22() noexcept  { return bind_btn_22; }
inline void set_bind_btn_22(const char* v) noexcept
{
    strncpy(bind_btn_22, v, MAX_BIND_LEN - 1);
    bind_btn_22[MAX_BIND_LEN - 1] = '\0';
}

inline const char* get_bind_btn_23() noexcept  { return bind_btn_23; }
inline void set_bind_btn_23(const char* v) noexcept
{
    strncpy(bind_btn_23, v, MAX_BIND_LEN - 1);
    bind_btn_23[MAX_BIND_LEN - 1] = '\0';
}

inline const char* get_bind_btn_21_1() noexcept  { return bind_btn_21_1; }
inline void set_bind_btn_21_1(const char* v) noexcept
{
    strncpy(bind_btn_21_1, v, MAX_BIND_LEN - 1);
    bind_btn_21_1[MAX_BIND_LEN - 1] = '\0';
}

inline const char* get_bind_btn_22_1() noexcept  { return bind_btn_22_1; }
inline void set_bind_btn_22_1(const char* v) noexcept
{
    strncpy(bind_btn_22_1, v, MAX_BIND_LEN - 1);
    bind_btn_22_1[MAX_BIND_LEN - 1] = '\0';
}

inline const char* get_bind_btn_23_1() noexcept  { return bind_btn_23_1; }
inline void set_bind_btn_23_1(const char* v) noexcept
{
    strncpy(bind_btn_23_1, v, MAX_BIND_LEN - 1);
    bind_btn_23_1[MAX_BIND_LEN - 1] = '\0';
}

extern BleKeyboard get_var_ble_keyboard();
extern void set_var_ble_keyboard(BleKeyboard value);

#endif /*EEZ_LVGL_UI_VARS_H*/