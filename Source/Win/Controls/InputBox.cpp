#include "InputBox.hpp"

namespace Goo
{
void InputBox::CreateControl()
{
	CreateHandle("EDIT", ES_AUTOHSCROLL, WS_EX_CLIENTEDGE);
}

std::string InputBox::GetText() const
{
	char buffer[0x100];
	GetWindowText(GetHandle(), buffer, 0x100);
	return std::string(buffer);
}
}
