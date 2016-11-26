#include <functional>

#include "Platform.hpp"

#include "App.hpp"

namespace Goo
{
	void Application::Run()
	{
		MSG msg;
		while (GetMessage(&msg, NULL, 0, 0) != 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	void Application::Quit()
	{
		PostQuitMessage(0);
	}

	void Application::PollEvents()
	{
		MSG Msg;
		while (PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
	}
}

#pragma comment(linker, "\"/manifestdependency:type='win32' \
						name='Microsoft.Windows.Common-Controls' \
						version='6.0.0.0' \
						processorArchitecture='*' \
						publicKeyToken='6595b64144ccf1df' language='*'\"")
