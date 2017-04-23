#include <vector>
#include "Shapes.h"

#pragma once

class shapeCollection {
	std::vector<std::unique_ptr<shape>> a;
public:
	shapeCollection() {};
	//~shapeCollection() {};
	shapeCollection& operator=(const shapeCollection& shColl) {
		if (this != &shColl) {
			a.clear();
			for (auto &sh : shColl.a) {
				a.push_back(sh->copy());
			}	
		}
		return *this;
	}
	shapeCollection(const shapeCollection& shColl) {
		for (auto &sh : shColl.a) {
			a.push_back(sh->copy());
		}
	}

	void add(std::unique_ptr<shape> sh) {
		a.push_back(sh);
	}

	double area() const {
		double sum = 0;
		for (auto &sh : a)
			sum += sh->area();
		return sum;
	}
};