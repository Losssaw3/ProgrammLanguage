#include <iostream>
using namespace std;
/**
* \brief Функция определяющая вес тела
* \param Первый аргумент - масса тела
* \param Второй агрумент - ускорение свободного падения
* \return Возвращает значение веса тела
*/
const double getWeight(const double mass,const double GRAVITYACCELERATION);
/**
* \brief Функция определяющая силу тяжести
* \param Первый аргумент - масса тела
* \param Второй агрумент - ускорение свободного падения
* \return Возвращает значение силы тяжести
*/
const double getGravityForse(const double mass,const double GRAVITYACCELERATION);
/**
* \brief Точка входа в программу 
* \return 0 в случае успеха
*/
int main()
{
	setlocale(LC_ALL, "Rus");
	const double GRAVITYACCELERATION = 9.8;
	double mass = 0.0;
	cout << "Введите массу тела" << endl;
	cin >> mass;
	if (mass < 0)
	{
		cout << "Недопустимое значение массы" << endl;
		return 1;
	}
	const double weight = getWeight(mass, GRAVITYACCELERATION);
	const double gravityForse = getGravityForse(mass, GRAVITYACCELERATION);
	cout << "Сила тяжести = " << gravityForse << '\n' << "Вес тела = " << weight << endl;
	return 0;
}
const double getWeight(const double mass, const double GRAVITYACCELERATION)
{
	return (mass * GRAVITYACCELERATION);
}
const double getGravityForse(const double mass, const double GRAVITYACCELERATION)
{
	return (mass * GRAVITYACCELERATION);
}
