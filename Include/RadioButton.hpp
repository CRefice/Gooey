#pragma once

#include "ButtonBase.hpp"

namespace Goo
{
class RadioButton : public ButtonBase
{
public:
	RadioButton() : ButtonBase() {}
	RadioButton(const std::string& text) : ButtonBase(text) {}
	RadioButton(const std::string& text, const Point& pos, const Size& size) : ButtonBase(text, pos, size) {}

	void CreateControl() override;
};
}
