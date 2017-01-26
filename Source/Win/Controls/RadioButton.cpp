#include "RadioButton.hpp"

namespace Goo
{
void RadioButton::CreateControl()
{
	CreateHandle("BUTTON", text, BS_AUTORADIOBUTTON);
}
}
