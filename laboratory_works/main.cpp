#include <iostream>
#include "dependencies.h"

using namespace std;

int main()
{

#ifndef DEBUG
	do
	{
		int n;
		cout << "1) List" << endl;
		cout << "What lab do you want to test : ";
		try 
		{
			cin >> n;
		}
		catch(...)
		{ 
			cout << "Try again" << endl;
		}

		if (n == 1)
		{
			return main_lab1();
		}

	} while (true);
#else

	main_lab2();

#endif


	return 0;
}