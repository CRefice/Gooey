#pragma once

#include <cstdint>

namespace Goo
{
struct Point
{
  Point();
  Point(int x, int y);

  int x, y;

  Point& operator+=(const Point& rhs);
  Point& operator-=(const Point& rhs);
};

Point operator+(Point lhs, const Point& rhs);
Point operator-(Point lhs, const Point& rhs);

Point DefaultPosition();

typedef Point Size;

struct Color
{
  uint8_t r, g, b;

  Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}

  static Color Red();
  static Color Green();
  static Color Blue();

  static Color Black();
  static Color White();

  static Color Control();
};
}
