#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <map>

using namespace std;

bool isPerfect(int);

// returns iterator to end of collection if there are no equal elements
template<class T>
auto twoSameInARow(T &collection) {
	for (auto it = collection.begin(); it != prev(collection.end()); it++) {
		auto nx = next(it);
		if (*it == *nx)
			return it;
	}
	return collection.end();
}

int main() {

	cout << isPerfect(28) << endl;
	cout << isPerfect(7) << endl;
	cout << endl;

	list<int> test1{ 1, 10, 10, 3, 4, 5, 5 };
	vector<int> test2{ 1, 2, 3, 4, 5, 5 };
	vector<int> test3{ 1, 3, 5 };
	auto tmp = twoSameInARow(test1);
	cout << *tmp << endl;
	auto tmp2 = twoSameInARow(test2);
	cout << *tmp2 << endl;
	auto tmp3 = twoSameInARow(test3);
	if (tmp3 == test3.end())
		cout << "No equal elements" << endl;

	return 0;
}