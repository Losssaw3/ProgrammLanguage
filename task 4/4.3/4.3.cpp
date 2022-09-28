#include <iostream>
#include <ctime>
using namespace std;
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
*\brief Фукция выводящая на экран массив
*\param **arr - указатель на массив
*\param row - кол-во строк в массиве
*\param col - кол-во столбцов в массиве
*\return Возвращает массив
*/
void printArray(int** arr, int row, int  col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << '\n';
    }
}
/*
*\brief Фукция ,заменяющая минимальный по модулю элемент столбца массива нулем
*\param **arr - указатель на массив
*\param row - кол-во строк в массиве
*\param col - кол-во столбцов в массиве
*\return Возвращает измененный массив
*/
void changeArray(int** arr, int row, int col)
{
    int** arrChanged = new int* [row];
    for (int i = 0; i < row; i++)
        arrChanged[i] = new int[col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arrChanged[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < col; i++)
    {
        int mini = 10000000;
        for (int j = 0; j < row; j++)
        {
            if (abs(arrChanged[j][i]) < mini)
            {
                mini = abs(arrChanged[j][i]);
            }

        }
        for (int j = 0; j < row; j++)
        {
            if (abs(arrChanged[j][i]) == mini)
            {
                arrChanged[j][i] = 0;
            }
        }
    }
    printArray(arrChanged, row, col);
    for (int i = 0; i < row; i++)
    {
        delete[] arrChanged[i];
    }
    delete[] arrChanged;
}
/*
*\brief Фукция удаляющая в массиве столбцы, первый элемент которых больше последнего
*\param **arr - указатель на массив
*\param row - кол-во строк в массиве
*\param col - кол-во столбцов в массиве
*\return Возвращает массив с измененным кол-вом столбцов
*/
void newArray(int** arr, int row, int col)
{
    int counter = 0;
    for (int i = 0; i < col; i++)
    {
        if (arr[0][i] > arr[row - 1][i])
        {
            counter += 1;
        }
    }
    int** arrNum = new int* [row];
    for (int i = 0; i < row; i++)
    {
        arrNum[i] = new int[col - counter];
    }
    int* arrCheck = new int[abs(col - counter)];
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
                cout << arrNum[i][j] << '\t';
            }
            cout << '\n';
        }
    }
    else
    {
        if (counter == 0)
        {
            cout << "Все столбцы массивы были удалены" << endl;
        }
    }
    delete[] arrCheck;
    for (int i = 0; i < counter; i++)
    {
        delete[] arrNum[i];
    }
    delete[] arrNum;
}
/*
*\brief Точка входа в программу
*\return возвращает 0 в случае успеха
*/
int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int row;
    int col;
    const int limit = 100;
    cout << "Введите кол-во строк массива" << endl;
    cin >> row;
    cout << "Введите кол-во рядов массива" << endl;
    cin >> col;
    int** arr = new int* [row];
    for (int i = 0; i < row; i++)
        arr[i] = new int[col];
    cout << "Как следует заполнить массив?" << "\n" << static_cast<int>(fillArray::random) << '\t' << "Случайно" << "\n" << static_cast <int>(fillArray::userInput) << '\t' << "Пользовательский ввод" << endl;
    int input = 0;
    cin >> input;
    const auto choice = static_cast<fillArray>(input);
    switch (choice)
    {
    case(fillArray::random):
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int sigh = rand() % 2;
                if (sigh == 0)
                {
                    arr[i][j] = rand() % limit;
                }
                else
                {
                    arr[i][j] = -1 * rand() % limit;
                }
            }
        }
        break;
    }
    case(fillArray::userInput):
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int x = 0;
                cin >> x;
                arr[i][j] = x;
            }
        }
        break;
    }
    default:
    {
        cout << "Нет такой операции заполнения" << endl;
    }
        break;
    }
    cout << "Начальный массив" << '\n';
    printArray(arr, row, col);
    cout << "Массив с измененными минимальными элементами" << endl;
    changeArray(arr, row, col);
    cout << "Массив с удаленными столбцами" << endl;
    newArray(arr, row, col);
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}