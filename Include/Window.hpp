#pragma once

#include <string>
#include <vector>

#include "Control.hpp"
#include "Event.hpp"
#include "Menu.hpp"

namespace Goo
{
enum class BorderStyle
{
	Fixed, Sunken, Sizeable
};
enum class StatusButtons
{
	Minimize, Maximize, Both, None
};

class Window : public Control
{
public:
	Window() : Control() {}
	Window(const std::string& text) : text(text), Control() {}
	Window(const std::string& text, const Point& pos, const Size& size) : text(text), Control(pos, size) {}
	
	void CreateControl() override;
	void Close();
	void CreateChildren();
	void AddControl(Control& control);

	void SetClientArea(const Size& area);
	Size GetClientArea();

	void SetText(const std::string& text_);
	std::string GetText() { return text; }

	Event<CancelToken&> OnClose;
	Event<> OnDestroy;
	Event<Size> OnResize;

	void SetMenuBar(MenuBar* menubar);
	MenuBar* GetMenuBar() { return menubar; }

	void SetBorderStyle(BorderStyle style);
	void SetTitleBarButtons(StatusButtons style);
	BorderStyle GetBorderStyle() { return style; }

private:
	MenuBar* menubar = nullptr;
	StatusButtons buttons = StatusButtons::Both;
	BorderStyle style = BorderStyle::Sizeable;
	std::string text;

	std::vector<Control*>collection;
};
}
