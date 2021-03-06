#pragma once

#include "Platform.hpp"

namespace Goo
{
template<typename T>
class Handle
{
public:
	Handle() : _handle(nullptr) {}
	Handle(T handle) : _handle(handle) {}
	Handle(const Handle& handle);
	Handle(Handle&& handle) = default;
	~Handle();

	Handle& operator=(const Handle& handle);
	Handle& operator=(Handle&& handle) = default;
	Handle& operator=(T handle);

	operator T() { return _handle; }
	operator const T() const { return _handle; }

private:
	T _handle = nullptr;
};

using ControlHandle = Handle<NativeControl>;
using FontHandle = Handle<NativeFont>;
using MenuHandle = Handle<NativeMenu>;
using ImageHandle = Handle<NativeImage>;
using LayoutHandle = Handle<NativeLayout>;
}
