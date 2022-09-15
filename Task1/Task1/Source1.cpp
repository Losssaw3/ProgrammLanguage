#include <iostream>
#include <cmath>
using namespace std;
/**
* \ brief Расчет а по заданной формуле
* \ param x Перый аргумент функции
* \ param y Второй аргумент функции
* \ return Значение а
*/
double getA(const double x, const double y);
/**
* \ brief Расчет b по заданной формуле
* \ param x Перый аргумент функции
* \ param y Второй аргумент функции
* \ param z Третий аргумент функции
* \ return Значение b
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