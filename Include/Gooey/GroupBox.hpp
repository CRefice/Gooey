#pragma once

#include "Control.hpp"

namespace Goo
{
class GroupBox : public Control
{
public:
	GroupBox() : Control() {}
	GroupBox(const std::string& text) : Control(text) {}
	GroupBox(const std::string& text, const Point& pos, const Size& size) : Control(text, pos, size) {}

	void CreateControl() override;
};
}
