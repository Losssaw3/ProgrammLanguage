#include <iostream>
#include <cmath>
using namespace std;
/**
* \ brief calculates the value of a
* \ param x the first argument of the function
* \ param y the second argument of the function
* \ return Return a value
*/
double getA(const double x, const double y);
/**
* \ brief calculates the value of b
* \ param x the first argument of the function
* \ param y the second argument of the function
* \ param z the third argument of the function
* \ return Return b value
*/
double getB(const double x, const double y, const double z);
int main()
{
	const double x = 1.825;
	const double y = 18.225;
	const double z = -3.298;
	const double a = getA(x, y);
	const double b = getB(x, y, z);
	cout << "x=" << x << "\n" << "y=" << y << "\n" << "z=" << z << endl;
	cout << "A=" << a << "\n" << "B=" << b << endl;
	return 0;
}
double getA(const double x, const double y)
{
	return (pow(x, y / x) - pow(y / x, 1.0 / 3));
}
double getB(const double x, const double y, const double z)
{
	return ((y - x) + ((y - z) / (y - x)) / (3 + (pow(z, 2) / 5)));
}