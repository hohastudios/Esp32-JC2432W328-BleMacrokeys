#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NUM_LABELS 12  

typedef struct _objects_t {
    lv_obj_t *startup;
    lv_obj_t *main;
    lv_obj_t *btn_ok;
    lv_obj_t *lblok;
    lv_obj_t *config_selector;
    lv_obj_t *tab_view;
    lv_obj_t *tab1;
    lv_obj_t *btn12;
    lv_obj_t *lbl12;
    lv_obj_t *btn13;
    lv_obj_t *lbl13;
    lv_obj_t *btn23;
    lv_obj_t *lbl23;
    lv_obj_t *btn11;
    lv_obj_t *lbl11;
    lv_obj_t *btn22;
    lv_obj_t *lbl22;
    lv_obj_t *btn21;
    lv_obj_t *lbl21;
    lv_obj_t *custom2;
    lv_obj_t *btn23_1;
    lv_obj_t *lbl23_1;
    lv_obj_t *btn22_1;
    lv_obj_t *lbl22_1;
    lv_obj_t *btn21_1;
    lv_obj_t *lbl21_1;
    lv_obj_t *btn11_1;
    lv_obj_t *lbl11_1;
    lv_obj_t *btn13_1;
    lv_obj_t *lbl13_1;
    lv_obj_t *btn12_1;
    lv_obj_t *lbl12_1;
    lv_obj_t *label_ptrs[NUM_LABELS];
} objects_t;

extern objects_t objects;

inline void init_label_ptrs(void)
{
    objects.label_ptrs[0]  = objects.lbl12;
    objects.label_ptrs[1]  = objects.lbl13;
    objects.label_ptrs[2]  = objects.lbl23;
    objects.label_ptrs[3]  = objects.lbl11;
    objects.label_ptrs[4]  = objects.lbl22;
    objects.label_ptrs[5]  = objects.lbl21;
    objects.label_ptrs[6]  = objects.lbl23_1;
    objects.label_ptrs[7]  = objects.lbl22_1;
    objects.label_ptrs[8]  = objects.lbl21_1;
    objects.label_ptrs[9]  = objects.lbl11_1;
    objects.label_ptrs[10] = objects.lbl13_1;
    objects.label_ptrs[11] = objects.lbl12_1;
}

/* ------------------------------------------------------------------------- */
/*  Macro that iterates over all labels in the `label_ptrs` array.             */
/*  Usage example:                                                           */
/*      FOR_EACH_LABEL(objects, set_label_text);     // set_label_text takes lv_obj_t* */ 
/* ------------------------------------------------------------------------- */

static const char *label_names[NUM_LABELS] = {
    "lbl12",  "lbl13",  "lbl23",  "lbl11",
    "lbl22",  "lbl21",  "lbl23_1", "lbl22_1",
    "lbl21_1","lbl11_1","lbl13_1","lbl12_1"
};

#define FOR_EACH_LABEL(obj, expr) \
    do { \
        for (int _i = 0; _i < NUM_LABELS; ++_i) { \
            expr((obj).label_ptrs[_i], label_names[_i]); \
        } \
    } while (0)

void set_label_text(lv_obj_t *lbl, const char *txt);
extern void set_all_label_text();

enum ScreensEnum {
    SCREEN_ID_STARTUP = 1,
    SCREEN_ID_MAIN = 2,
};

void create_screen_startup();
void tick_screen_startup();

void create_screen_main();
void tick_screen_main();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/