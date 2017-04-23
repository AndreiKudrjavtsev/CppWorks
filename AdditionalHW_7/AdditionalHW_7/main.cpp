#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include "ShapeCollection.h"

using namespace std;

// решение 2го задани€
bool foundNull(const vector<vector<int>> &v) {
	return any_of(v.begin(), v.end(), 
		[](const vector<int> &vect) -> bool { return all_of(vect.begin(), vect.end(), 
			[](int numb) -> bool {return numb % 10 == 0; }
			); }
		);
}

// вспомогательна€ функци€ дл€ первого
double calcAvrg(const vector<int> &v) {
	double sum = 0;
	for (auto i = v.begin(); i != v.end(); i++)
		sum += *i;
	return (sum / v.size());
}

// решение 1го задани€
void avrgScore() {
	map<string, vector<int>> marks;
	string name;
	int mark;
	while (true) {
		cin >> name;
		if (name == "*")
			break;
		cin >> mark;
		marks[name].push_back(mark);
	}
	for (auto it = marks.begin(); it != marks.end(); it++)
		cout << it->first << " " << calcAvrg(it->second) << endl;
}

int main() {
	// пара тестов дл€ 2 задачи
	vector<vector<int>> v = { {1, 4, 10 }, {10, 20, 3}, {5, 4, 10} };
	vector<vector<int>> v1 = { { 1, 4, 10 },{ 10, 20, 30 },{ 5, 4, 10 } };
	cout << foundNull(v) << endl;
	cout << foundNull(v1) << endl;
	
	// 1 задача, ввод возлагаетс€ на пользовател€ 
	avrgScore();

	shapeCollection sc;
	sc.add(unique_ptr<shape> (new rhomb(1, 3, 5, 2)));
	sc.add(unique_ptr<shape> (new square(0, 0, 10)));
	cout << sc.area() << endl;	shapeCollection sc1(sc);
	shapeCollection sc2 = sc;
	cout << sc1.area() << endl;
	cout << sc2.area() << endl;

	return 0;
}