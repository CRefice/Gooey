#pragma once

#ifdef _WIN32
#include <Windows.h>
#include <CommCtrl.h>

//The WinApi defines a macro, MessageBox,
//which conflicts with our MessageBox namespace.
#undef MessageBox

namespace Goo
{
using ControlHandle = HWND;
using FontHandle = HFONT;
using MenuHandle = HMENU;
struct GLContext
{
  HDC hdc;
  HGLRC hglrc;
};

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
}
#endif
