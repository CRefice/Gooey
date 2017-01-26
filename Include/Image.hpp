#pragma once

#include <string>

#include "Handle.hpp"

namespace Goo
{
class Image
{
public:
	Image() : handle() {}
	explicit Image(const std::string& filePath);
	explicit Image(ImageHandle handle) : handle(handle) {}	

	ImageHandle& GetHandle() { return handle; }
	const ImageHandle& GetHandle() const { return handle; }

private:
	ImageHandle handle;
};
}
