#pragma once
#define _USE_MATH_DEFINES

#include <memory>

class shape {
protected:
	int x, y;
public:
	shape() {};
	shape(int x_, int y_) : x(x_), y(y_)
	{}
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual ~shape() {}
};

class square : public shape {
	int size;
public:
	square(int x_, int y_, int size_) :
		shape(x_, y_), size(size_)
	{}
	double area() const override;
	double perimeter() const override;
};

class rhomb : public shape {
	int w, h;
public:
	rhomb(int x_, int y_, int w_, int h_) : 
		shape(x_, y_), w(w_),
		h(h_)
	{}
	double area() const override;
	double perimeter() const override;
};

class circle : public shape {
	double r;
public:
	circle(int x_, int y_, double _r) : 
		shape(x_, y_), r(_r)
	{}
	double area() const override;
	double perimeter() const override;
};

class shapeWithHole : public shape {
	std::shared_ptr<circle> hole;
	std::shared_ptr<shape> sh;
public:
	shapeWithHole(shape *sh_, double holeR_) :
		sh(sh_), hole(std::shared_ptr<circle>(new circle(x, y, holeR_)))
	{}
	double area() const override;
	double perimeter() const override;
};