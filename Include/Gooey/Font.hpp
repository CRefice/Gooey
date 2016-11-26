#pragma once

#include <string>

#include "Platform.hpp"

namespace Goo
{
enum class FontStyle
{
	Bold, Italic, Underline, Strikethrough
};

class Font
{
public:
  Font(const std::string& typeface_, int size_);
  Font(FontHandle handle);
  
  FontHandle GetHandle() { return handle; }
  const FontHandle GetHandle() const { return handle; }
  
private:
  std::string typeface;
  int size;
  
  FontHandle handle;
};

Font DefaultFont();
}
