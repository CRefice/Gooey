#include "RadioButton.hpp"

namespace Goo
{
void RadioButton::CreateControl()
{
	CreateHandle("BUTTON", BS_AUTORADIOBUTTON);
}
}
