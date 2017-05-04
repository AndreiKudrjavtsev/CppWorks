#include <iostream>
#include "Shapes.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	shape* s1 = new shapeWithHole(new rhomb(0, 0, 10, 20), 3);
	shape* rh = new rhomb(0, 0, 10, 20);
	shape* crcl = new circle(0, 0, 3);
	cout << rh->area() << "\t" << crcl->area() << endl;
	cout << rh->area() - crcl->area() << endl;
	cout << s1->area() << endl;

	shape* s2 = new shapeWithHole(new square(0, 0, 400), 50);
	cout << s2->perimeter() << endl;


	return 0;
}