#include <memory>
#include <iostream>
#include <type_traits>
#include <initializer_list>

using namespace std;

// task 5 function
void moveUniquePtr(unique_ptr<int> a[]) {
	for (int i = 0; i < 9; i++) {
		auto tmp = move(a[i % 10]);
		a[i % 10] = move(a[(i + 1) % 10]);
		a[(i + 1) % 10] = move(tmp);
	}
}

// task 6 function
template<typename T, typename ... T1>
T varTemplSum(const T first, const T1 ... other) {
	return first + varTemplSum(other...);
}
template<typename T>
T varTemplSum(const T sum) {
	return sum;
}

// task 7 function
template<typename T>
T initListSum(initializer_list<T> lst) {
	T sum = 0;
	for (auto it = lst.begin(); it != lst.end(); it++)
		sum += *it;
	return sum;
}

int main() {
	
	// task 1 example 
	cout << "Task 1 examples: " << endl;
	cout << "Is int a pointer? " << is_pointer<int>::value << endl;
	cout << "Is int* a pointer? " << is_pointer<int*>::value << endl << endl;

	// task 5 example
	cout << "Task 5 example: " << endl;
	auto *a = new unique_ptr<int>[10];
	for (int i = 0; i < 10; i++) {
		a[i] = unique_ptr<int>(new int(i + 1));
		cout << *a[i] << " ";
	}
	cout << endl;
	moveUniquePtr(a);
	for (int i = 0; i < 10; i++) 
		cout << *a[i] << " ";
	cout << endl << endl;
	delete[] a;

	// task 6 example
	cout << "Summ of ints from 1 to 5: " << varTemplSum(1, 2, 3, 4, 5) << endl;
	cout << "Summ of doubles 1.01, 2.02, 3.03: " << varTemplSum(1.01, 2.02, 3.03) << endl << endl;

	// task 7 example
	cout << "Summ of ints from 1 to 5 again: " << initListSum({ 1, 2, 3, 4, 5 }) << endl;
	cout << "Summ of doubles 1.01, 2.02, 3.03 again: " << initListSum({ 1.01, 2.02, 3.03 }) << endl << endl;

	return 0;
}