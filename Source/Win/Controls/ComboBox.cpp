#include "ComboBox.hpp"

namespace Goo
{
void ComboBox::CreateControl() {
	CreateHandle(WC_COMBOBOX, "", CBS_DROPDOWNLIST | CBS_HASSTRINGS);
	for (auto& str : items) {
		DoAddItem(str);
	}
	SelectItem(selectedIndex);
}

void ComboBox::AddItem(const std::string& text) {
	DoAddItem(text);
	items.push_back(text);
}

void ComboBox::DoAddItem(const std::string& text) {
	::SendMessage(GetHandle(), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)text.c_str());
}

int ComboBox::GetSelectedIndex() const {
	return (int)(::SendMessage(GetHandle(), (UINT)CB_GETCURSEL, 0, 0));
}
void ComboBox::SelectItem(int index) {
	::SendMessage(GetHandle(), CB_SETCURSEL, index, 0);
	selectedIndex = index;
}

std::string ComboBox::GetSelectedString() const {
	char buffer[0x100];
	::SendMessage(GetHandle(), (UINT)CB_GETLBTEXT, GetSelectedIndex(), (LPARAM)buffer);
	return std::string(buffer);
}
}
