#include <vector>
#include "Shapes.h"

#pragma once

class shapeCollection {
	std::vector<shape*> a;
public:
	shapeCollection() {};
	~shapeCollection() {
		for (auto sh : a)
			delete sh;
	}
	shapeCollection& operator=(const shapeCollection& shColl) {
		if (this != &shColl) {
			delete this;
			a = std::vector<shape*>();
			for (auto it = 0; it != shColl.a.size(); it++) {
				shColl.a.at(it)->info();
				a.push_back(shColl.a.at(it));
			}	
		}
		return *this;
	}
	shapeCollection(const shapeCollection& shColl) {
		std::vector<shape*> newOne;
		for (auto i = 0; i != shColl.a.size(); i++) {
			shColl.a.at(i)->info();
			a.push_back(shColl.a.at(i));
		}
	}
	void add(shape* sh)
	{
		a.push_back(sh);
	}
	double area() const
	{
		double sum = 0;
		for (auto sh : a)
			sum += sh->area();
		return sum;
	}
};