#include "Font.hpp"

namespace Goo
{
Font::Font(FontHandle handle) : handle(handle) {}

Font::Font(const std::string& typeface, int size) : typeface(typeface), size(size)
{
	//handle = CreateFont()
}

Font DefaultFont()
{
	return Font((FontHandle)GetStockObject(DEFAULT_GUI_FONT));
}
}
