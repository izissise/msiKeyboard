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
    LOGO = 4,
    FRONTRIGHT = 5,
    FRONTLEFT = 6,
    MOUSE = 7,
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

  void setColor(MsiKeyboard::Regions region,
                    uint8_t r, uint8_t g, uint8_t b, MsiKeyboard::Modes m);

protected:
  HidDevice  _device;
};

#endif // MSIKEYBOARD_H
