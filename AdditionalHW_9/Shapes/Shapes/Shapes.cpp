#include "Shapes.h"
#include <math.h>

double square::area() const {
	return size*size;
}
double square::perimeter() const {
	return 4 * size;
}

double rhomb::area() const {
	return 2 * w*h;
}
double rhomb::perimeter() const {
	return 4 * sqrt(w*w + h*h);
}

double circle::area() const {
	return M_PI * r * r;
}
double circle::perimeter() const {
	return 2 * M_PI * r;
}

double shapeWithHole::area() const {
	return sh->area() - hole->area();
}
double shapeWithHole::perimeter() const {
	return sh->perimeter() + hole->perimeter();
}