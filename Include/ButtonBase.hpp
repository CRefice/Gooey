#pragma once

#include <string>

#include "Control.hpp"
#include "Font.hpp"
#include "Event.hpp"

namespace Goo
{
class ButtonBase : public Control
{
public:
  ButtonBase() : Control() {}
  ButtonBase(const std::string& text) : text(text), Control() {}
  ButtonBase(const std::string& text, const Point& pos, const Size& size) : text(text), Control(pos, size) {}

  Event<> OnClick;

  void SetText(const std::string& text_);
  std::string GetText() const { return text; }
  void SetFont(const Font& font_);
  Font GetFont() const { return font; }

protected:
  std::string text;
  Font font = DefaultFont();
};
}
