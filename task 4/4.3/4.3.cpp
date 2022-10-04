#include <iostream>

#include <ctime>

#include <random>//new array delete mass
using namespace std;
/*
*\brief Функция считывающая размеры массива
*\param message Побуждающее сообщение (подсказка для пользователя)
*\return Возвращает размеры массива
*/
size_t getSize(const string& message);
/*
*\brief Выбор типа заполнения массива
*\param random - Случайное заполнение
*\param userInput - Пользовательский ввод
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
*/
void deleteArray(int**& arr, const size_t row);
/*
*\brief Фукция создающая двухмерный массив 
*\param row - кол-во строк в массиве
*\return Возвращает указатель на массив
*/
int** createArray(const size_t row, const size_t col);
/*
*\brief Фукция выводящая на экран массив
*\param **arr - указатель на массив
*\param row - кол-во строк в массиве
*\param col - кол-во столбцов в массиве
*/
void printArray(int** arr, const size_t row, const size_t  col);
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
*\param row - кол-во строк в массиве
*\param col - кол-во столбцов в массиве
*\param minValue нижняя граница рандома
*\param maxValue верхняя граница рандома
*\return Возвращает указатель на заполненный массив
*/
int** fillRandomArray(const size_t row, const size_t col, const int minValue, const int maxValue);
/*
*\brief Функция создающая массив с номерами столбцов, в которых первый элемент меньше последнего
*\param **arr указатель на массив , столбцы которого необходимо анализировать
*\param row - кол-во строк в массиве
*\param col - кол-во столбцов в массиве
*\return Возвращает указатель на массив с номерами столбцов, в которых первый элемент меньше последнего
*/
int* colNumbers(int** arr, const size_t row, const size_t col);
/*
*\brief Фукция заполняющая массив пользовательским вводом
*\param row - кол-во строк в массиве
*\param col - кол-во столбцов в массиве
*\return Возвращает указатель на заполненный массив
*/
int** fillManualArray(const size_t row, const size_t col);
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
*\param **arrChanged указатель на массив, минимальные элементы которого будут заменены
*\param row - кол-во строк в массиве
*\param col - кол-во столбцов в массиве
*/
void changeArray(int** arr, int** arrChanged, const size_t row, const size_t col);
/*
*\brief Фукция удаляющая в массиве столбцы, первый элемент которых больше последнего
*\param **arr - указатель на массив
*\param **arrNew указатель на массив с удаленными столбцами
*\param row - кол-во строк в массиве
*\param col - кол-во столбцов в массиве
*/
void newArray(int** arr, int** arrNew, const size_t row, const size_t col);//doc
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
    int** arr = createArray(row, col);
    cout << "Как следует заполнить массив?" << "\n" << static_cast<int>(fillArray::random) << '\t' << "Случайно" << "\n" << static_cast <int>(fillArray::userInput) << '\t' << "Пользовательский ввод" << endl;
    int input = 0;
    cin >> input;
    const auto choice = static_cast<fillArray>(input);
    switch (choice)
    {
    case(fillArray::random):
    {
        arr = fillRandomArray(row, col, minValue, maxValue);
        break;
    }
    case(fillArray::userInput):
    {
        arr = fillManualArray(row, col);
        break;
    }
    default:
    {
        cout << "Нет такой операции заполнения" << endl;
    }
        break;
    }
    //Пункт 1
    int** arrChanged = createArray(row, col);
    changeArray(arr, arrChanged, row, col);
    //Пункт 2
    int counter = searchForCounter(arr, row, col);
    int** arrNum = createArray(row, col - counter);
    if (col - counter > 0)
    {
        newArray(arr, arrNum, row, col);
    }
    else
    {
        cout << "Все столбца были удалены, новый массив пуст!" << endl;
    }
    //Вывод
    cout << "Начальный массив" << endl;
    printArray(arr, row, col);
    cout << "Массив с измененными минимальными элементами" << endl;
    printArray(arrChanged, row, col);
    cout << "Массив с удаленными столбцами" << endl;
    printArray(arrNum, row, col-counter);
    //Удаление
    deleteArray(arr, row);
    deleteArray(arrChanged, row);
    deleteArray(arrNum, row);
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
void deleteArray(int**& arr, const size_t row)
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
int** createArray(const size_t row, const size_t col)
{
    int** arr = new int* [row];
    for (size_t i = 0; i < row; i++)
        arr[i] = new int[col];
    return arr;
}
void printArray(int** arr, const size_t row, const size_t  col)
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
    if (row > 0)
    {
        for (size_t i = 0; i < col; i++)
        {
            if (arr[0][i] > arr[row - 1][i])
            {
                counter += 1;
            }
        }
        return counter;
    }  
}
int** fillRandomArray(const size_t row, const size_t col, const int minValue, const int maxValue)
{
    int** arr = createArray(row, col);
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
    return arr;
}
int** fillManualArray(const size_t row, const size_t col)
{
    int** arr = createArray(row, col);
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }
    return arr;
}
int* colNumbers(int** arr, const size_t row, const size_t col)
{
    int counter = searchForCounter(arr, row, col);
    int* arrCheck = new int[(col - counter)];
    counter = 0;
    if (row > 0)
    {
        for (size_t i = 0; i < col; i++)
        {
            if (arr[0][i] <= arr[row - 1][i])
            {
                counter += 1;
                arrCheck[counter - 1] = i;
            }
        }
    }
    return arrCheck;
    if (arrCheck != nullptr)
    {
        delete[] arrCheck;
        arrCheck = nullptr;
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
void changeArray(int** arr,int** arrChanged, const size_t row, const size_t col)
{
    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            if (std::abs(arr[j][i]) == searchForMini(arr, row, col, i))
            {
                arrChanged[j][i] = 0;
            }
            else
            {
                arrChanged[j][i] = arr[j][i];
            }
        }
    }   
}
void newArray(int** arr,int** arrNew, const size_t row, const size_t col)
{
    int counter = searchForCounter(arr, row, col);
    int* arrCheck = colNumbers(arr, row, col);
    for (size_t i = 0; i < row; i++)
    {
       for (size_t j = 0; j < col - counter; j++)
       {
            arrNew[i][j] = arr[i][arrCheck[j]];
       }
    }
}