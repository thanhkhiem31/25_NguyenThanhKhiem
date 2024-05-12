#include "Rectangle.h"

void Rectangle::setWidth(int _width)
{
	width = _width;
}

int Rectangle::getWidth() const
{
	return width;
}

void Rectangle::setHeight(int _height)
{
	height = _height;
}

int Rectangle::getHeight() const
{
	return height;
}

int Rectangle::area()
{
	return width * height;
}
