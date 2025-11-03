#include "vars.h"

void map_keys(const StaticJsonDocument& doc)
{
    populate_button_lbl_vars(doc);
    populate_button_binding_vars(doc);
}

void populate_button_lbl_vars(const StaticJsonDocument& doc)   // use a reference if you prefer
{
    // Button 11, 12, 13
    set_lbl_btn_11(doc["btn11"]["label"]);
    set_lbl_btn_12(doc["btn12"]["label"]);
    set_lbl_btn_13(doc["btn13"]["label"]);

    // Button 11_1, 12_1, 13_1
    set_lbl_btn_11_1(doc["btn11_1"]["label"]);
    set_lbl_btn_12_1(doc["btn12_1"]["label"]);
    set_lbl_btn_13_1(doc["btn13_1"]["label"]);

    // Button 21, 22, 23
    set_lbl_btn_21(doc["btn21"]["label"]);
    set_lbl_btn_22(doc["btn22"]["label"]);
    set_lbl_btn_23(doc["btn23"]["label"]);

    // Button 21_1, 22_1, 23_1
    set_lbl_btn_21_1(doc["btn21_1"]["label"]);
    set_lbl_btn_22_1(doc["btn22_1"]["label"]);
    set_lbl_btn_23_1(doc["btn23_1"]["label"]);
}


void populate_button_binding_vars(const StaticJsonDocument& doc)
{
   //todo
}