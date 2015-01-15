#include "MsiKeyboard.hpp"

MsiKeyboard::MsiKeyboard(uint16_t vendor_id, uint16_t product_id)
  : _device(vendor_id, product_id)
{
}
