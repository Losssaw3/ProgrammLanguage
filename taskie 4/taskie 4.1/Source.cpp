#include <iostream>
#include <ctime>
using namespace std;
enum class fillArray
{
	random,
	userInput
};
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	int size;
	int x = 0;
	cin >> size;
	int *arr = new int[size];
	cout << "operasia" << '\n'
		<< static_cast <int>(fillArray::userInput) <<'\t' << "cam" <<'\n'
		<< static_cast <int>(fillArray::random)<<'\t'<< "random" << endl;
	int input = 0;
	cin >> input;
	const auto choice = static_cast<fillArray>(input);
	switch (choice)
	{
	default:
		{
			cout << "no var" << endl;
		}
		break;
	case fillArray::userInput: 
		{
			for (int i = 0; i < size; i++)
			{
				cin >> x;
				arr[i] = x;
			}
			break;
		}
	case fillArray::random:
		{
			for (int i = 0; i < size; i++)
				{
					arr[i] = rand() % 100;
				}
			break;
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
	delete[]arr;
	return 0;
}

