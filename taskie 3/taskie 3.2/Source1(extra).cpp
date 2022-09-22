#include <iostream>
using namespace std;
int main()
{
	double x;
	double maxi = -1000000;
	int n;
	cin >> n;
	int i = 1;
	for (i; i <= n; i++)
	{
		cin >> x;
		if (x > maxi)
		{
			maxi = x;
		}

	}
	cout << maxi;
	return 0;
}