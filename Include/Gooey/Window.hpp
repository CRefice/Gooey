#pragma once

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
	Window() : Control("Window") {}
	Window(const std::string& text) : Control(text) {}
	Window(const std::string& text, const Point& pos, const Size& size) : Control(text, pos, size) {}
	
	void CreateControl() override;
	void Close();
	void CreateChildren();
	void AddControl(Control& control);

	void SetClientArea(const Size& area);
	Size GetClientArea();

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

	BorderStyle style = BorderStyle::Sizeable;
	StatusButtons buttons = StatusButtons::Both;

	std::vector<Control*>collection;
};
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
