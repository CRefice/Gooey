#include "GroupBox.hpp"

namespace Goo
{
void GroupBox::CreateControl()
{
	CreateHandle("BUTTON", text, BS_GROUPBOX);
}
}
