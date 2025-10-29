//
//  PrintableBigNumber.h
//
//  Author:  Nick Gammon
//  Date:    22nd January 2013.
//  Contributors: Paul Stoffregen, S. Downey
//  Version: 3.5
//  Released into the public domain.
//  Added print function as suggested by Paul Stoffregen.

#ifndef _PrintableBigNumber_h
#define _PrintableBigNumber_h

#include <Arduino.h>
#include <BigNumber.h>

class PrintableBigNumber : public Printable
{
  public:
    explicit PrintableBigNumber(const BigNumber& big) : big(big) {}
    ~PrintableBigNumber() = default;

    virtual size_t printTo(Print& p) const; // for Arduino Serial.print()

  private:
    BigNumber big;
};  // end class declaration

#endif
