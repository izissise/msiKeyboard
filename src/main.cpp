#include <iostream>
#include <string>

#include "MsiKeyboard.hpp"

int main([[gnu::unused]]int ac, [[gnu::unused]]char *avp[])
{
  MsiKeyboard kb(0x1770, 0xff00);


  return 0;
}
