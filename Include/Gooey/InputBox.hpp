#pragma once

#include "Control.hpp"

namespace Goo
{
class InputBox : public Control
{
public:
	InputBox() : Control() {}
	InputBox(const std::string& text) : Control(text) {}
	InputBox(const std::string& text, const Point& pos, const Size& size) : Control(text, pos, size) {}

	void CreateControl() override;

	std::string GetText() const override;
};
}
