#include "CheckBox.hpp"

namespace Goo
{
void CheckBox::CreateControl()
{
	CreateHandle("BUTTON", text, BS_AUTOCHECKBOX);
}

void CheckBox::SetChecked(bool state)
{
	::SendMessage(GetHandle(), BM_SETCHECK, state ? BST_CHECKED : BST_UNCHECKED, 0);
}

bool CheckBox::IsChecked() const
{
	return ::SendMessage(GetHandle(), BM_GETCHECK, 0, 0) == BST_CHECKED;
}
}
