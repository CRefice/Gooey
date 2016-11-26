#pragma once

#include "Window.hpp"

namespace Goo
{
class GLWindow : public Window
{
public:
	void CreateControl() override;
	void SwapBuffers();

	void SetViewport(const Point& pos, const Size& size);
	void SetSize(const Size& size) override;

	void SetFullscreen();
	void SetVsync(bool enable);

private:
	GLContext context;
};
}
