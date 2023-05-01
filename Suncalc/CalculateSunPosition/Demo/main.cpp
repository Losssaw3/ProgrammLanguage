#include "..//SunPosition/SunPosition.h"

int main()
{
	setlocale(LC_ALL, "ru");
	SUN::SunPosition fisrt(55.0, 37.0);
	std::cout << fisrt;
}