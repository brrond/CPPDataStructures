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
		cout << "2) stack" << endl;
		cout << "3) Queue" << endl;
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
		else if (n == 2)
		{
			return main_lab2_stack();
		}
		else if(n == 3)
		{
			return main_lab2_queue();
	} while (true);
#else

	//main_lab1();
	//main_lab2_stack();
	main_lab2_queue();

#endif


	return 0;
}