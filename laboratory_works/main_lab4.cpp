#include "dependencies.h"

using namespace std;

#define SIZE_OF_ARRAY 1000

int main_lab4()
{
	auto print_array = [](vector<int>& arr) {
		for_each(arr.begin(), arr.end(), [](int n) {cout << n << " "; });
		cout << endl;
	};
	cout << boolalpha;
	
	int tmp = 0;
	vector<int> arr(SIZE_OF_ARRAY);
	generate(arr.begin(), arr.end(), []() {return rand() % 100 - 50; });

	do
	{
		cout << "1) Create array" << endl;
		cout << "2) Print array" << endl;
		cout << "3) Insertion sort" << endl;
		cout << "4) Shell sort" << endl;
		cout << "5) Selection sort" << endl;
		cout << "0) Random current array" << endl;
		cout << ">>>";

		string input;
		int menu;

		try
		{
			cin >> input;
			if (input == "exit")
				return 0;
			
			menu = stoi(input);
		}
		catch (...)
		{
			cout << "Try again" << endl;
			continue;
		}

		if (menu == 1)
		{
			int n = 0;
			do
			{
				cout << "How many elements : ";
				try
				{
					cin >> input;
					n = stoi(input);
				}
				catch (...)
				{
					cout << "Try again" << endl;
					n = 0;
				}
			} while (!n);

			arr.resize(n);

			do
			{
				cout << "What order of elements do you want ?" << endl;
				cout << "0) Random" << endl;
				cout << "1) Ascending" << endl;
				cout << "2) Descending" << endl;

				try
				{
					cin >> input;
					menu = stoi(input);
				}
				catch (...)
				{
					cout << "Try again" << endl;
				}

				break;
			} while (true);

			switch (menu)
			{
			case 1:
				tmp = 0;
				generate(arr.begin(), arr.end(), [&tmp]() {return tmp++; });
				break;
			case 2:
				tmp = 0;
				generate(arr.begin(), arr.end(), [&tmp]() {return tmp++; });
				reverse(arr.begin(), arr.end());
				break;
			default:
				generate(arr.begin(), arr.end(), []() {return rand() % 100 - 50; });
				break;
			}
			
		}
		else if (menu == 2)
		{
			system("cls");
			cout << "Array is : ";
			print_array(arr);
			cout << "Is sorted func : " << is_sorted(arr.begin(), arr.end()) << endl;
			system("pause");
			system("cls");
		}
		else if (menu == 3)
		{
			insertion_sort(arr.begin(), arr.end());
		}
		else if (menu == 4)
		{
			shell_sort(arr.begin(), arr.end());
		}
		else if (menu == 5)
		{
			selection_sort(arr.begin(), arr.end());
		}
		else if (menu == 0)
		{
			random_shuffle(arr.begin(), arr.end());
		}

		cout << "Done" << endl;
	} while (true);//*/

	return 0;
}