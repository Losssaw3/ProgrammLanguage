#include <iostream>
#include <ctime>
#include <random>
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
enum class fillarray
{
	random,
	userInput
};

/*
*\brief Фукция удаляющая массив
*\param array - указатель на массив
*\param row - кол-во строк в массиве
*/
void deleteArray(int**& array, const size_t row);

/*
*\brief Фукция создающая двухмерный массив 
*\param row - кол-во строк в массиве
*\return Возвращает указатель на массив
*/
int** createArray(const size_t row, const size_t column);

/*
*\brief Фукция выводящая на экран массив
*\param array - указатель на массив
*\param row - кол-во строк в массиве
*\param column - кол-во столбцов в массиве
*/
void printArray(int** array, const size_t row, const size_t  column);

/*
*\brief Фукция которая ищет кол-во столбцов , в которых первый элемент больше последнего
*\param array - указатель на массив
*\param row - кол-во строк в массиве
*\param column - кол-во столбцов в массиве
*\return Возвращает кол-во столбцов , в которых первый элемент больше последнего
*/
int searchForCounter(int** array, const size_t row, const size_t column);

/*
*\brief Фукция которая заполняет массив случайными элементами
*\param row - кол-во строк в массиве
*\param column - кол-во столбцов в массиве
*\param minValue нижняя граница рандома
*\param maxValue верхняя граница рандома
*\return Возвращает указатель на заполненный массив
*/
int** fillRandomArray(const size_t row, const size_t column, const int minValue, const int maxValue);

/*
*\brief Функция создающая массив с номерами столбцов, в которых первый элемент меньше последнего
*\param **array указатель на массив , столбцы которого необходимо анализировать
*\param row - кол-во строк в массиве
*\param column - кол-во столбцов в массиве
*\return Возвращает указатель на массив с номерами столбцов, в которых первый элемент меньше последнего
*/
int* columnNumbers(int** array, const size_t row, const size_t column);

/*
*\brief Фукция заполняющая массив пользовательским вводом
*\param row - кол-во строк в массиве
*\param column - кол-во столбцов в массиве
*\return Возвращает указатель на заполненный массив
*/
int** fillManualArray(const size_t row, const size_t column);

/*
*\brief Фукция которая ищет минимальный по модулю элемент столбца
*\param row - кол-во строк в массиве
*\param column - кол-во столбцов в массиве
*\param i - номер строки, в котоой следует искать минимум
*\return Возвращает минимальный по модулю элемент столбца
*/
int searchForMini(int** array, const size_t row, const size_t column, size_t i);

/*
*\brief Фукция ,заменяющая минимальный по модулю элемент столбца массива нулем
*\param array - указатель на массив
*\param arrayChanged указатель на массив, минимальные элементы которого будут заменены
*\param row - кол-во строк в массиве
*\param column - кол-во столбцов в массиве
*/
void changeArray(int** array, int** arrayChanged, const size_t row, const size_t column);

/*
*\brief Фукция удаляющая в массиве столбцы, первый элемент которых больше последнего
*\param array - указатель на массив
*\param arrayNew указатель на массив с удаленными столбцами
*\param row - кол-во строк в массиве
*\param column - кол-во столбцов в массиве
*/
void newArray(int** array, int** arrayNew, const size_t row, const size_t column);//doc

/*
*\brief Точка входа в программу
*\return возвращает 0 в случае успеха
*/
int main()
{
    setlocale(LC_ALL, "Rus");
    const int minValue = -100;
    const int maxValue = 100;
    int row, column;
    row = getSize("Bведите кол-во строк\n");
    column = getSize ("Введите кол-во рядов массива\n");
    int** array = createArray(row, column);

    cout << "Как следует заполнить массив?" << "\n" << static_cast<int>(fillarray::random) << '\t' << "Случайно" << "\n" << static_cast <int>(fillarray::userInput) << '\t' << "Пользовательский ввод" << endl;
    int input = 0;
    cin >> input;
    const auto choice = static_cast<fillarray>(input);
    switch (choice)
    {
    case(fillarray::random):
    {
        array = fillRandomArray(row, column, minValue, maxValue);
        break;
    }
    case(fillarray::userInput):
    {
        array = fillManualArray(row, column);
        break;
    }
    default:
    {
        cout << "Нет такой операции заполнения" << endl;
    }
        break;
    }
    //Пункт 1
    int** arrayChanged = createArray(row, column);
    changeArray(array, arrayChanged, row, column);
    //Пункт 2
    int counter = searchForCounter(array, row, column);
    int** arrayNum = createArray(row, column - counter);
    if (column - counter > 0)
    {
        newArray(array, arrayNum, row, column);
    }
    else
    {
        cout << "Все столбца были удалены, новый массив пуст!" << endl;
    }
    //Вывод
    cout << "Начальный массив" << endl;
    printArray(array, row, column);
    cout << "Массив с измененными минимальными элементами" << endl;
    printArray(arrayChanged, row, column);
    cout << "Массив с удаленными столбцами" << endl;
    printArray(arrayNum, row, column-counter);
    //Удаление
    deleteArray(array, row);
    deleteArray(arrayChanged, row);
    deleteArray(arrayNum, row);
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

void deleteArray(int**& array, const size_t row)
{
    if (array != nullptr)
    {
        for (size_t i = 0; i < row; i++)
        {
            delete[] array[i];
        }
        delete[] array;
        array = nullptr;
    }
}

int** createArray(const size_t row, const size_t column)
{
    int** array = new int* [row];
    for (size_t i = 0; i < row; i++)
        array[i] = new int[column];
    return array;
}

void printArray(int** array, const size_t row, const size_t  column)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            cout << array[i][j] << '\t';
        }
        cout << '\n';
    }
}

int searchForCounter(int** array, const size_t row, const size_t column)
{
    int counter = 0;
    if (row > 0)
    {
        for (size_t i = 0; i < column; i++)
        {
            if (array[0][i] > array[row - 1][i])
            {
                counter += 1;
            }
        }
        return counter;
    }  
}

int** fillRandomArray(const size_t row, const size_t column, const int minValue, const int maxValue)
{
    int** array = createArray(row, column);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> uniformIntDistribution(minValue, maxValue);
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            array[i][j] = uniformIntDistribution(gen);
        }
    }
    return array;
}

int** fillManualArray(const size_t row, const size_t column)
{
    int** array = createArray(row, column);
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            int x;
            cin >> x;
            array[i][j] = x;
        }
    }
    return array;
}

int* columnNumbers(int** array, const size_t row, const size_t column)
{
    int counter = searchForCounter(array, row, column);
    int* arrayCheck = new int[(column - counter)];
    counter = 0;
    if (row > 0)
    {
        for (size_t i = 0; i < column; i++)
        {
            if (array[0][i] <= array[row - 1][i])
            {
                counter += 1;
                arrayCheck[counter - 1] = i;
            }
        }
    }
    return arrayCheck;
}

int searchForMini(int** array, const size_t row, const size_t column, size_t i)
{
    int mini = std::abs(array[0][i]);
    for (size_t j = 0; j < row; j++)
    {
        if (std::abs(array[j][i]) < mini)
        {
            mini = std::abs(array[j][i]);
        }
    }
    return mini;
}

void changeArray(int** array,int** arrayChanged, const size_t row, const size_t column)
{
    for (size_t i = 0; i < column; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            if (std::abs(array[j][i]) == searchForMini(array, row, column, i))
            {
                arrayChanged[j][i] = 0;
            }
            else
            {
                arrayChanged[j][i] = array[j][i];
            }
        }
    }   
}

void newArray(int** array,int** arrayNew, const size_t row, const size_t column)
{
    int counter = searchForCounter(array, row, column);
    int* arrayCheck = columnNumbers(array, row, column);
    for (size_t i = 0; i < row; i++)
    {
       for (size_t j = 0; j < column - counter; j++)
       {
            arrayNew[i][j] = array[i][arrayCheck[j]];
       }
    }
}