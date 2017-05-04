#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <Windows.h>

using namespace std;

void commonBook() {
	auto people = map<string, string>();
	string name;
	string book;
	while (true) {
		cin >> name >> book;
		auto ins = people.insert({ book, name });
		if (ins.second == false) {
			cout << "Интересы совпадают: " << ins.first->second
				<< " " << name << endl;
			return;
		}
	}
}

void commonInterests() {
	auto people = map<pair<string, string>, string>();
	string name, book, band;
	while (true) {
		cin >> name >> book >> band;
		auto interests = pair<string, string>(book, band);
		auto ins = people.insert({ interests, name });
		if (ins.second == false) {
			cout << "Интересы совпадают: " << ins.first->second
				<< " " << name << endl;
			return;
		}
	}
}

void commonInterest() {
	auto peopleBook = map<string, string>();
	auto peopleBand = map<string, string>();
	string name, book, band;
	while (true) {
		cin >> name >> book >> band;
		auto insBook = peopleBook.insert({ book, name });
		auto insBand = peopleBand.insert({ band, name });
		if (insBook.second == false || insBand.second == false) {
			cout << "Интересы частично совпадают: " << insBook.first->second
				<< " " << name << endl;
			return;
		}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// 1st task
	commonBook();
	// 2nd task
	commonInterests();
	// 3rd task
	commonInterest();

	return 0;
}