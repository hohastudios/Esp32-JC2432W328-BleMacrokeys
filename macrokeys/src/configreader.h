#ifndef CONFIGREADER_H          // ← NEW, unique guard
#define CONFIGREADER_H
#include <FS.h>
#include <ArduinoJson.h>

const char* read_config_file(String path); 
String read_sd_directory();
#endif /* CONFIGREADER_H */