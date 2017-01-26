#include "Platform.hpp"
#include <gl\GL.h>

#include "GLWindow.hpp"

static void* GetAnyGLFuncAddress(const char* name)
{
	void *p = (void *)wglGetProcAddress(name);
	if (p == 0 || (p == (void*)0x1) || (p == (void*)0x2) || (p == (void*)0x3) || (p == (void*)-1))
	{
		HMODULE module = LoadLibraryA("opengl32.dll");
		p = (void *)GetProcAddress(module, name);
	}
	return p;
}

namespace Goo
{
void GLWindow::CreateControl()
{
	Window::CreateControl();

	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
		PFD_TYPE_RGBA,            //The kind of framebuffer. RGBA or palette.
		32,                        //Colordepth of the framebuffer.
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		24,                        //Number of bits for the depthbuffer
		8,                        //Number of bits for the stencilbuffer
		0,                        //Number of Aux buffers in the framebuffer.
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};

	context.hdc = ::GetDC(GetHandle());

	const int format = ::ChoosePixelFormat(context.hdc, &pfd);
	::SetPixelFormat(context.hdc, format, &pfd);

	context.hglrc = wglCreateContext(context.hdc);
	::wglMakeCurrent(context.hdc, context.hglrc);

	SetViewport({ 0, 0 }, GetClientArea());
}

void GLWindow::SwapBuffers()
{
	::SwapBuffers(context.hdc);
}

void GLWindow::SetViewport(const Point& point, const Size& size)
{
	glViewport(point.x, point.y, size.x, size.y);
}
void GLWindow::SetSize(const Size& size)
{
	SetClientArea(size);
}

void GLWindow::SetFullscreen()
{

}

void GLWindow::SetVsync(bool enable)
{
	typedef void(*VSyncFunc)(int);
	VSyncFunc func = (VSyncFunc)GetAnyGLFuncAddress("wglSwapIntervalEXT");
	func(enable);
}
}
