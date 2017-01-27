#include "Control.hpp"

namespace goo
{
void Control::setVisible(bool state) {
	if (!_created) create();
	::ShowWindow(_handle, state ? SW_SHOW : SW_HIDE);
}
bool Control::visible() const {
	return ::IsWindowVisible(_handle) == TRUE;
}

void Control::setEnabled(bool state) {
	::EnableWindow(_handle, state);
}
bool Control::enabled() const {
	return ::IsWindowEnabled(_handle) == TRUE;
}

void Control::setParent(const Control* parent) {
	_parent = parent;
}
void Control::setBounds(const Point& pos, const Size& size) {
	::MoveWindow(_handle, pos.x, pos.y, size.x, size.y, TRUE);
	_pos = pos;
	_size = size;
}
void Control::setPosition(const Point& pos) {
	setBounds(pos, _size);
}
void Control::setSize(const Size& size) {
	setBounds(_pos, size);
}

void Control::setFont(Font font) {
	::SendMessage(_handle, WM_SETFONT, (WPARAM)(HFONT)(font.handle()), TRUE);
	_font = font;
}

void Control::createHandle(const char* name, const std::string& text, long style, long exStyle) {
	style |= WS_VISIBLE;
	if (_parent != nullptr) style |= WS_CHILD;

	_handle = ::CreateWindowEx(exStyle,
		name, text.c_str(), style,
		_pos.x, _pos.y, _size.x, _size.y,
		_parent ? (HWND)(_parent->_handle) : NULL,
		NULL, ::GetModuleHandle(NULL), NULL);

	if (_handle == NULL) throw std::runtime_error("Failed to create handle!");
	::SendMessage(_handle, WM_SETFONT, (WPARAM)(HFONT)(_font.handle()), TRUE);
	::SetProp(_handle, "PROP_CONTROL", this);
}
}
