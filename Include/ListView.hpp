#pragma once

#include <vector>

#include "Control.hpp"
#include "Text.hpp"

namespace Goo
{
class ColumnHeader
{
public:
  ColumnHeader(const std::string& text, int width) : text(text), width(width) {}

  std::string GetText() const { return text; }
  int GetWidth() const { return width; }

  void SetTextAlignment(TextAlignment alignment_);
  TextAlignment GetTextAlignment() const { return alignment; }

private:
  TextAlignment alignment = TextAlignment::Center;
  std::string text;
  int width;
};

typedef ColumnHeader ListViewItem;

class ListView : public Control
{
public:
  ListView() : Control() {}
  ListView(const Point& pos, const Size& size) : Control(pos, size) {}

  void CreateControl() override;

  void AddColumn(const ColumnHeader& column);
  void AddItem(const ListViewItem& item);

  std::vector<ColumnHeader> GetColumns() { return columns; }
  std::vector<ListViewItem> GetItems() { return items; }

private:
  void DoAddColumn(const ColumnHeader& column);
  void DoAddItem(const ListViewItem& item);
  std::vector<ColumnHeader> columns;
  std::vector<ListViewItem> items;
};
}
