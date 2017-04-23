#include "Shapes.h"

double square::area() const {
	return size*size;
}
double square::perimeter() const {
	return 4 * size;
}
std::unique_ptr<shape> square::copy() const {
	std::unique_ptr<shape> sh(new square(x, y, size));
	return sh;
}

double rhomb::area() const {
	return 2 * w*h;
}
double rhomb::perimeter() const {
	return 4 * sqrt(w*w + h*h);
}
std::unique_ptr<shape> rhomb::copy() const {
	std::unique_ptr<shape> sh(new rhomb(x, y, w, h));
	return sh;
}

double circle::area() const {
	return M_PI * r * r;
}
double circle::perimeter() const {
	return 2 * M_PI * r;
}
std::unique_ptr<shape> circle::copy() const {
	std::unique_ptr<shape> sh(new circle(x, y, r));
	return sh;
}