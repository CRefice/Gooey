#pragma once

#include <vector>

#include "Control.hpp"
#include "Text.hpp"

namespace goo
{
class ColumnHeader
{
public:
  ColumnHeader(std::string text, int width) : _text(std::move(text)), _width(width) {}

  std::string text() const { return _text; }
  int width() const { return _width; }

  void setTextAlignment(TextAlignment alignment);
  TextAlignment textAlignment() const { return _alignment; }

private:
  std::string _text;
  int _width;
  TextAlignment _alignment = TextAlignment::Center;
};

//Really lazy, I know, but it does the job fine
typedef ColumnHeader ListViewItem;

class ListView : public Control
{
public:
  ListView() : Control() {}
  ListView(const Point& pos, const Size& size) : Control(pos, size) {}

  void addColumn(ColumnHeader column);
  void addItem(ListViewItem item);

  std::vector<ColumnHeader> columns() { return _columns; }
  std::vector<ListViewItem> items() { return _items; }

private:
  void createControl() override;

  void doAddColumn(const ColumnHeader& column);
  void doAddItem(const ListViewItem& item);

  std::vector<ColumnHeader> _columns;
  std::vector<ListViewItem> _items;

};
}
