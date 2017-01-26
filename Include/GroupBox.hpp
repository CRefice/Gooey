#pragma once

#include <string>

#include "Control.hpp"

namespace Goo
{
class GroupBox : public Control
{
public:
  GroupBox() : Control() {}
  GroupBox(const std::string& text) : text(text), Control() {}
  GroupBox(const std::string& text, const Point& pos, const Size& size) : text(text), Control(pos, size) {}

  void CreateControl() override;

private:
  std::string text;
  Font font = DefaultFont();
};
}
