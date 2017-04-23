#include"Day.h"

DayOfYear::DayOfYear(std::string date) {
	std::string num;
	std::stringstream nums(date);
	int count = 0;
	while (std::getline(nums, num, '.')) {
		if (count == 0)
			_day = std::stoi(num);
		else if (count == 1)
			_month = std::stoi(num);
		count++;
	}
}

bool DayOfYear::operator==(const DayOfYear & date) {
	if (_day == date._day && _month == date._month)
		return true;
	return false;
}

Message::Message(DayOfYear date) {
	this->date = date;
	if (date == DayOfYear(1, 1))
		this->message = "Новый год";
	else if (date == DayOfYear(7, 1))
		this->message = "Рождество";
	else if (date == DayOfYear(8, 3))
		this->message = "8 марта";
	else if (date == DayOfYear(1, 5))
		this->message = "День весны и труда";
	else if (date == DayOfYear(9, 5))
		this->message = "День победы";
	else
		this->message = "Обычный день ";
}
