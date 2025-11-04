#ifndef KEYMAPPER_H         
#define KEYMAPPER_H
#include <ArduinoJson.h>

void map_keys(const char* cfg);
void populate_button_lbl_vars(const char* cfg);
void populate_button_binding_vars(const char* cfg);

#endif /* KEYMAPPER_H */