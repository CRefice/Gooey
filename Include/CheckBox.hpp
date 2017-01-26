#pragma once

#include "ButtonBase.hpp"

namespace Goo
{
class CheckBox : public ButtonBase
{
public:
  CheckBox() : ButtonBase() {}
  CheckBox(const std::string& text) : ButtonBase(text) {}
  CheckBox(const std::string& text, const Point& pos, const Size& size) : ButtonBase(text, pos, size) {}

  void CreateControl() override;

  void SetChecked(bool state);
  bool IsChecked() const;
};
}
