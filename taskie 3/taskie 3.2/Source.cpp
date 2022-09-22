#include <iostream>
#include <cmath>
using namespace std;
/*
*\brief Точка входа в программу
*\return Возвращает 0 в случае успеха
*/
int main()
{
	setlocale(LC_ALL, "Rus");
	int Counter = 1;
	int SequenceNumber;
	int FactorialNumber = 1;
	double CurrentSum = 1;
	cout << "Введите номер члена последовательности сумму которых необходимо посчитать" << endl;
	cin >> SequenceNumber;
	if (SequenceNumber > 0)
	{
		for (Counter; Counter <= SequenceNumber; Counter = Counter + 1)
		{
			FactorialNumber = FactorialNumber * Counter;
			CurrentSum = (pow(-1, Counter)) / (FactorialNumber * (FactorialNumber * (Counter + 1))) + CurrentSum;
		}
	}
	else
	{
		if (SequenceNumber == 0)
		{
			CurrentSum = 1;
		}
		else
		{
			cout << "Номер конечного члена должен быть натуральным числом!";
		}
	}
	cout << "Кол-во членов последовательности - " << SequenceNumber << "\n" << "Их сумма - " << '(' << CurrentSum << ')' << endl;
	return 0;
}