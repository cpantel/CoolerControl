#ifndef _local_
#define _local_

#include <iostream>
#include <iomanip>
using namespace std;

typedef unsigned char byte;

#define F(x) x

class Serial {
  public:
    void print(byte b) {
      cout << (unsigned) b;
    }

    void println(byte b) {
      print(b);
      cout << endl;
    }

}

#endif
