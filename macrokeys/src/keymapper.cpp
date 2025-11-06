#include "vars.h"
#include <ArduinoJson.h>

/* ------------------------------------------------------------------ */
/* 1️⃣  struct that holds a mapping from a JSON key to two setters   */
/* ------------------------------------------------------------------ */
struct BtnMapping {
    const char* jsonKey;            // e.g. "btn11"
    void (*lblSetter)(const char*); // e.g. set_lbl_btn_11
    void (*bindSetter)(const char*);// e.g. set_bind_btn_11
};

/* ------------------------------------------------------------------ */
/* 2️⃣  mapping table (one entry per button)                          */
/* ------------------------------------------------------------------ */
static const BtnMapping btnSetters[] = {
    {"btn11",  set_lbl_btn_11,  set_bind_btn_11},
    {"btn11_1",set_lbl_btn_11_1, set_bind_btn_11_1},
    {"btn12",  set_lbl_btn_12,  set_bind_btn_12},
    {"btn12_1",set_lbl_btn_12_1,set_bind_btn_12_1},
    {"btn13",  set_lbl_btn_13,  set_bind_btn_13},
    {"btn13_1",set_lbl_btn_13_1,set_bind_btn_13_1},
    {"btn21",  set_lbl_btn_21,  set_bind_btn_21},
    {"btn21_1",set_lbl_btn_21_1,set_bind_btn_21_1},
    {"btn22",  set_lbl_btn_22,  set_bind_btn_22},
    {"btn22_1",set_lbl_btn_22_1,set_bind_btn_22_1},
    {"btn23",  set_lbl_btn_23,  set_bind_btn_23},
    {"btn23_1",set_lbl_btn_23_1,set_bind_btn_23_1}
};

/* ------------------------------------------------------------------ */
/* 3️⃣  helper that applies a single button's *label*                 */
/* ------------------------------------------------------------------ */
static inline void applyBtnLabel(const JsonObject& doc, const BtnMapping& m)
{
    if (!doc.containsKey(m.jsonKey)) return;

    JsonObject obj = doc[m.jsonKey].as<JsonObject>();
    const char* txt = obj["label"].as<const char*>();
    m.lblSetter(txt);                     // call per‑button label function
}

/* ------------------------------------------------------------------ */
/* 4️⃣  helper that applies a single button's *binding*               */
/* ------------------------------------------------------------------ */
static inline void applyBtnBinding(const JsonObject& doc, const BtnMapping& m)
{
    if (!doc.containsKey(m.jsonKey)) return;

    JsonObject obj = doc[m.jsonKey].as<JsonObject>();
    const char* txt = obj["binding"].as<const char*>();
    m.bindSetter(txt);                    // call per‑button binding function
}

/* ------------------------------------------------------------------ */
/* 5️⃣  function that deserialises *once* and calls the helpers      */
/* ------------------------------------------------------------------ */
void populate_button_lbl_vars(const char* cfg)
{
    /* --------------------------------- create a *filtered* document */
    JsonDocument filter;
    for (const auto& m : btnSetters) filter[m.jsonKey] = true;   // include all buttons

    /* 512‑byte static buffer (enough for the 12 buttons + bindings) */
    StaticJsonDocument<512> doc;
    DeserializationError err = deserializeJson(
        doc, cfg, DeserializationOption::Filter(filter)
    );

    if (err) {
        Serial.printf("deserializeJson() failed: %s\n", err.c_str());
        return;
    }

    /* 6️⃣  loop over buttons – apply *both* label & binding */
    for (const auto& m : btnSetters) {
        applyBtnLabel(doc.as<JsonObject>(), m);
        applyBtnBinding(doc.as<JsonObject>(), m);
    }
}

/* ------------------------------------------------------------------ */
/* 6️⃣  the unused placeholder (kept for clarity)                    */
/* ------------------------------------------------------------------ */
void populate_button_binding_vars(const char* cfg) { /* now handled together */ }

/* ------------------------------------------------------------------ */
/* 7️⃣  public routine                                                */
/* ------------------------------------------------------------------ */
void map_keys(const char* cfg)
{
    /* entire configuration is handled inside stage 5 (labels & bindings) */
    populate_button_lbl_vars(cfg);
}