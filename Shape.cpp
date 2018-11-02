#include "Shape.h"

void TwoDimensionalShape::setcoordinate(int x, int y)
{
	xcoordinate = x;
	ycoordinate = y;
}

void ThreeDimensionalShape::setcoordinate(int x, int y, int z)
{
	xcoordinate = x;
	ycoordinate = y;
	zcoordinate = z;
}


double Circle::getArea(double input)
{
	double area = 0.0;
	radius = input;
	area = M_PI * radius * radius;
	return area;
}


double Triangle::getArea(double iuput)
{
	double area = 0.0;
	edge = iuput;
	area = sqrt(3)*pow(edge, 2.0) / 4;
	return area;
}


double Sphere::getArea(double input)
{
	double area = 0.0;
	radius = input;
	area = 4 * M_PI*pow(radius, 2.0);
	return area;
}

double Sphere::getVolumn()
{
	double volumn = 0.0;
	volumn = 4 / 3 * M_PI*pow(radius, 3.0);
	return volumn;
}

double Tetrahedron::getArea(double input)
{
	double area = 0.0;
	edge = input;
	area = sqrt(3)*pow(edge, 2.0);
	return area;
}

double Tetrahedron::getVolumn()
{
	double volumn = 0.0;
	volumn = sqrt(2) / 12 * pow(edge, 3.0);
	return volumn;
}
