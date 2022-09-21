﻿#include <iostream>
using namespace std;
/**
*\brief Функция считывает параметры тела (его длину , высоту , ширину)
*\param  Message побуждающее сообщение
*\return Возвращает значения длины , высоты , ширины тела
*/
const double getSides(const string& message = "");
/**
*\brief Функция считывает параметры отверстия (его  высоту , ширину)
*\param  MessageH побуждающее сообщение
*\return Возвращает значения  высоты , ширины отверстия
*/
int main()
{
	setlocale(LC_ALL, "Rus");
	const double length = getSides("Введите значение длины кирпича");
	const double width = getSides("Введите значение ширины кирпича");
	const double height = getSides("Введите значение высоты кирпича");
	const double holeWidth = getSides("Введите значение ширины отверстия");
	const double holeHeight = getSides("Введите значение высоты отверстия");
	if (length < 0 or width < 0 or height < 0 or holeHeight < 0 or holeWidth < 0)
	{
		cout << "Были введены недопустимые значения" << endl;
		return 1;
	}
	if ((width <= holeWidth) and (height <= holeHeight))
	{
		cout << "Кирпич пройдет!" << endl;
	}
	else
	{
		cout << "Размеры кирпича не совпадают с параметрами отверстия" << endl;
		return 1;
	}
	return 0;
}

const double getSides(const string& message)
{
	cout << message;
	double side = 0.0;
	cin >> side;
	return side;
}