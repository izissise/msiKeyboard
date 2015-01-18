#include "ColorUnifier.hpp"

void ColorUnifier::push_color(const ColorUnifier::Color& color)
{
  _pushedColor = color;
}

const ColorUnifier::Color& ColorUnifier::unifColor()
{
  _lastSendedColor = _sendedColor;

  int r = _pushedColor.r;
  int g = _pushedColor.g;
  int b = _pushedColor.b;

  r = (r / 4) * 4;
  g = (g / 4) * 4;
  b = (b / 4) * 4;

  _pushedColor.r = r;
  _pushedColor.g = g;
  _pushedColor.b = b;
  _sendedColor = _pushedColor;
  return _sendedColor;
}
