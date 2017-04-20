#include <math.h>
#include <iostream>

#pragma once

class shape {
protected:
	int x, y;
public:
	shape(int x_, int y_) : x(x_), y(y_)
	{}
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual void info() const = 0;
	virtual ~shape() {}
	// Е и еще м.б. draw() и т.д. Е
};

class square : public shape {
	int size;
public:
	square(int x_, int y_, int size_) :
		shape(x_, y_), size(size_)
	{}
	double area() const override;
	double perimeter() const override;
	void info() const override;
};

class rhomb : public shape {
	int w, h;
public:
	rhomb(int x_, int y_, int w_,
		int h_) : shape(x_, y_), w(w_),
		h(h_)
	{}
	double area() const override;
	double perimeter() const override;
	void info() const override;
};