#ifndef _Config_
#define _Config_


#ifdef UNIT_TEST

#include <list>
#include "local.h"

#endif


class Config {
  public:
    void show();
    bool readFromEEPROM();
    void writeToEEPROM();
    void downloadToCLI();
    bool uploadFromCLI();

    byte         signature       = 0x14;
    byte         temp_ref_1      = 25;
    byte         temp_ref_2      = 25;
    byte         weight_1        = 5;
    byte         weight_2        = 5;
    byte         decrement_2     = 20;
    byte         decrement_1     = 10;
    byte         decrement_0     = 0;
    byte         increment_1     = 10;
    byte         increment_2     = 20;
    byte         increment_3     = 50;
    byte         min_speed       = 84;
    byte         scale           = 1;
    byte         delta_eq        = 2;
    unsigned int sample_interval = 5000;

  private:
    unsigned int base = 0;
};


#endif
