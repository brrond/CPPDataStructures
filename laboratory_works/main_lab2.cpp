#include "dependencies.h"



using namespace std;



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
		cout << "14) Write to file" << endl;
		cout << "15) Read from file" << endl;
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
				return 0;
			}
			else if (menu_string == "size")
			{
				cout << st.size() << endl;
				continue;
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

			int j = 0;
			while (st2.size())
			{
				cout << st2.top() << " ";
				st2.pop();
				if (j == mid) {
					cout << "*" << " ";
				}
				j++;
			}
			cout << endl;

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
				while (st.size() > 1)
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
		else if (menu == 14)
		{
			fstream fout;
			fout.open("file.txt");
			stack<int> st2 = st.create_reverse();
			while (st2.size())
			{
				fout << st2.top() << " ";
				st2.pop();
			}
			fout.close();
			cout << "Done" << endl;
		}
		else if (menu == 15)
		{
			ifstream fin;
			fin.open("file.txt");
			while (!fin.eof())
			{
				int n; fin >> n;
				st.push(n);
			}
			st.pop();
			fin.close();
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
		cout << "Queue is : ";
		cout << a << endl;
		cout << "0) Exit" << endl;
		cout << "1) Size()" << endl;
		cout << "2) Average" << endl;
		cout << "3) Min and Max" << endl;
		cout << "4) Get {i} element" << endl;
		cout << "5) Before min" << endl;
		cout << "6) Push" << endl;
		cout << "7) Clear" << endl;
		cout << "8) Write to file" << endl;
		cout << "9) Read from file" << endl;
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
			queue<int> q(a);
			if (!q.size())
			{
				cout << "There is no elements" << endl;
				continue;
			}
			int min, max;
			min = max = q.front_pop();
			while (q.size())
			{
				if (q.front() > max)
				{
					max = q.front();
				}
				else if (q.front() < min)
				{
					min = q.front();
				}
				q.pop();
			}
			cout << "Min : " << min << ", max : " << max << endl;
		}
		else if (menu == 4)
		{
			cout << "Enter i : ";
			int i; cin >> i;
			if (i < 0 || i >= a.size())
			{
				cout << "Incorrect input" << endl;
				continue;
			}

			queue<int> q(a);
			for (int j = 0; j < i && q.size(); j++)
			{
				q.pop();
			}

			if (!q.size())
			{
				cout << i << " is out of range" << endl;
				continue;
			}

			cout << q.front() << endl;
		}
		else if (menu == 5)
		{
			if (!a.size())
			{
				cout << "There is no elements" << endl;
				continue;
			}

			queue<int> q(a);
			int min = q.front_pop();
			int min_i = 0;
			int i = 0;
			while (q.size())
			{
				if (q.front() < min)
				{
					min = q.front();
					min_i = i;
				}
				q.pop();
				i++;
			}

			if (min_i == 0)
			{
				cout << "First element is min" << endl;
			}
			else
			{
				queue<int> q2(a);
				while (min_i--)
				{
					q2.pop();
				}
				cout << q2.front() << endl;
			}
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
			n = abs(n);

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
		else if (menu == 8)
		{
			fstream fout;
			fout.open("file.txt");
			queue<int> q = a;
			while (q.size())
			{
				fout << q.front_pop() << " ";
			}
			fout.close();
			cout << "Done" << endl;
		}
		else if (menu == 9)
		{
			ifstream fin;
			fin.open("file.txt");
			bool first = true;
			int prev;
			while (!fin.eof())
			{
				int n; fin >> n;
				if (first) {
					prev = n;
					first = false;
					continue;
				}
				a.push(prev);
				prev = n;
			}
			fin.close();
			cout << "Done" << endl;
		}

	} while (true);

	return 0;
}



int get_value(bool rk)
{
	//Random(1) keyboard(0)
	if (rk)
	{
		return rand() % 100 - 50;
	}
	string n_str;
	int n = 0;
	cout << "Enter value : "; cin >> n_str;
	try
	{
		n = stoi(n_str);
	}
	catch (...)
	{
		int n = rand() % 100 - 50;
		cout << "Nope. This one will be " << n << endl;
		return n;
	}
	return n;
}



int main_lab2_deque()
{
	string input;
	int menu;

	deque<int> a;

	for (int i = 0; i < 10; i++)
	{
		a.push_front(i);
	}

	do
	{
		cout << "Deque : " << a << endl;
		cout << "1) Clear" << endl;
		cout << "2) Is empty" << endl;
		cout << "3) Push front" << endl;
		cout << "4) Push back" << endl;
		cout << "5) Front" << endl;
		cout << "6) Back" << endl;
		cout << "7) Pop front" << endl;
		cout << "8) Pop back" << endl;
		cout << "9) Get by index" << endl;
		cout << "10) Insert" << endl;		
		cout << "0) Exit" << endl;
		cout << "11) Write to file" << endl;
		cout << "12) Read from file" << endl;
		cout << ">>>";
		cin >> input;

		try
		{
			if (input == "exit")
			{
				return 0;
			}
			else if (input == "cls")
			{
				system("cls");
				continue;
			}
			
			menu = stoi(input);
		}
		catch (...)
		{
			cout << "Nope" << endl;
			continue;
		}

		if (menu == 0)
		{
			return 0;
		}
		else if (menu == 1)
		{
			a.clear();
		}
		else if (menu == 2)
		{
			cout << "Is empty : " << a.is_empty() << endl;
		}
		else if (menu == 3)
		{
			bool rk;
			cout << "Random(1) keyboard(0) > "; cin >> rk;
			cout << "How many  elements > "; cin >> input;
			int n;
			try
			{
				n = abs(stoi(input));
			}
			catch (...)
			{
				cout << "Try again later" << endl;
				continue;
			}

			while (n--)
			{
				a.push_front(get_value(rk));
			}
			cout << "Done" << endl;
		}
		else if (menu == 4)
		{
			bool rk;
			cout << "Random(1) keyboard(0) > "; cin >> rk;
			cout << "How many  elements > "; cin >> input;
			int n;
			try
			{
				n = abs(stoi(input));
			}
			catch (...)
			{
				cout << "Try again later" << endl;
				continue;
			}

			while (n--)
			{
				a.push_back(get_value(rk));
			}
			cout << "Done" << endl;
		}
		else if (menu == 5)
		{
			if (!a.size())
			{
				cout << "Deque is empty" << endl;
				continue;
			}
			cout << "Front is : " << a.front() << endl;
		}
		else if (menu == 6)
		{
			if (!a.size())
			{
				cout << "Deque is empty" << endl;
				continue;
			}
			cout << "Back is : " << a.back() << endl;
		}
		else if (menu == 7)
		{
			if (!a.size())
			{
				cout << "There is no elements" << endl;
				continue;
			}
			a.pop_front();
			cout << "Done" << endl;
		}
		else if (menu == 8)
		{
			if (!a.size())
			{
				cout << "There is no elements" << endl;
				continue;
			}
			a.pop_back();
			cout << "Done" << endl;
		}
		else if (menu == 9)
		{
			if (a.is_empty())
			{
				cout << "Deque is empty" << endl;
				continue;
			}
			cout << "Enter index > "; int n; cin >> n;
			try
			{
				n = a[n];
			}
			catch (...)
			{
				cout << "Index out of range" << endl;
				continue;
			}
			cout << "Value is : " << n << endl;
		}
		else if (menu == 10)
		{
			bool rk;
			cout << "Random(1) keyboard(0) > "; cin >> rk;
			cout << "Where do you want to insert value >>>"; int i; cin >> i;
			a.insert(i, get_value(rk));
			cout << "Done" << endl;
		}
		else if (menu == 11)
		{
			fstream fout;
			fout.open("file.txt");
			deque<int> dq = a;
			while (dq.size())
			{
				fout << dq.front() << " ";
				dq.pop_front();
			}
			fout.close();
			cout << "Done" << endl;
			}
		else if (menu == 12)
		{
			ifstream fin;
			fin.open("file.txt");
			while (!fin.eof())
			{
				int n; fin >> n;
				a.push_back(n);
			}
			fin.close();
			a.pop_back();
			cout << "Done" << endl;
		}

	} while (true);


	return 0;
}


