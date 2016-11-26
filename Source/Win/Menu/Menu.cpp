#include <vector>
#include <algorithm>

#include "Menu.hpp"

namespace Goo
{
static int total_id = 0;

MenuItem::MenuItem(const std::string& text_, long style_) : text(text_), style(style_), id(total_id++) {}
MenuItem::MenuItem(const std::string& text_, long style_, uintptr_t id_) : text(text_), style(style_), id(id_) {}

TextItem::TextItem(const std::string & text_) : MenuItem(text_, MF_STRING) {}

void TextItem::SetChecked(bool state)
{
	::CheckMenuItem(container, (UINT)id, state ? MF_CHECKED : MF_UNCHECKED);
	checked = state;
}

SeparatorItem::SeparatorItem() : MenuItem(nullptr, MF_SEPARATOR, 0) {}

static std::vector<MenuItem*>& StaticVec()
{
  static std::vector<MenuItem*> vec;
  return vec;
}

Menu::Menu() : handle(::CreateMenu()) {}

void Menu::AppendItem(MenuItem& item)
{
	::AppendMenu(handle, item.style, item.id, item.text.c_str());
	item.container = handle;
	StaticVec().emplace_back(&item);
}

MenuItem* Menu::GetFromID(int id)
{
	auto item = std::find_if(StaticVec().cbegin(), StaticVec().cend(), [this, id](MenuItem* item)
	{
		return item->id == id;
	});

	return item != StaticVec().end() ? *item : nullptr;
}

PopupMenuItem::PopupMenuItem(const std::string& text_) : Menu(), MenuItem(text_, MF_POPUP, (UINT_PTR)GetHandle()) {}
}
