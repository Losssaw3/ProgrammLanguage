#include <iostream>
#include <ctime>
#include <random>//new array delete mass
using namespace std;
size_t getSize(const string& message);
/*
*\brief Функция для выбора вида заполнения массива
*\param random - Случайное заполнение
*\param userInput - Пользовательский ввод
*\return Способ заполнения массива
*/
enum class fillArray
{
	random,
	userInput
};
/*
*\brief Фукция удаляющая массив
*\param **arr - указатель на массив
*\param row - кол-во строк в массиве
*\return удаляет массив
*/
const void deleteArray(int**& arr, const size_t row);
/*
*\brief Фукция создающая двухмерный массив 
*\param **arr - указатель на массив
*\param row - кол-во строк в массиве
*\param col - кол-во столбцов в массиве
*\return Возвращает двухмерный массив
*/
const void createArray(int** arr, const size_t row, const size_t col);
/*
*\brief Фукция выводящая на экран массив
*\param **arr - указатель на массив
*\param row - кол-во строк в массиве
*\param col - кол-во столбцов в массиве
*\return Возвращает массив
*/
const void printArray(int** arr, const size_t row, const size_t  col);
/*
*\brief Фукция которая ищет кол-во столбцов , в которых первый элемент больше последнего
*\param **arr - указатель на массив
*\param row - кол-во строк в массиве
*\param col - кол-во столбцов в массиве
*\return Возвращает кол-во столбцов , в которых первый элемент больше последнего
*/
int searchForCounter(int** arr, const size_t row, const size_t col);
/*
*\brief Фукция которая заполняет массив случайными элементами
*\param **arr - указатель на массив
*\param row - кол-во строк в массиве
*\param col - кол-во столбцов в массиве
*\param minValue нижняя граница рандома
*\param maxValue верхняя граница рандома
*\return Возвращает массив , заполненный случайными элементами
*/
const void FillRandomArray(int** arr, const size_t row, const size_t col, const int minValue, const int maxValue);
/*
*\brief Фукция заполняющая массив пользовательским вводом
*\param **arr - указатель на массив
*\param row - кол-во строк в массиве
*\param col - кол-во столбцов в массиве
*\return Возвращает массив , заполненный пользователем
*/
const void fillManualArray(int** arr, const size_t row, const size_t col);
/*
*\brief Фукция копирующая массив
*\param **arrOrigin - массив который будет скопирован
*\param **arrCopy - новый, скопированный массив
*\param row - кол-во строк в массиве
*\param col - кол-во столбцов в массиве
*\return Возвращает новый масссив , совпадающий со старым
*/
const void copyArray(int** arrOrigin, int** arrCopy, const size_t row, const size_t col);
/*
*\brief Фукция которая ищет минимальный по модулю элемент столбца
*\param row - кол-во строк в массиве
*\param col - кол-во столбцов в массиве
*\param i - номер строки, в котоой следует искать минимум
*\return Возвращает минимальный по модулю элемент столбца
*/
int searchForMini(int** arr, const size_t row, const size_t col, size_t i);
/*
*\brief Фукция ,заменяющая минимальный по модулю элемент столбца массива нулем
*\param **arr - указатель на массив
*\param row - кол-во строк в массиве
*\param col - кол-во столбцов в массиве
*\return Возвращает измененный массив
*/
const void changeArray(int** arr, const size_t row, const size_t col);
/*
*\brief Фукция удаляющая в массиве столбцы, первый элемент которых больше последнего
*\param **arr - указатель на массив
*\param row - кол-во строк в массиве
*\param col - кол-во столбцов в массиве
*\return Возвращает массив с измененным кол-вом столбцов
*/
const void newArray(int** arr, const size_t row, const size_t col);
/*
*\brief Точка входа в программу
*\return возвращает 0 в случае успеха
*/
int main()
{
    setlocale(LC_ALL, "Rus");
    int row,col;
    const int minValue = -100;
    const int maxValue = 100;
    row = getSize("Bведите кол-во строк\n");
    col = getSize ("Введите кол-во рядов массива\n");
    int** arr = new int* [row];
    createArray(arr, row, col);
    cout << "Как следует заполнить массив?" << "\n" << static_cast<int>(fillArray::random) << '\t' << "Случайно" << "\n" << static_cast <int>(fillArray::userInput) << '\t' << "Пользовательский ввод" << endl;
    int input = 0;
    cin >> input;
    const auto choice = static_cast<fillArray>(input);
    switch (choice)
    {
    case(fillArray::random):
    {
        FillRandomArray(arr, row, col,minValue,maxValue);
        break;
    }
    case(fillArray::userInput):
    {
        fillManualArray(arr, row, col);
        break;
    }
    default:
    {
        cout << "Нет такой операции заполнения" << endl;
    }
        break;
    }
    cout << "Начальный массив" << endl;
    printArray(arr, row, col);
    cout << "Массив с измененными минимальными элементами" << endl;
    changeArray(arr, row, col);
    cout << "Массив с удаленными столбцами" << endl;
    newArray(arr, row, col);
    deleteArray(arr, row);
    return 0;
}
size_t getSize(const string& message)
{
    int size = -1;
    cout << message;
    cin >> size;
    if (size < 0)
    {
        throw out_of_range("Incorrect size. Value has to be greater or equal zero.");
    }
    return size;
}
const void deleteArray(int**& arr, const size_t row)
{
    if (arr != nullptr)
    {
        for (size_t i = 0; i < row; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        arr = nullptr;
    }
}
const void createArray(int** arr, const size_t row, const size_t col)
{
    for (size_t i = 0; i < row; i++)
        arr[i] = new int[col];
}
const void printArray(int** arr, const size_t row, const size_t  col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << '\n';
    }
}
int searchForCounter(int** arr, const size_t row, const size_t col)
{
    int counter = 0;
    for (size_t i = 0; i < col; i++)
    {
        if (arr[0][i] > arr[row - 1][i])
        {
            counter += 1;
        }
    }
    return counter;
}
const void FillRandomArray(int** arr, const size_t row, const size_t col, const int minValue, const int maxValue)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> uniformIntDistribution(minValue, maxValue);
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arr[i][j] = uniformIntDistribution(gen);
        }
    }
}
const void fillManualArray(int** arr, const size_t row, const size_t col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }
}
const void copyArray(int** arrOrigin, int** arrCopy, const size_t row, const size_t col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arrCopy[i][j] = arrOrigin[i][j];
        }
    }
}
int searchForMini(int** arr, const size_t row, const size_t col, size_t i)
{
    int mini = std::abs(arr[0][i]);
    for (size_t j = 0; j < row; j++)
    {
        if (std::abs(arr[j][i]) < mini)
        {
            mini = std::abs(arr[j][i]);
        }
    }
    return mini;
}
const void changeArray(int** arr, const size_t row, const size_t col)
{
    int** arrChanged = new int* [row];
    createArray(arrChanged, row, col);
    copyArray(arr, arrChanged, row, col);
    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            if (abs(arr[j][i]) == searchForMini(arr, row, col, i))
            {
                arrChanged[j][i] = 0;
            }
        }
    }
    printArray(arrChanged, row, col);
    deleteArray(arrChanged, row);
}
const void newArray(int** arr, const size_t row, const size_t col)
{
    int counter = searchForCounter(arr, row, col);
    int** arrNum = new int* [row];
    createArray(arrNum, row, col - counter);
    int* arrCheck = new int[(col - counter)];
    counter = 0;
    for (int i = 0; i < col; i++)
    {
        if (arr[0][i] <= arr[row - 1][i])
        {
            counter += 1;
            arrCheck[counter - 1] = i;
        }
    }
    if (counter != 0)
    {
        for (int i = 0; i < row; i++)
        {

            for (int j = 0; j < counter; j++)
            {
                arrNum[i][j] = arr[i][arrCheck[j]];
            }
        }
        printArray(arrNum, row, counter);
    }
    else
    {
        if (counter == 0)
        {
            cout << "Все столбцы массивы были удалены" << endl;
        }
    }
    if (arrCheck != nullptr)
    {
        delete[] arrCheck;
        arrCheck = nullptr;
    }
    deleteArray(arrNum, row);
}