#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "MsiKeyboard.hpp"

int main([[gnu::unused]]int ac, [[gnu::unused]]char *avp[])
{
  MsiKeyboard kb(0x1770, 0xff00);

  int i = 0;
  while (1)
    {
      kb.setAttribute(MsiKeyboard::Regions::LEFT, static_cast<MsiKeyboard::Colors>(i),
                      MsiKeyboard::Levels::MED, MsiKeyboard::Modes::NORMAL);

      kb.setAttribute(MsiKeyboard::Regions::MIDDLE, static_cast<MsiKeyboard::Colors>(i),
                      MsiKeyboard::Levels::MED, MsiKeyboard::Modes::NORMAL);

      kb.setAttribute(MsiKeyboard::Regions::RIGHT, static_cast<MsiKeyboard::Colors>(i),
                      MsiKeyboard::Levels::MED, MsiKeyboard::Modes::NORMAL);

      i = (i + 1) % 8;
      std::cout << std::hex << i << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }

  return 0;
}
