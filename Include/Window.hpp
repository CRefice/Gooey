#pragma once

#include <string>
#include <vector>

#include "Control.hpp"
#include "Event.hpp"
#include "Menu.hpp"

namespace goo
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
	Window(std::string text) : _text(std::move(text)), Control() {}
	Window(std::string text, const Point& pos, const Size& size) : _text(std::move(text)), Control(pos, size) {}
	
	void close();
	void addControl(Control& control);

	Size clientArea();
	void setClientArea(const Size& area);

	std::string text() { return _text; }
	void setText(std::string text);

	Event<CancelToken&> onClose;
	Event<> onDestroy;
	Event<Size> onResize;

	MenuBar* menuBar() { return _menuBar; }
	void setMenuBar(MenuBar* menuBar);

	BorderStyle borderStyle() { return _borderStyle; }
	void setBorderStyle(BorderStyle style);
	StatusButtons titleBarButtons() { return _titleButtons; }
	void setTitleBarButtons(StatusButtons buttons);

protected:
	void createControl() override;
	void createChildren();

private:
	MenuBar* _menuBar = nullptr;
	StatusButtons _titleButtons = StatusButtons::Both;
	BorderStyle _borderStyle = BorderStyle::Sizeable;
	std::string _text;

	std::vector<Control*> _collection;
};
}
