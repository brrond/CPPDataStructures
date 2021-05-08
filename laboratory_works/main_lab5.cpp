#include "dependencies.h"

using namespace std;

#define SIZE_OF_ARRAY 20

int main_lab5_search()
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
		cout << "3) Get array from file" << endl;
		cout << "4) Save array to file" << endl;
		cout << "5) Enter from keyboard" << endl;
		cout << "6) Linear search" << endl;
		cout << "7) Linear search with bar" << endl;
		cout << "8) Binary search" << endl;

		string input;
		int menu;

		cout << ">>>";

		try
		{
			cin >> input;
			if (input == "exit")
				return 0;
			else if (input == "cls" || input == "clear")
			{
				system("cls");
				continue;
			}

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
			//system("cls");
			cout << "Array is : ";
			print_array(arr);
			cout << "Is sorted func : " << is_sorted(arr.begin(), arr.end()) << endl;
			//system("pause");
			//system("cls");
		}
		else if (menu == 3)
		{
			arr.clear();
			ifstream fin;
			fin.open("array_file.txt");
			while (!fin.eof())
			{
				fin >> tmp;
				arr.push_back(tmp);
			}
			fin.close();
		}
		else if (menu == 4)
		{
			ofstream fout;
			fout.open("array_file.txt");
			for (int n : arr)
			{
				fout << n << " ";
			}
			fout.close();
		}
		else if (menu == 5)
		{
			arr.clear();
			bool error = false;
			cout << "Enter elements : ";
			getline(cin, input);
			getline(cin, input);
			string tmp = "";
			for (char ch : input)
			{
				if (ch == ' ')
				{
					try
					{
						arr.push_back(stoi(tmp));
					}
					catch (...)
					{
						error = true;
					}
					tmp = "";
					continue;
				}
				else if (ch == '\n')
				{
					try
					{
						arr.push_back(stoi(tmp));
					}
					catch (...)
					{
						error = true;
					}
					tmp = "";
					break;
				}
				tmp += ch;
			}

			if (tmp != "")
			{
				try
				{
					arr.push_back(stoi(tmp));
				}
				catch (...)
				{
					error = true;
				}
			}

			if (error)
			{
				cout << "Done, but error happened" << endl;
				continue;
			}
		}
		else if (menu == 6)
		{
			int n = 0;
			do
			{
				cout << "What element do you want to find : ";
				try
				{
					cin >> input;
					n = stoi(input);
					break;
				}
				catch(...)
				{
					continue;
				}
			} while (true);

			cout << "Results is : " << linear_search(arr.begin(), arr.end(), n) << endl;
		}
		else if (menu == 7)
		{
			int n = 0;
			do
			{
				cout << "What element do you want to find : ";
				try
				{
					cin >> input;
					n = stoi(input);
					break;
				}
				catch (...)
				{
					continue;
				}
			} while (true);

			cout << "Results is : " << linear_search_with_barrier(arr.begin(), arr.end(), n) << endl;
		}
		else if (menu == 8)
		{
			if (!is_sorted(arr.begin(), arr.end()))
			{
				cout << "array isn't sorted, but ok, I'll do it" << endl;
				shell_sort(arr);
			}
			int n = 0;
			do
			{
				cout << "What element do you want to find : ";
				try
				{
					cin >> input;
					n = stoi(input);
					break;
				}
				catch (...)
				{
					continue;
				}
			} while (true);

			cout << "Results is : " << binary_search_(arr.begin(), arr.end(), n) << endl;
		}


	} while (true);
	return 0;
}

int main_lab5_substr()
{
	string main_str;

	cout << "Enter main string : ";
	getline(cin, main_str);
	cout << "String is : " << endl << main_str << endl;
	do
	{
		cout << "Main string : " << main_str << endl;
		cout << "1) Input new main search string" << endl;
		cout << "2) Linear search" << endl;
		cout << "3) KPM search" << endl;
		cout << "4) BM search" << endl;
		cout << "5) RK search" << endl;
		cout << ">>>";
		string input;
		int menu;

		cin >> input;

		try
		{
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
			cout << "Enter new string : ";
			getline(cin, input);
			getline(cin, main_str);
			cout << "Done" << endl;
		}
		else if (menu == 2)
		{
			cout << "Enter substr : ";
			getline(cin, input);
			getline(cin, input);
			cout << "Result : " << substr_search_linear(main_str, input) << endl;
		}
		else if (menu == 3)
		{
			cout << "Enter substr : ";
			getline(cin, input);
			getline(cin, input);
			cout << "Result : " << substr_search_kpm(main_str, input) << endl;
		}
		else if (menu == 4)
		{
			cout << "Enter substr : ";
			getline(cin, input);
			getline(cin, input);
			cout << "Result : " << substr_search_bm(main_str, input) << endl;
		}
		else if (menu == 5)
		{
			cout << "Enter substr : ";
			getline(cin, input);
			getline(cin, input);
			cout << "Result : " << substr_search_rk(main_str, input) << endl;
		}



	} while (true);
}