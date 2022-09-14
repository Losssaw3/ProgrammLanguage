#include <iostream>
#include <cmath>

using namespace std;
double GetFaceArea(double CubeEdge);
double GetCubeVolume(double CubeEdge);
double GetFullFaceArea(double CubeEdge);
int main()
{
    setlocale(LC_ALL, "Rus");
    double CubeEdge{};
    cout << "Введите размер ребра куба" << endl;
    cin >> CubeEdge;
    const double FaceArea = GetFaceArea(CubeEdge);
    const double CubeVolume = GetCubeVolume(CubeEdge);
    const double FullFaceArea = GetFullFaceArea(CubeEdge);
    cout << "Объем куба = " << CubeVolume << "\n" << "Площадь полной поверхности = " << FullFaceArea << "\n" << "Площадь грани = " << FaceArea << endl;
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