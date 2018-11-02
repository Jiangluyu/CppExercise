#pragma once
#include <iostream>
#include <corecrt_math_defines.h>
#include<math.h>

class Shape
{
public:
	virtual double getArea(double input) = 0;
};

class TwoDimensionalShape :public Shape {
public:
	void setcoordinate(int x, int y);
protected:
	int xcoordinate;
	int ycoordinate;
};

class ThreeDimensionalShape :public Shape {
public:
	void setcoordinate(int x, int y, int z);
	virtual double getVolumn() = 0;
protected:
	int xcoordinate;
	int ycoordinate;
	int zcoordinate;
};

class Circle :public TwoDimensionalShape {
public:
	double getArea(double input);

protected:
	double radius;
};

class Triangle :public TwoDimensionalShape {
public:
	double getArea(double input);

protected:
	double edge;
};

class Sphere :public ThreeDimensionalShape {
public:
	double getArea(double input);
	double getVolumn();

protected:
	double radius;
};

class Tetrahedron :public ThreeDimensionalShape {
public:
	double getArea(double input);
	double getVolumn();

protected:
	double edge;
};