#ifndef _HID_DEVICE_HPP_
# define _HID_DEVICE_HPP_

#include <atomic>
#include <memory>
#include <exception>
#include <stdexcept>
#include <string>
#include <cstdint>
#include <hidapi.h>

class HidDevice
{
public:
  typedef std::basic_string<unsigned char> Buffer;

private:
  static std::atomic<bool>   _init;
  static std::atomic<size_t> _nbInstance;

public:
  HidDevice(uint16_t vendor_id, uint16_t product_id);
  virtual ~HidDevice();

  void sendFeatureReport(const HidDevice::Buffer& buff);

private:
  hid_device* _handle;
  uint16_t _vendor_id;
  uint16_t _product_id;
};


#endif
