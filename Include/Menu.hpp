#pragma once

#include <vector>

#include "Event.hpp"
#include "Handle.hpp"

namespace Goo
{
class MenuItem
{
public:
  Event<> OnClick;

protected:
  MenuItem(const std::string& text, long style);
  MenuItem(const std::string& text, long style, uintptr_t id);

  MenuHandle container;
  uintptr_t id;
  std::string text;

private:
  long style;

  friend class Menu;
};

class TextItem : public MenuItem
{
public:
  TextItem(const std::string& text_);

  void SetChecked(bool state);
  bool IsChecked() const { return checked; }

  std::string GetText() const { return text; }

private:
  bool checked;
};

class SeparatorItem : public MenuItem
{
public:
  SeparatorItem();
};

class Menu
{
public:
  Menu();

  void AppendItem(MenuItem& item);
  MenuItem* GetFromID(int id);

  MenuHandle& GetHandle() { return handle; }
  const MenuHandle& GetHandle() const { return handle; }

private:
  MenuHandle handle;
};

class MenuBar : public Menu
{};

class PopupMenuItem : public Menu, public MenuItem
{
public:
  PopupMenuItem(const std::string& text);

  std::string GetText() const { return text; }
};
}
