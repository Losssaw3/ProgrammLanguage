#include <iostream>
#include <cmath>

using namespace std;
/***
* \brief Функция определяющая площадь грани куба
* \param Аргумент функции (ребро куба)
* \return Возвращает значение площади грани куба
*/
const double getFaceArea(const double cubeEdge);
/***
* \brief Функция определяющая объем куба
* \param Аргумент функции (ребро куба)
* \return Возвращает значение объема куба
*/
const double getCubeVolume(const double cubeEdge);
/***
* \brief Функция определяющая площадь полной поверхности куба
* \param Аргумент функции (ребро куба)
* \return Возвращает значение площади полной поверхности куба
*/
const double getFullFaceArea(const double cubeEdge);
/***
* \brief Вхождение в программу
* \return Возвращает 0 в случае успеха
*/
int main()
{
    setlocale(LC_ALL, "Rus");
    double cubeEdge = 0.0;
    cout << "Введите размер ребра куба" << endl;
    cin >> cubeEdge;
    const double faceArea = getFaceArea(cubeEdge);
    const double cubeVolume = getCubeVolume(cubeEdge);
    const double fullFaceArea = getFullFaceArea(cubeEdge);
    if (cubeEdge > 0)
    {
        cout << "Объем куба = " << cubeVolume << "\n" << "Площадь полной поверхности = " << fullFaceArea << "\n" << "Площадь грани = " << faceArea << endl;
    }
    else
    {
        cout << "Ребро куба должно являться положительным действительным числом!" << endl;
    }
    return 0;
}
const double getFaceArea(const double cubeEdge)
{
    return cubeEdge * cubeEdge;
}
const double getCubeVolume(const double cubeEdge)
{
    return (cubeEdge * cubeEdge * cubeEdge);
}
const double getFullFaceArea(const double cubeEdge)
{
    return (cubeEdge * cubeEdge * 6);
}
