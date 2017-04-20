#include <vector>
#include "Shapes.h"

#pragma once

class shapeCollection {
	std::vector<shape*> a;
public:
	shapeCollection() {};
	~shapeCollection() {
		for (auto &sh : a)
			delete sh;
	}
	shapeCollection& operator=(const shapeCollection& shColl) {
		if (this != &shColl) {
			for (auto &sh : shColl.a) {
				a.push_back(sh->copy());
			}	
		}
		return *this;
	}
	shapeCollection(const shapeCollection& shColl) {
		std::vector<shape*> newOne;
		for (auto &sh : shColl.a) {
			a.push_back(sh->copy());
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