#ifndef _Brain_
#define _Brain_


#ifdef UNIT_TEST

#include <list>
#include "local.h"

#endif

#define LEN 4

struct Node {
  byte temp_1;
  byte temp_2;
};

class Brain {

  public:
    Brain() {};

    Brain(
        byte weight_1,
        byte weight_2,
        byte scale,
        byte ref_1,
        byte ref_2,
        byte minSpeed,
        byte delta_eq,
        byte decrement_2,
        byte decrement_1,
        byte equal,
        byte increment_1,
        byte increment_2,
        byte increment_3
    ):
        weight_1(weight_1),
        weight_2(weight_2),
        scale(scale),
        ref_1(ref_1),
        ref_2(ref_2),
        minSpeed(minSpeed),
        delta_eq(delta_eq),
        decrement_2(decrement_2),
        decrement_1(decrement_1),
        equal(equal),
        increment_1(increment_1),
        increment_2(increment_2),
        increment_3(increment_3)
    {};

    void init(
        byte weight_1, byte weight_2,
        byte ta,
        byte ref_1, byte ref_2,
        byte minSpeed,
        byte delta_eq,
        byte decrement_2,
        byte decrement_1,
        byte equal,
        byte increment_1,
        byte increment_2,
        byte increment_3
    );

    int getAverage();

    int getTendency();

    void addMeasure(byte temp_1, byte temp_2);

    int getDeltaSpeed();


    byte getNewSpeed(byte speed);
    byte getMinSpeed();

  // cheating


  private:
    byte weight_1;
    byte weight_2;
    byte scale;
    byte ref_1;
    byte ref_2;
    byte minSpeed;
    byte delta_eq;
    byte decrement_2;
    byte decrement_1;
    byte equal;
    byte increment_1;
    byte increment_2;
    byte increment_3;

    byte offCounter;
    bool firstTime = 1;
    Node measurements[LEN];
};

#endif
