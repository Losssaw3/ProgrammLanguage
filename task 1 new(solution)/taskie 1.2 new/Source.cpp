#include <iostream>
#include <cmath>

using namespace std;
/***
* \brief Функция определяющая площадь грани куба
* \param Аргумент функции (ребро куба)
* \return Возвращает значение площади грани куба
*/
double GetFaceArea(double CubeEdge);
/***
* \brief Функция определяющая объем куба
* \param Аргумент функции (ребро куба)
* \return Возвращает значение объема куба
*/
double GetCubeVolume(double CubeEdge);
/***
* \brief Функция определяющая площадь полной поверхности куба
* \param Аргумент функции (ребро куба)
* \return Возвращает значение площади полной поверхности куба
*/
double GetFullFaceArea(double CubeEdge);
/***
* \brief Вхождение в программу
* \return Возвращает 0 в случае успеха
*/
int main()
{
    setlocale(LC_ALL, "Rus");
    double CubeEdge = 0.0;
    cout << "Введите размер ребра куба" << endl;
    cin >> CubeEdge;
    const double FaceArea = GetFaceArea(CubeEdge);
    const double CubeVolume = GetCubeVolume(CubeEdge);
    const double FullFaceArea = GetFullFaceArea(CubeEdge);
    if (CubeEdge > 0)
    {
        cout << "Объем куба = " << CubeVolume << "\n" << "Площадь полной поверхности = " << FullFaceArea << "\n" << "Площадь грани = " << FaceArea << endl;
    }
    else
    {
        cout << "Ребро куба должно являться положительным действительным числом!" << endl;
    }
    return 0;
}
double GetFaceArea(double CubeEdge)
{
    return CubeEdge * CubeEdge;
}
double GetCubeVolume(double CubeEdge)
{
    return (CubeEdge * CubeEdge * CubeEdge);
}
double GetFullFaceArea(double CubeEdge)
{
    return (CubeEdge * CubeEdge * 6);
}
