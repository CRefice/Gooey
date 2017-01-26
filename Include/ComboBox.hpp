#pragma once

#include <string>
#include <vector>

#include "Control.hpp"
#include "Event.hpp"

namespace Goo
{
class ComboBox : public Control
{
public:
	ComboBox() : Control() {}
	ComboBox(const Point& pos, const Size& size) : Control(pos, size) {}

	void CreateControl() override;

	void AddItem(const std::string& text);

	int GetSelectedIndex() const;
	void SelectItem(int index);

	std::string GetSelectedString() const;
	std::vector<std::string> GetItemList() const { return items; }
	
	Event<int> OnSelectionChanged;

private:
	void DoAddItem(const std::string& text);
	
	int selectedIndex = 0;
	std::vector<std::string> items;
};
}
