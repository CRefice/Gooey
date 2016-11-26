#pragma once

#include <string>

#include "Platform.hpp"
#include "Drawing.hpp"
#include "Font.hpp"

namespace Goo
{
class Control
{
public:
  Control();
  Control(const std::string& text);
  Control(const std::string& text, const Point& pos, const Size& size);
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
  
  virtual void SetText(const std::string& text_);
  virtual void SetBounds(const Point& pos_, const Size& size_);
  virtual void SetPosition(const Point& pos_);
  virtual void SetSize(const Size& size_);
  virtual void SetFont(const Font& font_);
  
  virtual std::string GetText() const { return text; }
  virtual Point GetPosition() const { return pos; }
  virtual Size GetSize() const { return size; }
  virtual Font GetFont() const { return font; }
  
  ControlHandle GetHandle() { return handle; }
  const ControlHandle GetHandle() const { return handle; }

protected:
  void CreateHandle(const char* name, long style, long exStyle = 0);
  virtual void CreateControl() = 0;

private:
  Point pos;
  Size size;
  Font font = DefaultFont();
  std::string text;

  const Control* parent = nullptr;
  bool created = false;
  
  ControlHandle handle;
};
}
