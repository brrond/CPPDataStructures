#include "dependencies.h"

using namespace std;

void chain_table_menu()
{
	chain_hash<int>* ch = nullptr;
	do {
		int menu;
		cout << "1) Create" << endl;
		cout << "2) Print" << endl;
		cout << "3) Insert" << endl;
		cout << "4) Find" << endl;
		cout << "5) Remove" << endl;
		cout << "6) Write to file" << endl;
		cout << "7) Read from file" << endl;
		cout << ">>>"; cin >> menu;

		if (menu == 1)
		{
			cout << "Enter size : ";
			int m; cin >> m;
			ch = new chain_hash<int>(m, [m](int k) {return k % m; });
			cout << "Done" << endl;
		}
		else if (menu == 2)
		{
			if (ch != nullptr)
			{
				cout << *ch;
			}
			else
			{
				cout << "Create table first" << endl;
			}
		}
		else if (menu == 3)
		{
			if (ch != nullptr)
			{
				cout << "Enter number : ";
				int n; cin >> n;
				ch->insert(n);
			}
			else
			{
				cout << "Create table first" << endl;
			}
		}
		else if (menu == 4)
		{
			if (ch != nullptr)
			{
				cout << "Enter number : ";
				int n; cin >> n;
				cout << "Result is : " << ch->find(n) << endl;
			}
			else
			{
				cout << "Create table first" << endl;
			}
		}
		else if (menu == 5)
		{
			if (ch != nullptr)
			{
				cout << "Enter number : ";
				int n; cin >> n;
				ch->remove(n);
				cout << "Done" << endl;
			}
			else
			{
				cout << "Create table first" << endl;
			}
		}
		else if (menu == 6)
		{
			if (ch != nullptr)
			{
				ofstream fout;
				fout.open("out.txt");
				fout << *ch;
				fout.close();
				cout << "Done" << endl;
			}
			else
			{
				cout << "Create table first" << endl;
			}
		}
		else if (menu == 7)
		{
			if (ch != nullptr)
			{
				ifstream fin;
				fin.open("inp.txt");
				while (!fin.eof())
				{
					int n;
					fin >> n;
					ch->insert(n);
				}
				fin.close();
				cout << "Done" << endl;
			}
			else
			{
				cout << "Create table first" << endl;
			}
		}
		else if (menu == 0)
			return;

	} while (true);

}

hash_table<int>* get_ht(int prob, int m)
{
	if (prob == 0)
		return new hash_table<int>(m, [m](int k) {return k % m; });
	else if(prob == 1)
		return new hash_table<int>(m, [m](int k) {return k % m; }, [m](int k, int i) {return (k % m + 1 * i) % m; });
	else if (prob == 2)
		return new hash_table<int>(m, [m](int k) {return k % m; }, 
			[m](int k, int i) {return (k % m + 1 * i + 3 * i * i) % m; });
	else
		return new hash_table<int>(m, [m](int k) {return k % m; },
			[m](int k, int i) {return (k % m + i * (1 + k % (m-1)) ) % m; });
}

void prob_menu(int prob_type)
{
	hash_table<int>* ht = nullptr;
	do {
		int menu;
		cout << "1) Create" << endl;
		cout << "2) Print" << endl;
		cout << "3) Insert" << endl;
		cout << "4) Find" << endl;
		cout << "5) Remove" << endl;
		cout << "6) Write to file" << endl;
		cout << "7) Read from file" << endl;
		cout << ">>>"; cin >> menu;

		if (menu == 1)
		{
			cout << "Enter size : ";
			int m; cin >> m;
			ht = get_ht(prob_type, m);
			cout << "Done" << endl;
		}
		else if (menu == 2)
		{
			if (ht != nullptr)
			{
				cout << *ht;
			}
			else
			{
				cout << "Create table first" << endl;
			}
		}
		else if (menu == 3)
		{
			if (ht != nullptr)
			{
				cout << "Enter number : ";
				int n; cin >> n;
				ht->insert(n);
			}
			else
			{
				cout << "Create table first" << endl;
			}
		}
		else if (menu == 4)
		{
			if (ht != nullptr)
			{
				cout << "Enter number : ";
				int n; cin >> n;
				cout << "Result is : " << ht->find(n) << endl;
			}
			else
			{
				cout << "Create table first" << endl;
			}
		}
		else if (menu == 5)
		{
			if (ht != nullptr)
			{
				cout << "Enter number : ";
				int n; cin >> n;
				ht->remove(n);
				cout << "Done" << endl;
			}
			else
			{
				cout << "Create table first" << endl;
			}
		}
		else if (menu == 6)
		{
			if (ht != nullptr)
			{
				ofstream fout;
				fout.open("out.txt");
				fout << *ht;
				fout.close();
				cout << "Done" << endl;
			}
			else
			{
				cout << "Create table first" << endl;
			}
		}
		else if (menu == 7)
		{
			if (ht != nullptr)
			{
				ifstream fin;
				fin.open("inp.txt");
				while (!fin.eof())
				{
					int n;
					fin >> n;
					try{ ht->insert(n); }
					catch (...) { break; cout << "There are too much data" << endl; }
				}
				fin.close();
				cout << "Done" << endl;
			}
			else
			{
				cout << "Create table first" << endl;
			}
		}
		else if (menu == 0)
			return;

	} while (true);

}

int main_lab6()
{
	cout << "Hello Hash!" << 2144 << endl;

	vector<int> arr = { 49, 32, 75, 53, 85, 19, 76, 44, 5 };
	const int M = 11;
	auto h_ = [M](int k) {return k % M; };
	auto h1 = h_;
	auto h2 = [M](int k) {return 1 + (k % (M - 1)); };

	int menu;
	string input;
	chain_hash<int>* ch = nullptr;
	hash_table<int>* ht = nullptr;

	do
	{
		cout << "1) First task" << endl;
		cout << "2) Second task" << endl;
		cout << "3) Third task" << endl;
		cout << "/*---------------------------*/" << endl;
		cout << "4) Chain table" << endl;
		cout << "5) Inc prob" << endl;
		cout << "6) Linear prob" << endl;
		cout << "7) Squeare prob" << endl;
		cout << "8) Double hash" << endl;
		cout << ">>>";

		getline(cin, input);

		if (input == "exit")
		{
			return 0;
		}
		else if (input == "cls" || input == "clear")
		{
			system("cls");
			continue;
		}

		try
		{
			menu = stoi(input);
		}
		catch(...)
		{
			continue;
		}

		if (menu == 0)
		{
			return 0;
		}
		else if (menu == 1)
		{
			float A = (sqrt(5) - 1) / 2;
			hash_table<int> ht(20, [A](int k) {
				float t = k * A;
				return (size_t)((t - floor(t)) * 20);
				});

			ht.insert(81);
			ht.insert(82);
			ht.insert(83);
			ht.insert(84);
			ht.insert(85);

			cout << ht << "Done" << endl;
		}
		else if (menu == 2)
		{
			chain_hash<int> table(9, [](int k) {return k % 9; });
			for_each(arr.begin(), arr.end(), [&table](int n) {table.insert(n); });
			cout << table << "Done" << endl;
		}
		else if (menu == 3)
		{
			hash_table<int> ht_1(M, h_);
			hash_table<int> ht_2(M, h_, [h_, M](int k, int i) { return (h_(k) + i * 1 + i * i * 3) % M; });
			hash_table<int> ht_3(M, h_, [h1, h2, M](int k, int i) {return  (h1(k) + i * h2(k)) % M; });

			for_each(arr.begin(), arr.end(), [&ht_1, &ht_2, &ht_3](int n) {
				ht_1.insert(n);
				ht_2.insert(n); 
				ht_3.insert(n); 
			});
			
			cout << "First : \n" << ht_1 << "Second : \n" << ht_2 << "Third : \n" << ht_3 << "Done\n";
		}
		else if (menu == 4)
		{
			cout << "Ok : " << endl;
			chain_table_menu();
		}
		else if (menu == 5)
		{
			prob_menu(0);
		}
		else if (menu == 6)
		{
			prob_menu(1);
		}
		else if (menu == 7)
		{
			prob_menu(2);
		}
		else if (menu == 8)
		{
			prob_menu(3);
		}


	} while (true);

	if (ch != nullptr)
		delete ch;

	if (ht != nullptr)
		delete ht;

	return 0;
}