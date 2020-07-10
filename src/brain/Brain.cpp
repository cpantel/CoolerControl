#include "Brain.hpp"

#ifdef UNIT_TEST

#include <iostream>
#include <iomanip>
using namespace std;

#endif

/*

                 | Ts < Tr | Ts == Tr | Ts > Tr
(+2) Subió mucho |    +    |    ++    |   +++
(+1) Subió       |    =    |     +    |    ++
 (0) Igual       |    -    |     =    |     +
(-1) Bajó        |   --    |     -	  |     =


*/
void Brain:: init(
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
    ) {
  this->weight_1 = weight_1;
  this->weight_2 = weight_2;
  this->scale = scale;
  this->ref_1 = ref_1;
  this->ref_2 = ref_2;
  this->minSpeed = minSpeed;
  this->delta_eq = delta_eq;
  this->decrement_2 = decrement_2;
  this->decrement_1 = decrement_1;
  this->equal = equal;
  this->increment_1 = increment_1;
  this->increment_2 = increment_2;
  this->increment_3 = increment_3;
};


int Brain::getDeltaSpeed() {
  int delta = ( measurements[0].temp_1 + measurements[0].temp_2 - ref_1 - ref_2 ) / 2;
  int tendency = getTendency();
/*
 * #ifdef UNIT_TEST

  cout << endl << "  Last     : " << (unsigned) measurements[0].temp_1 << endl;
  cout << "  Last     : " << (unsigned) measurements[0].temp_2 << endl;
  cout << "  Ref      : " << (unsigned) ref_1 << endl;
  cout << "  Ref      : " << (unsigned) ref_2 << endl;
  cout << "  Delta    : " << delta << endl;
  cout << "  Tendency : " << tendency << endl;

  #endif
*/

  if ( delta >= delta_eq ) {
    //cout << "Delta positivo" << endl;
    switch (tendency) {

      case 2:
        return increment_3;
      break;

      case 1:
        return increment_2;
      break;

      case 0:
        return increment_1;
      break;

      case -1:
        return - equal;
      break;

    }
  } else if ( delta < ( - (int) delta_eq ) ) {
    //cout << "Delta negativo" << endl;
    switch (tendency) {
      case 2:
        return increment_1;
      break;

      case 1:
        return - equal;
      break;

      case 0:
        return - decrement_1 ;
      break;

      case -1:
        return - decrement_2 ;
      break;

    }
  } else {
    //cout << "Delta plano" << endl;
    switch (tendency) {
      case 2:
        return increment_2;
      break;

      case 1:
        return increment_1;
      break;

      case 0:
        return - equal;
      break;

      case -1:
        return - decrement_1 ;
      break;
    }
  }
}

/*
                              old speed
                 +-------+--------+-------+-------+
                 | > min | == min | == 0  | < min |
        +--------+-------+--------+-------+-------+
        | > 255  |  255  |   255  |  255  |  255  |
        +--------+-------+--------+-------+-------+
new     | > min  |  new  |   new  |  255  |  255  |
speed   +--------+-------+--------+-------+-------+
unfixed | == min |  new  |   new  |   0   |   0   |
        +--------+-------+--------+-------+-------+
        | < min  |  min  |   min  |   0   |   0   |
        +--------+-------+--------+-------+-------+

                         old speed
                 +-------+--------+--------+
                 | > min | == min | <= min |
        +--------+-------+--------+--------+
        | > 255  |  255  |   255  |   255  |
        +--------+-------+--------+--------+
new     | > min  |  new  |   new  |   255  |
speed   +--------+-------+--------+--------+
unfixed | <= min |  min  |   min  |    0   |
        +--------+-------+--------+--------+


*/

byte Brain::getNewSpeed(byte speed) {
  int delta = getDeltaSpeed();
  int newSpeed = speed + delta;
  // cout << endl << "speed + delta = newspeed " << (unsigned) speed << " + " << delta << " = " << newSpeed << " => ";
  if (newSpeed < ( minSpeed - decrement_1 ) ) {

    if (speed == 0 && newSpeed > ( minSpeed - increment_3 ) ) {
      newSpeed = 255;
    } else if (speed <= minSpeed ) {
      newSpeed = 0;
    }
  } else {
      if (newSpeed < minSpeed)  newSpeed = minSpeed;
      else if (newSpeed > 255 ) newSpeed = 255;
  }

  return (byte) newSpeed;
}

byte Brain::getMinSpeed() {
  return minSpeed;
}

int Brain::getAverage() {
  unsigned int accum= 0;
  for (int i=0; i< LEN; ++i) {
    accum += measurements[i].temp_1 * weight_1 + measurements[i].temp_2 * weight_2;
  }
  int average = accum / ( ( weight_1 + weight_2)*LEN );
  return average;
}

int Brain::getTendency() {
  int tendency = scale *
         (
           (
             measurements[0].temp_1 * weight_1 + measurements[0].temp_2 * weight_2
           ) / (weight_1 + weight_2)
           - getAverage()
         );
  if (tendency > 2) tendency = 2;
  if (tendency < -1) tendency = -1;
  return tendency;
}

void Brain::addMeasure(byte temp_1, byte temp_2) {
  if (this->firstTime) {
    for (int i=0; i< LEN; ++i) {
       measurements[i].temp_1 = temp_1;
       measurements[i].temp_2 = temp_2;
    }
    this->firstTime = 0;
  } else {
    for (int i=1; i< LEN ; ++i) {
       measurements[i].temp_1 = measurements[i-1].temp_1;
       measurements[i].temp_2 = measurements[i-1].temp_2;
    }
    measurements[0].temp_1 = temp_1;
    measurements[0].temp_2 = temp_2;
  }
}
