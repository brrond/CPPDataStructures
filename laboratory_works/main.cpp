#include <iostream>
#include "dependencies.h"

using namespace std;

int main()
{

#if (MODE == 1)
	do
	{
		int n;
		cout << "1) List" << endl;
		cout << "2) Stack" << endl;
		cout << "3) Queue" << endl;
		cout << "4) Deque" << endl;
		cout << "5) Binary search tree" << endl;
		cout << "6) Red black tree" << endl;
		cout << "7) sorts 4th lab" << endl;
		cout << "8) search 5th lab" << endl;
		cout << "9) substr 5th lab" << endl;
		cout << "What lab do you want to test : ";

		try 
		{
			cin >> n;
		}
		catch(...)
		{ 
			cout << "Try again" << endl;
		}

		switch (n)
		{
		case 1: return main_lab1();
		case 2: return main_lab2_stack();
		case 3: return main_lab2_queue();
		case 4: return main_lab2_deque();
		case 5: return main_lab3_binary_search_tree();
		case 6: return main_lab3_red_black_tree();
		case 7: return main_lab4();
		case 8: return main_lab5_search();
		case 9: return main_lab5_substr();
		default:
			break;
		}

	} while (true);
#elif (MODE == 0)

	//main_lab1();
	//main_lab2_stack();
	//main_lab2_queue();
	//main_lab2_deque();
	//main_lab3_binary_search_tree();
	//main_lab3_red_black_tree();
	//main_lab4();
	//main_lab5_search();
	//main_lab5_substr();

#else
	do
	{
		int n;
		cout << "1) List" << endl;
		cout << "2) Stack" << endl;
		cout << "3) Queue" << endl;
		cout << "4) Deque" << endl;
		cout << "5) Binary search tree" << endl;
		cout << "6) Red black tree" << endl;
		cout << "7) sorts lab" << endl;
		cout << "8) search lab" << endl;
		cout << "9) substr" << endl;
		cout << "What lab do you want to test : ";

		try
		{
			string input;
			cin >> input;

			if (input == "cls")
			{
				system("cls");
				continue;
			}
			else if (input == "exit")
			{
				return 0;
			}

			n = stoi(input);
		}
		catch (...)
		{
			cout << "Try again" << endl;
			continue;
		}

		switch (n)
		{
		case 1: main_lab1(); break;
		case 2: main_lab2_stack(); break;
		case 3: main_lab2_queue(); break;
		case 4: main_lab2_deque(); break;
		case 5: main_lab3_binary_search_tree(); break;
		case 6: main_lab3_red_black_tree(); break;
		case 7: main_lab4(); break;
		case 8: main_lab5_search(); break;
		case 9: main_lab5_substr(); break;
		default:
			break;
		}

	} while (true);
#endif

	return 0;
}