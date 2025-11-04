#include "vars.h"
#include <ArduinoJson.h>

struct BtnMapping {
    const char* jsonKey;
    void(*setter)(const char*);
};

static const BtnMapping btnSetters[] = {
    {"btn11",  set_lbl_btn_11},
    {"btn11_1", set_lbl_btn_11_1},
    {"btn12",  set_lbl_btn_12},
    {"btn12_1", set_lbl_btn_12_1},
    {"btn13",  set_lbl_btn_13},
    {"btn13_1", set_lbl_btn_13_1},
    {"btn21",  set_lbl_btn_21},
    {"btn21_1", set_lbl_btn_21_1},
    {"btn22",  set_lbl_btn_22},
    {"btn22_1", set_lbl_btn_22_1},
    {"btn23",  set_lbl_btn_23},
    {"btn23_1", set_lbl_btn_23_1}
};

// 2️⃣  helper that applies a single button's label
static inline void applyBtnLabel(const JsonObject& doc, const BtnMapping& m)
{
    if (!doc.containsKey(m.jsonKey)) return;          // nothing to set for this key

    JsonObject obj = doc[m.jsonKey].as<JsonObject>();
    const char* txt = obj["label"].as<const char*>();
    m.setter(txt);                                  // call the old per‑button function
}

void populate_button_lbl_vars(const char* cfg)   // use a reference if you prefer
{

    JsonDocument filter;
    filter["btn11"] = true;
    filter["btn12"] = true;
    filter["btn13"] = true;
    filter["btn21"] = true;
    filter["btn22"] = true;
    filter["btn23"] = true;
    filter["btn12_1"] = true;
    filter["btn13_1"] = true;
    filter["btn21_1"] = true;
    filter["btn22_1"] = true;
    filter["btn23_1"] = true;

    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, cfg, DeserializationOption::Filter(filter));

    if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return;
    }

    Serial.printf("Header: %u bytes, Buckets: %u, Value pool: %u, Strings: %u\n",
              4,
              doc.poolSize(),                    // number of buckets
              doc.memoryUsage() - doc.poolSize(), // rough guess
              doc.memoryUsage() - /*header + buckets*/ );

    // 3️⃣  loop over all button mappings
    for (const auto& m : btnSetters) {
        // pass the root JsonObject, not the whole document
        applyBtnLabel(doc.as<JsonObject>(), m);
    }

}


void populate_button_binding_vars(const char* cfg)
{
   //todo
}

void map_keys(const char* cfg)
{
    populate_button_lbl_vars(cfg);
    populate_button_binding_vars(cfg);
}