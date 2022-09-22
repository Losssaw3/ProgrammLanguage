#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;
/**
*\brief ������� ��������� �������� ������� �� ������ � �������� �������
*\param x - �������� �������
*\param a - �������� , ���������� �������������
*\return ���������� �������� ������� f(x) �� �������� �������
*/
const double firstPiece(const double x, const double a);
/**
*\brief ������� ��������� �������� ������� �� ������ � �������� �������
*\param x - �������� �������
*\param a - �������� , ���������� �������������
*\return ���������� �������� ������� f(x) �� �������� �������
*/
const double secondPiece(const double x, const double a);
/**
*\brief ������� ��������� �������� ������� �� ������� � �������� �������
*\param x - �������� �������
*\param a - �������� , ���������� �������������
*\return ���������� �������� ������� f(x) �� �������� �������
*/
const double thirdPiece(const double x, const double a);
/**
*\brief ����� ����� � ���������
*\return ���������� 0 � ������ ������
*/
int main()
{
	setlocale(LC_ALL, "Rus");
	const int a = 2;
	const double limit1 = 1;
	const double limit2 = 2;
	double x = 0.0;
	cout << "������� �������� ������� (x)" << endl;
	cin >> x;
	if (x > limit1)
	{
		const double third = thirdPiece(x, a);
		cout << "y(x) =  " << third << endl;
	}
	if (x <= limit2 and x >= limit1)
	{
		const double first = firstPiece(x, a);
		cout << "y(x) =  " << first << endl;
	}
	if (x < limit1)
	{
		const double second = secondPiece(x, a);
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
	return (exp(a * x) * cos(x));
}