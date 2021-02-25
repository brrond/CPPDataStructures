#include "dependencies.h"

using namespace std;

#define star 14159265

int main_lab2_stack()
{
	
	stack<int> st;
	for (int i = 0; i < 10; i++)
	{
		st.push(i);
	}

	do {

		string menu_string;
		int menu;

		cout << "Stack (from bottom to top) : " << endl << st << endl;
		cout << "0) Exit" << endl;
		cout << "1) Swap first and last elements" << endl;
		cout << "2) Reverse" << endl;
		cout << "3) Delete element in the middle" << endl;
		cout << "4) Remove every second" << endl;			
		cout << "5) Insert '*' in the middle" << endl;
		cout << "6) Insert 0 after min element" << endl;
		cout << "7) Insert 0 after max element" << endl;
		cout << "8) Remove min" << endl;
		cout << "9) Remove all expect first" << endl;		
		cout << "10) Remove all expect last" << endl;		
		cout << "11) Remove max" << endl;	
		cout << "12) Replace min element with 0" << endl;
		cout << "13) Push" << endl;
		cout << ">>>";
		try
		{
			cin >> menu_string;
			if (menu_string == "cls")
			{
				system("cls");
				continue;
			}
			else if (menu_string == "exit")
			{
				exit(0);
			}
			menu = stoi(menu_string);
		}
		catch (...)
		{
			cout << "Nope" << endl;
			continue;
		}

		if (menu == 1)
		{
			if (st.size() < 2)
			{
				cout << "There are not enough elements" << endl;
				continue;
			}

			int f = st.top();
			st.pop();
			stack<int> secst;
			int size = st.size() - 1;
			int sizec = size;
			while (sizec--)
			{
				secst.push(st.top());
				st.pop();
			}
			
			int tmp = st.top();
			st.pop();
			st.push(f);
			while (size--)
			{
				st.push(secst.top());
				secst.pop();
			}
			
			st.push(tmp);
			cout << "Done" << endl;
		}
		else if (menu == 0)
		{
			return 0;
		}
		else if (menu == 2)
		{
			stack<int> st2;
			while (st.size())
			{
				st2.push(st.top());
				st.pop();
			}
			st = st2;
			cout << "Done" << endl;
		}
		else if (menu == 3)
		{
			if (st.size() == 0)
			{
				cout << "There is no elements" << endl;
				continue;
			}
			bool two = false;
			int mid;
			if (st.size() % 2 == 0)
			{
				two = true;
				mid = st.size() / 2 - 1;
			}
			else
			{
				mid = st.size() / 2;
			}

			auto st2 = st.create_reverse();
			st.clear();
			int j = 0;
			while (st2.size())
			{
				if (j++ == mid)
				{
					if (two)
					{
						mid++;
						two = false;
					}
					st2.pop();
					continue;
				}
				st.push(st2.top());
				st2.pop();
			}
		}
		else if (menu == 4)
		{
			stack<int> st2;
			while (size_t size = st.size())
			{
				if (size % 2 == 0)
				{
					st.pop();
					continue;
				}
				st2.push(st.top());
				st.pop();
			}
			st.clear();
			while (st2.size())
			{
				st.push(st2.top());
				st2.pop();
			}
			cout << "Done" << endl;
		}
		else if (menu == 5)
		{
			int mid = 0;
			if (st.size() % 2 == 0)
				mid = st.size() / 2 - 1;
			else
				mid = st.size() / 2;

			auto st2 = st.create_reverse();
			st.clear();

			int j = 0;
			while (st2.size())
			{
				st.push(st2.top());
				st2.pop();
				if (j == mid)
					st.push(star);
				j++;
			}

		}
		else if (menu == 6)
		{
			try
			{
				int min = st.min_value();
				stack<int> st2;
				while (st.size())
				{
					st2.push(st.top());
					st.pop();
				}

				while (st2.size())
				{
					st.push(st2.top());
					if (st2.top() == min)
						st.push(0);
					st2.pop();
				}
			}
			catch (...)
			{
				cout << "There is no elements" << endl;
			}
		}
		else if (menu == 7)
		{
			try
			{
				int max = st.max_value();
				stack<int> st2;
				while (st.size())
				{
					st2.push(st.top());
					st.pop();
				}

				while (st2.size())
				{
					st.push(st2.top());
					if (st2.top() == max)
						st.push(0);
					st2.pop();
				}
			}
			catch (...)
			{
				cout << "There is no elements" << endl;
			}
		}
		else if (menu == 8)
		{
			try
			{
				auto st2 = st.create_reverse();
				int min = st.min_value();
				st.clear();

				while (st2.size())
				{
					if(st2.top() != min)
						st.push(st2.top());
					st2.pop();
				}
			}
			catch (...)
			{
				cout << "There is no elements" << endl;
			}
		}
		else if (menu == 9)
		{
			if (st.size())
			{
				int top = st.top();
				st.clear();
				st.push(top);
				cout << "Done" << endl;
			}
			else
			{
				cout << "There is no elements" << endl;
			}
		}
		else if (menu == 10)
		{
			if (st.size())
			{
				while (st.size() != 1)
				{
					st.pop();
				}
				cout << "Done" << endl;
			}
			else
			{
				cout << "There is no elements" << endl;
			}
		}
		else if (menu == 11)
		{
			try
			{
				int max = st.max_value();
				stack<int> st2 = st.create_reverse();
				st.clear();
				
				while (st2.size())
				{
					if (st2.top() == max)
					{
						st2.pop();
						continue;
					}
					st.push(st2.top());
					st2.pop();
				}
				cout << "Done" << endl;
			}
			catch(...)
			{
				cout << "There is no elements" << endl;
			}

		}
		else if (menu == 12)
		{
		try
		{
			int min = st.min_value();
			stack<int> st2 = st.create_reverse();
			st.clear();

			while (st2.size())
			{
				if (st2.top() == min)
				{
					st.push(0);
					st2.pop();
					continue;
				}
				st.push(st2.top());
				st2.pop();
			}
			cout << "Done" << endl;
		}
		catch(...)
		{
			cout << "There is no elements" << endl;
		}

		}
		else if (menu == 13)
		{
			int kr;
			cout << "From keyboard(1) or random(0) >>>"; 
			try
			{
				cin >> kr;
			}
			catch (...)
			{
				cout << "Nope" << endl;
			}

			if (kr == 0)
			{

			}
			else if (kr == 1)
			{
				cout << "Enter number >>>";
				int n; 
				try
				{
					cin >> n;
				}
				catch (...)
				{
					cout << "Nope" << endl;
					continue;
				}
				st.push(n);
				continue;
			}
			else
			{
				cout << "Nope" << endl;
			}

			int n = rand() % 100;
			cout << "Element : " << n << endl;
			st.push(n);
			cout << "Done" << endl;
		}



	} while (true);


	return 0;
}


int main_lab2_queue()
{
	queue<int> a;

	for (int i = 0; i < 10; i++)
	{
		a.push(i);
	}

	do 
	{
		string menu_string;
		int menu = 1000;
		cout << "List is : ";
		cout << a << endl;
		cout << "0) Exit" << endl;
		cout << "1) Size()" << endl;
		cout << "2) Average" << endl;
		cout << "3) Min and Max" << endl;
		cout << "4) Get {i} element" << endl;
		cout << "5) Before min" << endl;
		cout << "6) Push" << endl;
		cout << "7) Clear" << endl;
		cout << ">>>";
		cin >> menu_string;

		try
		{
			if (menu_string == "exit")
			{
				return 0;
			}
			else if (menu_string == "cls")
			{
				system("cls");
			}
			else
			{
				menu = stoi(menu_string);
			}
		}
		catch (...)
		{
			cout << "Try again" << endl;
			continue;
		}

		if (menu == 0)
		{
			return 0;
		}
		else if (menu == 1)
		{
			cout << "Size : " << a.size() << endl;
		}
		else if (menu == 2)
		{
			int avg = 0;
			queue<int> a_cp(a);
			if (a_cp.size())
			{
				while (a_cp.size())
				{
					avg += a_cp.front_pop();
				}
				cout << "Avg : " << (float)avg / a.size() << endl;
			}
			else {
				cout << "There is no elements" << endl;
			}
		}
		else if (menu == 3)
		{

		}
		else if (menu == 6)
		{
			cout << "Random(1) or keyboard(0) >>>";
			string kr; cin >> kr;
			int kr_i = 1;
			try
			{
				kr_i = stoi(kr);
			}
			catch (...)
			{
				cout << "Try again" << endl;
			}

			int n; cout << "How many elements : ";
			cin >> n;

			if (kr_i == 0)
			{
				while (n--)
				{
					int value;
					cout << "Enter value : "; cin >> value;
					a.push(value);
				}
				cout << "Done" << endl;
				continue;
			}

			while (n--)
			{
				int value = rand() % 100 - 50;
				a.push(value);
			}
			cout << "Done" << endl;
		}
		else if (menu == 7)
		{
			a.clear();
		}

	} while (true);

	return 0;
}