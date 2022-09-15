#include <iostream>
#include <cmath>
using namespace std;
/**
* \ brief ������ � �� �������� �������
* \ param x ����� �������� �������
* \ param y ������ �������� �������
* \ return �������� �
*/
double getA(const double x, const double y);
/**
* \ brief ������ b �� �������� �������
* \ param x ����� �������� �������
* \ param y ������ �������� �������
* \ param z ������ �������� �������
* \ return �������� b
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