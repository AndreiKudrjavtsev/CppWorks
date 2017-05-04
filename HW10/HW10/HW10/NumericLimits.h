#pragma once
#include <limits>

template<class T>
class NumericLimits {
public:
	static T max();
};

bool NumericLimits<bool>::max() {
	return true;
}
double NumericLimits<double>::max() {
	return DBL_MAX;
}
float NumericLimits<float>::max() {
	return FLT_MAX;
}
int NumericLimits<int>::max() {
	return INT_MAX;
}
long NumericLimits<long>::max() {
	return LONG_MAX;
}
unsigned short NumericLimits<unsigned short>::max() {
	return 0xFFFF;
}