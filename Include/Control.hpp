#pragma once

#include <string>

#include "Drawing.hpp"
#include "Font.hpp"
#include "Handle.hpp"

namespace Goo
{
class Control
{
public:
  Control();
  Control(const Point& pos, const Size& size);
  explicit Control(ControlHandle handle);
  
  void Create();
  bool IsCreated() const { return created; }
  
  void SetVisible(bool state);
  void Show() { SetVisible(true); }
  void Hide() { SetVisible(false); }
  bool IsVisible() const;
  
  void SetEnabled(bool state);
  void Enable();
  void Disable();
  bool IsEnabled() const;
  
  void SetParent(const Control* parent_);
  
  void SetBounds(const Point& pos_, const Size& size_);
  void SetPosition(const Point& pos_);
  virtual void SetSize(const Size& size_);
  
  Point GetPosition() const { return pos; }
  Size GetSize() const { return size; }
  
  Font GetFont() { return font; }
  void SetFont(const Font& font_);

  ControlHandle& GetHandle() { return handle; }
  const ControlHandle& GetHandle() const { return handle; }

protected:
  virtual void CreateControl() = 0;
  void CreateHandle(const char* name, const std::string& text, long style, long exStyle = 0);

private:
  Point pos;
  Size size;
  Font font = DefaultFont();

  const Control* parent = nullptr;
  bool created = false;
  
  ControlHandle handle;
};
}
