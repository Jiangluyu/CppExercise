#include"Shape.h"

using namespace std;

int main()
{
	int choice = -1;
	int x;
	int y;
	int z;
	double input;
	double area;
	double volumn;

	Circle circle;
	Triangle triangle;
	Sphere sphere;
	Tetrahedron tetrahedron;

	do {
		cout << "Please choose a shape or 0 to exit:" << endl;
		cout << "1.Circle" << endl;
		cout << "2.Triangle" << endl;
		cout << "3.Sphere" << endl;
		cout << "4.Regular Tetrahedron" << endl;
		cout << "0.exit" << endl;
		cout << "Choice: ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "You have chosen the circle" << endl << endl;
			cout << "Please enter the center of the circle (x-coordinate and then y-coordinate):" << endl;
			cin >> x;
			cin >> y;
			circle.setcoordinate(x, y);
			cout << "Please enter the radius of the circle:" << endl;
			cin >> input;
			area = circle.getArea(input);
			cout << "The circle with radius " << input << " that is located at(" << x << "," << y << ")has:" << endl;
			cout << "An area of " << area << endl << endl;
			break;
		case 2:
			cout << "You have chosen the triangle" << endl << endl;
			cout << "Please enter the center of the triangle (x-coordinate and then y-coordinate):" << endl;
			cin >> x;
			cin >> y;
			triangle.setcoordinate(x, y);
			cout << "Please enter the edge of the triangle:" << endl;
			cin >> input;
			area = triangle.getArea(input);
			cout << "The triangle with edge " << input << " that is located at(" << x << "," << y << ")has:" << endl;
			cout << "An area of " << area << endl << endl;
			break;
		case 3:
			cout << "You have chosen the sphere" << endl << endl;
			cout << "Please enter the radius of the sphere (x-coordinate, y-coordinate, then z-coordinate):" << endl;
			cin >> x;
			cin >> y;
			cin >> z;
			sphere.setcoordinate(x, y, z);
			cout << "Please enter the radius of the sphere:" << endl;
			cin >> input;
			area = sphere.getArea(input);
			volumn = sphere.getVolumn();
			cout << "The sphere with radius " << input << " at location(" << x << "," << y << "," << z << ")has:" << endl;
			cout << "Surface area of " << area << endl;
			cout << "Volumn of " << volumn << endl << endl;
			break;
		case 4:
			cout << "You have chosen the regular tetrahedron" << endl << endl;
			cout << "Please enter the edge length of the tetrahedron:" << endl;
			cin >> input;
			area = tetrahedron.getArea(input);
			volumn = tetrahedron.getVolumn();
			cout << "Please enter the center of the regular tetrahedron (x-coordinate, y-coordinate, then z-coordinate):" << endl;
			cin >> x;
			cin >> y;
			cin >> z;
			tetrahedron.setcoordinate(x, y, z);
			cout << "The tetrahedron with edge length " << input << " at location(" << x << "," << y << "," << z << ")has:" << endl;
			cout << "Surface area of " << area << endl;
			cout << "Volumn of " << volumn << endl << endl;
			break;
		default:
			system("CLS");
			fflush(stdin);
			break;
		}
	} while (choice != 0);

	return 0;
}