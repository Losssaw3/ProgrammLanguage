#include <iostream>
#include <cmath>
using namespace std;
/*
*\brief определяет значение функции y(x) 
*\param Argument аргумент функции
*\return Возвращает значение функции
*/
double GetValue(double Argument);
/*
*\brief определяет интервал и шаг табуляции
*\param Message - побуждающее сообщение
*\return Возвращает интервал и шаг табуляции
*/
double GetInterval(const string& Message = "");
/*
*\brief Точка входа в программу
*\return Возвращает 0 в случае успеха
*/
int main()
{
	setlocale(LC_ALL, "Rus");
	const double LeftSide = GetInterval("Введите крайнее левое значение");
	const double RightSide = GetInterval("Введите крайнее правое значение");
	const double Step = GetInterval("Введите шаг");
	double Argument = 0.0;
	if (LeftSide < RightSide and Step > 0)
	{
		for (Argument = LeftSide; Argument <= RightSide; Argument = Argument + Step) {
			double Value = GetValue(Argument);
			cout << "x = " << Argument << "      " << "y =" << Value << endl;
		}
	}
	else
	{
		cout << "Правое крайнее значение должно быть больше левого,шаг должен быть больше 0!" << endl;
		return 1;
	}
	return 0;
}
double GetValue(double Argument) {
	return Argument * Argument * Argument * 0.29 + Argument - 1.2502;
}

double GetInterval(const string& Message)
{
	cout << Message;
	double Interval = 0.0;
	cin >> Interval;
	return Interval;
}