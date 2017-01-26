#include "Font.hpp"

namespace Goo
{
Font::Font(FontHandle handle) : handle(handle) {}

Font::Font(const std::string& typeface, int size) : typeface(typeface), size(size)
{
	handle = ::CreateFont(size, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET,
		OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, typeface.c_str());
}

Font DefaultFont()
{
	return Font("Microsoft Sans Serif", 14);
	//return Font((HFONT)GetStockObject(DEFAULT_GUI_FONT));
}
}
