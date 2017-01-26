#include "Button.hpp"

namespace Goo
{
void Button::CreateControl()
{
	CreateHandle("BUTTON", GetText(), BS_PUSHBUTTON);
}
}
