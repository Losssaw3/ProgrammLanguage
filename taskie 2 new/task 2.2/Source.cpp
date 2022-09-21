#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;
/**
*\brief Функция вычисляет значение функции на первом её заданном отрезке
*\param x - аргумент функции
*\param a - параметр , задаваемый пользователем
*\return Возвращает значение функции f(x) на заданном отрезке
*/
const double firstPiece(const double x, const double a);
/**
*\brief Функция вычисляет значение функции на втором её заданном отрезке
*\param x - аргумент функции
*\param a - параметр , задаваемый пользователем
*\return Возвращает значение функции f(x) на заданном отрезке
*/
const double secondPiece(const double x, const double a);
/**
*\brief Функция вычисляет значение функции на третьем её заданном отрезке
*\param x - аргумент функции
*\param a - параметр , задаваемый пользователем
*\return Возвращает значение функции f(x) на заданном отрезке
*/
const double thirdPiece(const double x, const double a);
/**
*\brief Точка входа в программу
*\return Возвращает 0 в случае успеха
*/
int main()
{
	setlocale(LC_ALL, "Rus");
	const int a = 2;
	double x = 0.0;
	cout << "Введите аргумент функции (x)" << endl;
	cin >> x;
	const double first = firstPiece(x, a);
	const double second = secondPiece(x, a);
	const double third = thirdPiece(x, a);
	if (x > 2)
	{
		cout << "y(x) =  " << third << endl;
	}
	if (x <= 2 and x >= 1)
	{
		cout << "y(x) =  " << first << endl;
	}
	if (x < 1)
	{
		cout << "y(x) = " << second << endl;
	}
	return 0;
}
const double firstPiece(const double x, const double a)
{
	return (a * pow(x, 2 * log(x)));
}

const double secondPiece(const double x, const double a)
{
	return 1;
}
const double thirdPiece(const double x, const double a)
{
	return (pow(M_E, a * x) * cos(x));
}
