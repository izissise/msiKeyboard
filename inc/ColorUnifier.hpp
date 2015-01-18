#ifndef COLORUNIFIER_H
#define COLORUNIFIER_H

#include <cstdint>

class ColorUnifier
{
public:
  struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;

    bool operator==(const Color& c) const {return (r == c.r && b == c.b && g == c.g);};
    bool operator!=(const Color& c) const {return !(*this == c);};
  };

public:
  ColorUnifier() = default;
  virtual ~ColorUnifier() = default;

  void push_color(const ColorUnifier::Color& color);

  bool isColorChanged() const {return _sendedColor != _lastSendedColor;};
  const ColorUnifier::Color& unifColor();

protected:
  Color _sendedColor;
  Color _pushedColor;
  Color _lastSendedColor;
};

#endif // COLORUNIFIER_H
