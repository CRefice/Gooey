#pragma once

#include "Control.hpp"

namespace Goo
{
class InputBox : public Control
{
public:
  InputBox() : Control() {}
  InputBox(const Point& pos, const Size& size) : Control(pos, size) {}

  void CreateControl() override;

  void SetText(const std::string& text);
  std::string GetText() const;
  void SetFont(const Font& font);
  Font GetFont() { return font; }

private:
  char buffer[0x200];
  Font font = DefaultFont();
};
}
