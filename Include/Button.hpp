#pragma once

#include "ButtonBase.hpp"

namespace Goo
{
class Button : public ButtonBase
{
public:
	Button() : ButtonBase() {}
	Button(const std::string& text) : ButtonBase(text) {}
	Button(const std::string& text, const Point& pos, const Size& size) : ButtonBase(text, pos, size) {}

	void CreateControl() override;
};
}
