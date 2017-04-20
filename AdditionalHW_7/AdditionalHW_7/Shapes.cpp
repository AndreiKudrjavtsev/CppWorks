#include "Shapes.h"

double square::area() const
{
	return size*size;
}
double square::perimeter() const
{
	return 4 * size;
}
shape *square::copy() const
{
	return new square(x, y, size);
}

double rhomb::area() const
{
	return 2 * w*h;
}
double rhomb::perimeter() const
{
	return 4 * sqrt(w*w + h*h);
}
shape *rhomb::copy() const
{
	return new rhomb(x, y, w, h);
}