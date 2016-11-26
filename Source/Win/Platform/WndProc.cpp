#include "Window.hpp"
#include "Button.hpp"

#include "Platform.hpp"

namespace Goo
{
template<typename T>
T* WinPtrFromHandle(HWND handle)
{
	return static_cast<T*>(::GetProp(handle, "PROP_CONTROL"));
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	Window* sender = WinPtrFromHandle<Window>(hwnd);

	switch (msg)
	{
	case WM_DESTROY:
	{
		if (sender) sender->OnDestroy();
		return 0;
	}

	case WM_CLOSE:
	{
		if (!sender) return 0;

		CancelToken token;
		sender->OnClose(token);
		if (!token.cancel) sender->Close();
		return 0;
	}

	case WM_COMMAND:
	{
		switch (HIWORD(wparam))
		{
		case BN_CLICKED:
			ButtonBase* clicked = WinPtrFromHandle<ButtonBase>((HWND)lparam);
			if (clicked) clicked->OnClick();

			else if (sender->GetMenuBar() != nullptr)
			{
				sender->GetMenuBar()->GetFromID(LOWORD(wparam))->OnClick();
			}
		}
		return 0;
	}
	case WM_SIZE:
	{
		if (sender) sender->OnResize({ LOWORD(lparam), HIWORD(lparam) });
		return 0;
	}

	default:
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}
}
}
