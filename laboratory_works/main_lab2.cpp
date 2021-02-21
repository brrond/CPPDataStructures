#include "dependencies.h"

using namespace std;

int main_lab2()
{
	stack<int> a;
	for (int i = 0; i < 100; i++)
	{
		a.push_back(i);
	}

	for (int i = 0; i < 100; i++)
	{
		cout << a.back() << " ";
		a.pop();
	}

	return 0;
}