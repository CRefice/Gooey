#pragma once

#include <string>

#include "Control.hpp"
#include "Font.hpp"

namespace Goo
{
class Label : public Control
{
public:
  Label() : Control() {}
  Label(const std::string& text) : text(text), Control() {}
  Label(const std::string& text, const Point& pos, const Size& size) : text(text), Control(pos, size) {}

  void CreateControl() override;

  void SetText(const std::string& text_);
  std::string GetText() { return text; }

private:
  std::string text;
};
}
