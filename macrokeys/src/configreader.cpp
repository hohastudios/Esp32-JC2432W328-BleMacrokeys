#include <ArduinoJson.h>
#include <jsonlib.h>
#include "configreader.h"
#include <SD.h>
#include <SPI.h>

// ---------------------------------------------------------------------------
//  Modified: read_sd_directory
//  Returns a String in LVGL-compatible format.
// ---------------------------------------------------------------------------
String read_sd_directory()
{
  if (!SD.begin()) { 
      Serial.println("Card Mount Failed");
      return String("");
  }
  Serial.println("Card Mounted"); 
  // 1. Open the directory that holds the configuration files
  File dirs = SD.open("/macrokeys/config");
  if (!dirs || !dirs.isDirectory()) {
    Serial.println("Failed to open /config directory");
    return String("");
  }

  String options = "";

  // 2. Iterate through all entries in the directory
  File file = dirs.openNextFile();
  while (file) {
    // Skip sub‑directories – we only want regular files
    if (!file.isDirectory()) {
      // Prepend a newline *only* if there is already something in the string
      if (!options.isEmpty()) {
        options += "\n";
      }
      options += String(file.name());   // e.g., "option1"
    }

    file.close();          // Close the current entry before opening the next
    file = dirs.openNextFile(); // Move to the next file/directory
  }

  dirs.close();  // Close the directory handle

  // 3. Return the constructed string
  return options;
}

const char* read_config_file(String path) {
  Serial.println(String("Reading file: ") + path);

  String fullPath = String("/macrokeys/config/") + path;
  File file = SD.open(fullPath.c_str());

  if (!file || file.isDirectory()) {
      const char* errMsg = "{\"error\":\"path error\"}";
      char* buffer = new char[strlen(errMsg) + 1];
      strcpy(buffer, errMsg);
      return buffer; 
  }

  String input="";
  while (file.available()) {
    input += char(file.read());
  }
  
  // Allocate memory for the const char* and copy the string
  char* buffer = new char[input.length() + 1];
  strcpy(buffer, input.c_str());
  
  file.close();
  return buffer;

}

