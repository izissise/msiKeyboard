#include "HidDevice.hpp"

std::atomic<bool>   HidDevice::_init(true);
std::atomic<size_t> HidDevice::_nbInstance(0);

HidDevice::HidDevice(uint16_t vendor_id, uint16_t product_id)
  : _vendor_id(vendor_id), _product_id(product_id)
{
  _nbInstance += 1;
  if (_init.exchange(false))
    {
      if (hid_init() == -1)
        throw std::runtime_error("Error: Can't init HID lib");
    }

  _handle = hid_open(_vendor_id, _product_id, NULL);
  if (_handle == nullptr)
  {
    throw std::runtime_error(std::string("Error: Can't open HID Device: ") + std::to_string(vendor_id) + " " + std::to_string(product_id));
  }
}

HidDevice::~HidDevice()
{
  hid_close(_handle);
  if (_nbInstance == 1)
    {
      hid_exit();
      _init.store(true);
    }
  _nbInstance -= 1;
}

void HidDevice::sendFeatureReport(const HidDevice::Buffer& buff) const
{
  int ret;

  ret = hid_send_feature_report(_handle, buff.data(), buff.size());
  if (ret == -1)
    {
      std::wstring ws(hid_error(_handle));
      std::string nws(ws.begin(), ws.end());

      throw std::runtime_error(std::string("Error: hid_send_feature_report") + nws);
    }
}
