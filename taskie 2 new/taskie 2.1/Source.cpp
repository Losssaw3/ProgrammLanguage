#include <iostream>
using namespace std;
/**
*\brief Функция вычисляет периметр прямоугольного треугольника
*\param FirstCathet аргумент функции (первый катет)
*\param SecondCathet аргумент функции (второй катет)
*\return Возвращает значение периметра
*/
const double getPerimeter(const double firstCathet,const double secondCathet);
/**
*\brief Функция вычисляет площадь прямоугольного треугольника
*\param FirstCathet аргумент функции (первый катет)
*\param SecondCathet аргумент функции (второй катет)
*\return Возвращает значение площади
*/
const double getArea(const double firstCathet,const double secondCathet);
/*
*\brief Список возможных операций
* \param Perimeter - вычисление периметра прямоугольного треугольника 
* \param Area - вычисление площади прямоугольного треугольника
*/
enum class userInput
{
	perimeter,
	area
};
/**
*\brief Точка входа в программу
*\return Возвращает 0 в случае успеха
*/
int main()
{
	setlocale(LC_ALL, "Rus");
	double firstCathet = 0.0;
	double secondCathet = 0.0;
	cout << "Введите длину первого катета" << endl;
	cin >> firstCathet;
	cout << "Введите длину второго катета" << endl;
	cin >> secondCathet;
	if (firstCathet or secondCathet < 0)
	{
		cout << "Введено недопустимое значение!" << endl;
		return 1;
	}
	const double perimeter = getPerimeter(firstCathet, secondCathet);
	const double area = getArea(firstCathet, secondCathet);
	cout << "Введите номер операции" << '\n'
		<< static_cast <int>(userInput::area) << "    " << "Вычисление площади" << '\n'
		<< static_cast <int>(userInput::perimeter) << "    " << "Вычисление периметра";
	int input = 0;
	cin >> input;
	const auto choice = static_cast<userInput>(input);
	switch (choice)
	{
	case userInput::area:
	{
		const auto area = getArea(firstCathet, secondCathet);
		cout << area << endl;
		break;
	}
	case userInput::perimeter:
	{
		const auto perimeter = getPerimeter(firstCathet, secondCathet);
		cout << perimeter << endl;
		break;
	}
	default:
	{
		cout << "Нет такой операции!" << endl;
	}
	}
	return 0;
}
const double getPerimeter(const double firstCathet,const double secondCathet)
{
	return (firstCathet + secondCathet + (sqrt((firstCathet * firstCathet) + (secondCathet * secondCathet))));
}
const double getArea(const double firstCathet,const double secondCathet)
{
	return (firstCathet * secondCathet) / 2.0;
}
