#include "MsiKeyboard.hpp"

MsiKeyboard::MsiKeyboard(uint16_t vendor_id, uint16_t product_id)
  : _device(vendor_id, product_id)
{
}

void MsiKeyboard::setColor(MsiKeyboard::Regions region,
							uint8_t r, uint8_t g, uint8_t b, MsiKeyboard::Modes m)
{
  HidDevice::Buffer buff;
  buff.resize(8);

  buff[0] = 1;
  buff[1] = 2;
  buff[2] = 64;
  buff[3] = region;
  buff[4] = r;
  buff[5] = g;
  buff[6] = b;
  buff[7] = 236;

  _device.sendFeatureReport(buff);

  buff[0] = 1;
  buff[1] = 2;
  buff[2] = 65; // commit
  buff[3] = m; // set hardware mode
  buff[4] = 0;
  buff[5] = 0;
  buff[6] = 0;
  buff[7] = 236; // EOR

  _device.sendFeatureReport(buff);
}
