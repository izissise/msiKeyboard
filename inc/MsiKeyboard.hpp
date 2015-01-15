#ifndef MSIKEYBOARD_H
#define MSIKEYBOARD_H

#include "HidDevice.hpp"

class MsiKeyboard
{
public:
  enum Regions {
    LEFT = 1,
    MIDDLE = 2,
    RIGHT = 3,
  };

  enum Colors {
    OFF = 0,
    RED = 1,
    ORANGE = 2,
    YELLOW = 3,
    GREEN = 4,
    SKY = 5,
    BLUE = 6,
    PURPLE = 7,
    WHITE = 8,
  };

  enum Levels {
    LIGHT = 3,
    LOW = 2,
    MED = 1,
    HIGH = 0,
  };

  enum Modes {
    NORMAL = 1,
    GAMING = 2,
    BREATHE = 3,
    DEMO = 4,
    WAWE = 5,
  };

public:
  MsiKeyboard(uint16_t vendor_id, uint16_t product_id);
  virtual ~MsiKeyboard() = default;

  void setAttribute(MsiKeyboard::Regions r, MsiKeyboard::Colors cl,
					MsiKeyboard::Levels l, MsiKeyboard::Modes m);

protected:
  HidDevice  _device;
};

#endif // MSIKEYBOARD_H
