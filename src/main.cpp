#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <thread>
#include <chrono>

#include "MsiKeyboard.hpp"
#include "ColorUnifier.hpp"

int main([[gnu::unused]]int ac, char *avp[])
{
  bool daemon = ((avp[1] != nullptr) && (std::string(avp[1]) == "-d"));
  bool first = true;

  while (daemon || first)
    {
      first = false;
      MsiKeyboard kb(0x1770, 0xff00);
      ColorUnifier cl;

      std::string lign;
      while (std::getline(std::cin, lign))
        {
          std::stringstream ss(lign);
          double dr, dg, db;
          ColorUnifier::Color color;

          ss >> dr >> dg >> db;
          color.r = dr * 255;
          color.g = dg * 255;
          color.b = db * 255;
          cl.push_color(color);
          color = cl.unifColor();
          if (cl.isColorChanged())
            for (auto && i : {MsiKeyboard::Regions::LEFT, MsiKeyboard::Regions::MIDDLE, MsiKeyboard::Regions::RIGHT})
              {
                kb.setColor(i, color.r, color.g, color.b, MsiKeyboard::Modes::NORMAL);
              }
        }
    }
  return 0;
}
