#pragma once

#include <string>
#include <iostream>

class Book {
public:
	Book(std::string author_, std::string name_, int year_) :
		author(author_), name(name_) {
		try {
			if (year_ < 1440 || year_ > 2014)
				throw "incorrect year";
			else 
				year = year_;
		}
		catch (char *s) {
			std::cout << s << std::endl;
		}
	}
	void print() {
		std::cout << "Author: " << author << std::endl
			<< "Name: " << name << std::endl
			<< "Year: " << year << std::endl;
	}
	bool operator< (Book b) {
		if (author < b.author)
			return true;
		else if (author == b.author && name < b.name)
			return true;
		else if (author == b.author && name == b.name && year < b.year)
			return true;
		return false;
	}

private:
	std::string author;
	std::string name;
	int year;
};