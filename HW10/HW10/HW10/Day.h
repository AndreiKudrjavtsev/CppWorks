#pragma once
#include <string>

class DayOfYear {
public:
	DayOfYear() {}
	DayOfYear(int day, int month)
		: _day(day), _month(month)
	{}
	// receives date with "dd.mm" format
	DayOfYear(std::string date);

	bool operator==(const DayOfYear& date);

private: 
	int _day;
	int _month;
};

struct Message {
	DayOfYear date;
	std::string message;

	Message(DayOfYear date);
};