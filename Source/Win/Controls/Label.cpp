#include "Label.hpp"

namespace Goo
{
void Label::CreateControl()
{
	CreateHandle("STATIC", text, SS_LEFT);
}

void Label::SetText(const std::string& text_)
{
	::SetWindowText(GetHandle(), text_.c_str());
	text = text_;
}
}
