#pragma once

#include "Control.hpp"
#include "Event.hpp"

namespace Goo
{
class ButtonBase : public Control
{
public:
	ButtonBase() : Control() {}
	ButtonBase(const std::string& text) : Control(text) {}
	ButtonBase(const std::string& text, const Point& pos, const Size& size) : Control(text, pos, size) {}

	Event<> OnClick;
};
}
