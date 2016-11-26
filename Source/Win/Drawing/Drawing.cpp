#include "Platform.hpp"

#include "Drawing.hpp"

namespace Goo
{
Point::Point() : x(0), y(0) {}
Point::Point(int x_, int y_) : x(x_), y(y_) {}

Point& Point::operator+=(const Point& rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}
Point& Point::operator-=(const Point& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

Point operator+(Point lhs, const Point& rhs) { return lhs += rhs; }
Point operator-(Point lhs, const Point& rhs) { return lhs -= rhs; }

Point DefaultPosition()
{
	return{ CW_USEDEFAULT, CW_USEDEFAULT };
}

Color Color::Red() { return Color(0xFF, 0, 0); }
Color Color::Green() { return Color(0, 0xFF, 0); }
Color Color::Blue() { return Color(0, 0, 0xFF); }
Color Color::White() { return Color(0xFF, 0xFF, 0xFF); }
Color Color::Black() { return Color(0, 0, 0); }
Color Color::Control() { return Color(240, 240, 240); }
}
