#pragma once

#include "Control.hpp"

namespace Goo
{
class Label : public Control
{
public:
	Label() : Control() {}
	Label(const std::string& text) : Control(text) {}
	Label(const std::string& text, const Point& pos, const Size& size) : Control(text, pos, size) {}

	void CreateControl() override;
};
}
