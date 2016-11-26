#include "Control.hpp"

namespace Goo
{
Control::Control() : text(""), pos(DefaultPosition()), size(DefaultPosition()) {}
Control::Control(const std::string & text_) : text(text_), pos(DefaultPosition()), size(DefaultPosition()) {}
Control::Control(const std::string & text, const Point & pos, const Size & size) : text(text), pos(pos), size(size) {}

void Control::Create()
{
	CreateControl();
	created = true;
}

void Control::SetVisible(bool state)
{
	if (!IsCreated()) Create();
	::ShowWindow(handle, state ? SW_SHOW : SW_HIDE);
}
bool Control::IsVisible() const
{
	return ::IsWindowVisible(handle) == TRUE;
}

void Control::SetEnabled(bool state)
{
	::EnableWindow(handle, state);
}
void Control::Enable()
{
	SetEnabled(true);
}
void Control::Disable()
{
	SetEnabled(false);
}
bool Control::IsEnabled() const
{
	return ::IsWindowEnabled(handle) == TRUE;
}

void Control::SetParent(const Control* parent_)
{
	parent = parent_;
}
void Control::SetText(const std::string& text_)
{
	::SetWindowText(handle, text_.c_str());
	text = text_;
}
void Control::SetBounds(const Point& pos_, const Size& size_)
{
	::MoveWindow(handle, pos_.x, pos_.y, size_.x, size_.y, true);
	pos = pos_;
	size = size_;
}
void Control::SetPosition(const Point& pos_)
{
	SetBounds(pos_, size);
}
void Control::SetSize(const Size& size_)
{
	SetBounds(pos, size_);
}
void Control::SetFont(const Font& font_)
{
	::SendMessage(handle, WM_SETFONT, (WPARAM)font_.GetHandle(), TRUE);
	font = font_;
}

void Control::CreateHandle(const char* name, long style, long exStyle)
{
	if (parent) style |= WS_CHILD;
	style |= WS_VISIBLE;

	handle = ::CreateWindowEx(exStyle,
		name, text.c_str(), style,
		pos.x, pos.y, size.x, size.y,
		parent ? parent->handle : NULL,
		NULL, ::GetModuleHandle(NULL), NULL);

	if (!handle) throw std::runtime_error("Failed to create handle!");
	::SendMessage(handle, WM_SETFONT, (WPARAM)font.GetHandle(), TRUE);
	::SetProp(handle, "PROP_CONTROL", this);
}
}
