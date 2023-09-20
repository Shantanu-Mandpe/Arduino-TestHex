#ifndef TestHex_h
#define TestHex_h

#include "Arduino.h"

class TestHex
{
  public:
    TestHex(int pin);
    void convert(const char* str,int16_t txt);
  private:
    int _pin;
};

#endif