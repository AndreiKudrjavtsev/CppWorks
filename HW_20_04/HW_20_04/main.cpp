#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool foundNull(vector<vector<int>> v) {
	return any_of(v.begin(), v.end(), 
		[](vector<int> vect) -> bool { return all_of(vect.begin(), vect.end(), 
			[](int numb) -> bool {return numb % 10 == 0; }
			); }
		);
}

// при вводе данных после "*" нужен пробел :)
void avrgScore() {
	map<string, double> marks;
	string name;
	double mark;
	string s;
	int uuu;
	bool isName = true;
	cin >> name >> uuu;
	while (getline(cin, s, ' ')) {
		if (isName) {
			name = s;
			if (s == "*")
				break;
			isName = false;
		}
		else {
			mark = stod(s);
			if (marks.find(name) == marks.end()) {
				marks[name] = mark;
				isName = true;
			}
			else {
				marks[name] = (marks[name] + mark) / 2;
				isName = true;
			}
		}
	}
	for (auto it = marks.begin(); it != marks.end(); it++)
		cout << it->first << " " << it->second << endl;
}

int main() {
	vector<vector<int>> v = { {1, 4, 10 }, {10, 20, 3}, {5, 4, 10} };
	vector<vector<int>> v1 = { { 1, 4, 10 },{ 10, 20, 30 },{ 5, 4, 10 } };
	cout << foundNull(v) << endl;
	cout << foundNull(v1) << endl;

	avrgScore();

	return 0;
}