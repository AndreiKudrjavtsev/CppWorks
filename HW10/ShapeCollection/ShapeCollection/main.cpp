#include <iostream>
#include <vector>
#include "ShapeCollection.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	shapeCollection sc;
	sc.add(unique_ptr<shape> (new rhomb(1, 3, 5, 2)));
	sc.add(unique_ptr<shape> (new square(0, 0, 3)));
	shapeCollection sc1(sc);
	sc.add(unique_ptr<shape>(new circle(0, 0, 2)));
	cout << "��������� 1, �������� ����: " << endl;
	cout << sc.haveACircle() << endl;
	cout << "��������� 2, �� �������� ����: " << endl;
	cout << sc1.haveACircle() << endl;

	return 0;
}