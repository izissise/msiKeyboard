#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <thread>
#include <chrono>

#include "MsiKeyboard.hpp"

int main([[gnu::unused]]int ac, [[gnu::unused]]char *avp[])
{
  MsiKeyboard kb(0x1770, 0xff00);

  std::string lign;
  while (std::getline(std::cin, lign))
    {
      std::stringstream ss(lign);
      double dr, dg, db;

      ss >> dr >> dg >> db;
      for (auto && i : {MsiKeyboard::Regions::LEFT, MsiKeyboard::Regions::MIDDLE, MsiKeyboard::Regions::RIGHT})
        {
          kb.setColor(i, dr * 255, dg * 255, db * 255, MsiKeyboard::Modes::NORMAL);
        }
    }

  return 0;
}
