#include <iostream>
#include <ctime>
using namespace std;
/*
*\brief ������� ��� ������ ���� ���������� �������
*\param random - ��������� ����������
*\param userInput - ���������������� ����
*\return ������ ���������� �������
*/
enum class fillArray
{
	random,
	userInput
};
/*
*\brief ������ ��������� �� ����� ������
*\param **arr - ��������� �� ������
*\param row - ���-�� ����� � �������
*\param col - ���-�� �������� � �������
*\return ���������� ������
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
*\brief ������ ,���������� ����������� �� ������ ������� ������� ������� �����
*\param **arr - ��������� �� ������
*\param row - ���-�� ����� � �������
*\param col - ���-�� �������� � �������
*\return ���������� ���������� ������
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
*\brief ������ ��������� � ������� �������, ������ ������� ������� ������ ����������
*\param **arr - ��������� �� ������
*\param row - ���-�� ����� � �������
*\param col - ���-�� �������� � �������
*\return ���������� ������ � ���������� ���-��� ��������
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
            cout << "��� ������� ������� ���� �������" << endl;
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
*\brief ����� ����� � ���������
*\return ���������� 0 � ������ ������
*/
int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int row, col,limit;
    limit = 100;
    cout << "������� ���-�� ����� �������" << endl;
    cin >> row;
    cout << "������� ���-�� ����� �������" << endl;
    cin >> col;
    int** arr = new int* [row];
    for (int i = 0; i < row; i++)
        arr[i] = new int[col];
    cout << "��� ������� ��������� ������?" << "\n" << static_cast<int>(fillArray::random) << '\t' << "��������" << "\n" << static_cast <int>(fillArray::userInput) << '\t' << "���������������� ����" << endl;
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
        cout << "��� ����� �������� ����������" << endl;
    }
        break;
    }
    cout << "��������� ������" << '\n';
    printArray(arr, row, col);
    cout << "������ � ����������� ������������ ����������" << endl;
    changeArray(arr, row, col);
    cout << "������ � ���������� ���������" << endl;
    newArray(arr, row, col);
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}