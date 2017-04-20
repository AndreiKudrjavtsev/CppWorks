#include "Shapes.h"

double square::area() const
{
	return size*size;
}
double square::perimeter() const
{
	return 4 * size;
}
void square::info() const
{
	std::cout << "this is a square" << std::endl;
}

double rhomb::area() const
{
	return 2 * w*h;
}
double rhomb::perimeter() const
{
	return 4 * sqrt(w*w + h*h);
}
void rhomb::info() const
{
	std::cout << "this is a rhomb" << std::endl;
}