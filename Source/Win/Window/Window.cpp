#include <exception>

#include "Window.hpp"

namespace Goo
{
void Window::CreateControl()
{
	std::string text = GetText();

	WNDCLASSEX wclass;
	ZeroMemory(&wclass, sizeof(wclass));
	wclass.cbSize = sizeof(WNDCLASSEX);
	wclass.lpfnWndProc = WndProc;
	wclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wclass.hInstance = GetModuleHandle(NULL);
	wclass.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	wclass.lpszClassName = text.c_str();

	RegisterClassEx(&wclass);

	long wndStyle = WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | CS_OWNDC;
	long exStyle = 0;

	switch (style)
	{
	case BorderStyle::Sizeable:
		wndStyle |= WS_THICKFRAME;
		break;

	case BorderStyle::Sunken:
		exStyle |= WS_EX_CLIENTEDGE;
		break;
	}
	switch (buttons)
	{
	case StatusButtons::Maximize:
		wndStyle |= WS_MAXIMIZEBOX;
		break;

	case StatusButtons::Minimize:
		wndStyle |= WS_MINIMIZEBOX;
		break;

	case StatusButtons::Both:
		wndStyle |= (WS_MAXIMIZEBOX | WS_MINIMIZEBOX);
	}

	CreateHandle(text.c_str(), wndStyle, exStyle);
	if (menubar) ::SetMenu(GetHandle(), menubar->GetHandle());

	for (auto control : collection)
		control->Create();
}

void Window::Close()
{
	::DestroyWindow(GetHandle());
}

void Window::SetMenuBar(MenuBar* menubar_)
{
	::SetMenu(GetHandle(), menubar_->GetHandle());
	menubar = menubar_;
}

void Window::SetBorderStyle(BorderStyle style_)
{
	style = style_;
}

void Window::SetTitleBarButtons(StatusButtons style_)
{
	buttons = style_;
}

void Window::AddControl(Control& control)
{
	control.SetParent(this);
	if (IsCreated()) control.Create();

	collection.emplace_back(&control);
}

void Window::SetClientArea(const Size& area)
{
	RECT rect;
	::SetRect(&rect, 0, 0, area.x + 1, area.y + 1);

	::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW | CS_OWNDC, GetMenuBar() != nullptr);
	Control::SetSize({ rect.right - rect.left - 1, rect.bottom - rect.top - 1 });
}

Size Window::GetClientArea()
{
	RECT rect;
	::GetClientRect(GetHandle(), &rect);
	return Size(rect.right - rect.left, rect.bottom - rect.top);
}
}
