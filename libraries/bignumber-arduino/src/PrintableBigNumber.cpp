//
//  BigNumber.cpp
//  
//  Author:  Nick Gammon
//  Date:    22nd January 2013.
//  Contributors: Paul Stoffregen, S. Downey
//  Version: 3.5
//  Released into the public domain.
//  Added print function as suggested by Paul Stoffregen.
//  Changed printTo to return the length, as required.

#include "PrintableBigNumber.h"

// Allow Arduino's Serial.print() to print BigNumber objects!
size_t PrintableBigNumber::printTo(Print& p) const
{
  char *buf = bc_num2str(num_);
  size_t len = p.write(buf);
  free(buf);
  return len;
}