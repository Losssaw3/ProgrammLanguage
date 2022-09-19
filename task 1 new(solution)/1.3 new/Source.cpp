#include <iostream>
using namespace std;
/**
* \brief Функция определяющая вес тела
* \param Первый аргумент - масса тела
* \param Второй агрумент - ускорение свободного падения
* \return Возвращает значение веса тела
*/
double GetWeight(double Mass, double GravityAcceleration);
/**
* \brief Функция определяющая силу тяжести
* \param Первый аргумент - масса тела
* \param Второй агрумент - ускорение свободного падения
* \return Возвращает значение силы тяжести
*/
double GetGravityForse(double Mass, double GravityAcceleration);
/**
* \brief Точка входа в программу 
* \return 0 в случае успеха
*/
int main()
{
	setlocale(LC_ALL, "Rus");
	double GravityAcceleration = 9.8;
	double Mass = 0.0;
	cout << "Введите массу тела" << endl;
	cin >> Mass;
	if (Mass < 0)
	{
		cout << "Недопустимое значение массы" << endl;
		return 1;
	}
	double Weight = GetWeight(Mass, GravityAcceleration);
	double GravityForse = GetGravityForse(Mass, GravityAcceleration);
	cout << "Сила тяжести = " << GravityForse << '\n' << "Вес тела = " << Weight << endl;
	return 0;
}
double GetWeight(double Mass, double GravityAcceleration)
{
	return (Mass * GravityAcceleration);
}
double GetGravityForse(double Mass, double GravityAcceleration)
{
	return (Mass * GravityAcceleration);
}
