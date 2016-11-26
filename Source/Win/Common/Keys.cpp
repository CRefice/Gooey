#include "Platform.hpp"

#include "Keys.hpp"

namespace Goo
{
bool IsKeyDown(Key key)
{
  return ::GetAsyncKeyState(static_cast<unsigned char>(key));
}

Point GetMousePos()
{
  ::POINT retVal;
  ::GetCursorPos(&retVal);
  return { retVal.x, retVal.y };
}
}
