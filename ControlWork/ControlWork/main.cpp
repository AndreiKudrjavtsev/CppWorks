#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <memory>
#include "Book.h"

using namespace std;

// 1
bool elemsAreIncreasing(int a[], int len) {
	int *p = a;
	p++;
	for (int* i = a; i < a + len - 1; i++) {
		if (*i >= *p)
			return false;
		p++;
	}
	return true;
}

// 5
void repeatedElems() {
	int a = -1;
	auto nums = map<int, int>();
	while (a != 0) {
		cin >> a;
		auto p = nums.find(a);
		if (p == nums.end()) 
			nums[a] = 1;
		else 
			p->second++;
	}
	for (auto it = nums.begin(); it != nums.end(); it++) {
		if (it->second > 2)
			cout << it->first << " ";
	}
	cout << endl;
}

// 6
template<class T>
int sumElemsWithOddIndx(T &collection) {
	int sum = 0;
	int index = 1;
	for (auto it = collection.begin(); it != collection.end(); it++) {
		if (index % 2 == 1)
			sum += *it;
		index++;
	}
	return sum;
}

// 9
auto revArray(unique_ptr<int> a[]) {
	unique_ptr<int> *b = new unique_ptr<int>[10];
	for (int i = 0; i < 10; i++) {
		b[10 - i] = move(a[i]);
	}
	return b;
}


int main() {

	// 1st task
	int *a = new int[4];
	for (int i = 0; i < 4; i++)
		a[i] = i;
	cout << elemsAreIncreasing(a, 4) << endl << endl;

	// 2nd task
	Book book = Book("", "", 1000);
	cout << endl;

	// 4th task
	Book b1 = Book("A", "A", 1500);
	Book b2 = Book("A", "B", 1600);
	Book b3 = Book("A", "B", 1700);
	Book b4 = Book("B", "B", 1500);
	cout << "Must return 1 1 1 1" << endl;
	cout << (b1 < b2) << (b2 < b3) << (b3 < b4) << (b1 < b4) << endl << endl;

	// 5th task
	//repeatedElems();
	cout << endl;

	// 6th task
	vector<int> v{ 2, 3, 6, 7, 8, 1 };
	list<int> lst{ 2, 3, 6, 7, 8, 1 };
	cout << "Vector sum: " << sumElemsWithOddIndx(v) << endl
		<< "List sum: " << sumElemsWithOddIndx(lst) << endl << endl;

	// 9th task
	auto *a = new unique_ptr<int>[10];
	for (int i = 0; i < 10; i++) {
		a[i] = unique_ptr<int>(new int(i + 1));
		cout << *a[i] << " ";
	}
	cout << endl;
	revArray(a);
	for (int i = 0; i < 10; i++)
		cout << *a[i] << " ";
	cout << endl << endl;
	delete[] a;


	return 0;
}