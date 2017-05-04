#include <iostream>
#include "Day.h"
#include "NumericLimits.h"

using namespace std;

void parseDouble(double x) {
	auto p = (int*)&x;
	for (int i = 0; i < 2; i++) {
		cout << p[i] << " ";
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");

	// macro for 5th task
	#define ASSERT(exp) if (!(exp)) cout << "error" << endl
	// macro for 7th task
	#define FOR(iter, bound) for (int iter = 0; iter < bound; iter++)

	// test for 1st task
	string date;
	cout << "������� ���� (� ������� ��.��): " << endl;
	cin >> date;
	DayOfYear test = DayOfYear(date);
	Message mes = Message(test);
	cout << mes.message << endl;
	cout << endl;

	// test for 2nd task
	cout << "������������ �������� ����� ��� ������ ������: " << endl;
	cout << "bool: " << NumericLimits<bool>::max() << endl;
	cout << "double: " << NumericLimits<double>::max() << endl;
	cout << "float: " << NumericLimits<float>::max() << endl;
	cout << "int: " << NumericLimits<int>::max() << endl;
	cout << "long: " << NumericLimits<long>::max() << endl;	cout << "unsigned short: " << NumericLimits<unsigned short>::max() << endl;	cout << endl;

	// test for 4th task
	cout << "�������� ����� 3.1415 �� 2 int" << endl;
	double x = 3.1415;
	parseDouble(x);
	cout << endl;

	// test for 5th
	cout << "���� ��� ��������� �������: " << endl;
	int i = -10;
	ASSERT(i > 0);
	cout << "���� ��� ������� �������: " << endl;
	int k = 10;
	ASSERT(k > 0);
	cout << endl;

	// test for 7th
	cout << "���� ��� ������� ����� (������� i ��� ������� 3): " << endl;
	FOR(i, 3) {
		cout << i << " ";
	}
	cout << endl;



	return 0;
}