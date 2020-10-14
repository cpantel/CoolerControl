#include "Config.hpp"

void Config::writeToEEPROM() {
  EEPROM.put(base + 0,signature);
  EEPROM.put(base + 1,temp_ref_1);
  EEPROM.put(base + 2,temp_ref_2);
  EEPROM.put(base + 3,weight_1);
  EEPROM.put(base + 4,weight_2);
  EEPROM.put(base + 5,decrement_2);
  EEPROM.put(base + 6,decrement_1);
  EEPROM.put(base + 7,decrement_0);
  EEPROM.put(base + 8,increment_1);
  EEPROM.put(base + 9,increment_2);
  EEPROM.put(base + 10,increment_3);
  EEPROM.put(base + 11,min_speed);
  EEPROM.put(base + 12,scale);
  EEPROM.put(base + 13,delta_eq);
  EEPROM.put(base + 14,sample_interval);
}

void Config::downloadToCLI() {
  Serial.println();
  Serial.print(temp_ref_1);
  Serial.print(" ");
  Serial.print(temp_ref_2);
  Serial.print(" ");
  Serial.print(weight_1);
  Serial.print(" ");
  Serial.print(weight_2);
  Serial.print(" ");
  Serial.print(decrement_2);
  Serial.print(" ");
  Serial.print(decrement_1);
  Serial.print(" ");
  Serial.print(decrement_0);
  Serial.print(" ");
  Serial.print(increment_1);
  Serial.print(" ");
  Serial.print(increment_2);
  Serial.print(" ");
  Serial.print(increment_3);
  Serial.print(" ");
  Serial.print(min_speed);
  Serial.print(" ");
  Serial.print(scale);
  Serial.print(" ");
  Serial.print(delta_eq);
  Serial.print(" ");
  Serial.print(sample_interval);
  Serial.print(" ");
  Serial.print(signature);
  Serial.println();
}

bool Config::readFromEEPROM() {
  byte newSignature;
  EEPROM.get(base + 0,newSignature);
  if (newSignature == signature) {
    EEPROM.get(base + 1,temp_ref_1);
    EEPROM.get(base + 2,temp_ref_2);
    EEPROM.get(base + 3,weight_1);
    EEPROM.get(base + 4,weight_2);
    EEPROM.get(base + 5,decrement_2);
    EEPROM.get(base + 6,decrement_1);
    EEPROM.get(base + 7,decrement_0);
    EEPROM.get(base + 8,increment_1);
    EEPROM.get(base + 9,increment_2);
    EEPROM.get(base + 10,increment_3);
    EEPROM.get(base + 11,min_speed);
    EEPROM.get(base + 12,scale);
    EEPROM.get(base + 13,delta_eq);
    EEPROM.get(base + 14,sample_interval);
    return true;
  } 
  return false;
}

void Config::showJSON() {
  Serial.print(F(" \"R1\" : \""));
  Serial.print(temp_ref_1);
  Serial.print(F("\", \"R2\" : \""));
  Serial.print(temp_ref_2);
  Serial.print(F("\", \"W1\" : \""));
  Serial.print(weight_1);
  Serial.print(F("\", \"W2\" : \""));
  Serial.print(weight_2);
  Serial.print(F("\", \"D2\" : \""));
  Serial.print(decrement_2);
  Serial.print(F("\", \"D1\" : \""));
  Serial.print(decrement_1);
  Serial.print(F("\", \"D0\" : \""));
  Serial.print(decrement_0);
  Serial.print(F("\", \"I1\" : \""));
  Serial.print(increment_1);
  Serial.print(F("\", \"I2\" : \""));
  Serial.print(increment_2);
  Serial.print(F("\", \"I3\" : \""));
  Serial.print(increment_3);
  Serial.print(F("\", \"MS\" : \""));
  Serial.print(min_speed);
  Serial.print(F("\", \"SC\" : \""));
  Serial.print(scale);
  Serial.print(F("\", \"DE\" : \""));
  Serial.print(delta_eq);
  Serial.print(F("\", \"SI\" : \""));
  Serial.print(sample_interval);
  Serial.print(F("\""));

  
}


void Config::show() {
  Serial.print(F("temp_ref_1      : "));
  Serial.println(temp_ref_1);
  Serial.print(F("temp_ref_2      : "));
  Serial.println(temp_ref_2);
  Serial.print(F("weight_1        : "));
  Serial.println(weight_1);
  Serial.print(F("weight_2        : "));
  Serial.println(weight_2);
  Serial.print(F("decrement_2     : "));
  Serial.println(decrement_2);
  Serial.print(F("decrement_1     : "));
  Serial.println(decrement_1);
  Serial.print(F("decrement_0     : "));
  Serial.println(decrement_0);
  Serial.print(F("increment_1     : "));
  Serial.println(increment_1);
  Serial.print(F("increment_2     : "));
  Serial.println(increment_2);
  Serial.print(F("increment_3     : "));
  Serial.println(increment_3);
  Serial.print(F("min_speed       : "));
  Serial.println(min_speed);
  Serial.print(F("scale           : "));
  Serial.println(scale);
  Serial.print(F("delta_eq        : "));
  Serial.println(delta_eq);
  Serial.print(F("sample_interval : "));
  Serial.println(sample_interval);
  Serial.print(F("signature       : "));
  Serial.println(signature);
  Serial.println();
}
bool Config::uploadFromCLI(){
  
  unsigned int new_temp_ref_1      = Serial.parseInt();
  unsigned int new_temp_ref_2      = Serial.parseInt();
  unsigned int new_weight_1        = Serial.parseInt();
  unsigned int new_weight_2        = Serial.parseInt();
  unsigned int new_decrement_2     = Serial.parseInt();
  unsigned int new_decrement_1     = Serial.parseInt();
  unsigned int new_decrement_0     = Serial.parseInt();
  unsigned int new_increment_1     = Serial.parseInt();
  unsigned int new_increment_2     = Serial.parseInt();
  unsigned int new_increment_3     = Serial.parseInt();
  unsigned int new_min_speed       = Serial.parseInt();
  unsigned int new_scale           = Serial.parseInt();
  unsigned int new_delta_eq        = Serial.parseInt();
  unsigned int new_sample_interval = Serial.parseInt();
  unsigned int new_signature       = Serial.parseInt();
  
  if (new_signature == signature ) {
    if (new_sample_interval < 5000 ) {
      new_sample_interval = 5000;
    }
    temp_ref_1      = new_temp_ref_1;
    temp_ref_2      = new_temp_ref_2;
    weight_1        = new_weight_1;
    weight_2        = new_weight_2;
    decrement_2     = new_decrement_2;
    decrement_1     = new_decrement_1;
    decrement_0     = new_decrement_0;
    increment_1     = new_increment_1;
    increment_2     = new_increment_2;
    increment_3     = new_increment_3;
    min_speed       = new_min_speed;
    scale           = new_scale;
    delta_eq        = new_delta_eq;
    sample_interval = new_sample_interval; 
    return true;
  }
  return false;
}
