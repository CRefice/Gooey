#pragma once

#ifdef _WIN32
//Do not include other headers such as winsock.h
#define WIN32_LEAN_AND_MEAN
//Do not define min and max macros, which are unneeded in C++
#define NOMINMAX

#include <Windows.h>
#include <CommCtrl.h>
#include <CommDlg.h>

//The WinApi defines a macro, MessageBox,
//which conflicts with our MessageBox namespace.
#undef MessageBox

namespace goo
{
using NativeControl = HWND;
using NativeFont = HFONT;
using NativeMenu = HMENU;
using NativeImage = HBITMAP;
struct GLContext
{
  HDC hdc;
  HGLRC hglrc;
};

LRESULT CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
}
#endif
