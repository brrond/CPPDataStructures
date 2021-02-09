#include <iostream>
#include <vector>
#include <string>
#include <fstream>

//#include "list.h"
//#include "linked_list.h"
#include "circular_linked_list.h"

using namespace std;

struct mystruct
{
	float a;
	float* b;
	int c;

	mystruct()
	{
		a = rand() % 100 + 0.5f;
		b = new float(rand() % 100 - 50 + 0.5f);
		c = rand() % 100 - 50;
	}

	mystruct(const mystruct& s)
	{
		a = s.a;
		c = s.c;
		b = new float(*s.b);
	}

	~mystruct()
	{
		delete b;
	}

	string c_str()
	{
		return (to_string(a) + " " + to_string(*b) + " " + to_string(c));
	}

	bool operator==(const mystruct& st)
	{
		return (a == st.a) && (*b == *st.b) && (c == st.c);
	}

	friend ofstream& operator<<(ofstream& out, const mystruct& st)
	{
		out << st.a << " " << *st.b << " " << st.c;
		return out;
	}

	friend ifstream& operator>>(ifstream& in, mystruct& st)
	{
		in >> st.a >> *st.b >> st.c;
		return in;
	}

};

#ifdef LINKED_LIST_H
template <typename Ty>
using list_ = linked_list<Ty>;
#elif defined LIST_H
template <typename Ty>
using list_ = list<Ty>;
#else
template <typename Ty>
using list_ = circular_linked_list<Ty>;
#endif

int main() 
{
	/*
	cout << "jfrkfgjerkgkj" << 457349543 << endl;
	list<mystruct> l, l2;
	
	for (int i = 0; i < 100; i++)
	{
		mystruct a;
		l.push_back(a);
		if (i % 2 == 0)
			l2.push_back(a);
	}

	cout << l.size() << endl;
	cout << l << endl;
	cout << l[50].c_str() << endl;

	cout << l2.size() << endl;
	l += l2;
	cout << l.size() << endl;

	for (int i = 0; i < 100; i++) 
	{
		l.erase(99 - i);
	}
	
	cout << l2 << endl;

	l.push_back({});
	cout << l.size() << endl;

	list<mystruct> l3 = l2 + l2;
	cout << l3.size() << endl;

	auto t = l[30];
	cout << l.find(t) << endl;

	cout << l.find(mystruct()) << endl;

	l3.insert(mystruct(), 0);
	l3.insert(mystruct(), 1);
	cout << l3.size() << endl;
	l3.clear();
	cout << l3.size() << endl;
	l3.insert(mystruct(), 0);
	l3.insert(mystruct(), 0);
	cout << l3.size() << endl;
	l3.swap(0);
	
	
	cout << "fjekfeje" << 1933583 << endl;
	list_<mystruct> a;
	for (int i = 0; i < 10; i++)
		a.insert({}, i);
	cout << a.size() << endl;
	cout << a << endl;
	a.swap(0);

	cout << a.find({}) << " " << a.find(a[5]) << endl;

	while(a.size() > 0)
	{
		a.erase(0);
	}

	cout << a.size() << endl;
	a.push_back({});
	cout << a[0].c_str() << " " << a.size() << endl;
	a.clear();
	cout << a.size() << endl;
	*/



	/*
	list_<mystruct> l;
	for (int i = 0; i < 10; i++)
		l.push_back({});
	
	cout << "First random gen. list" << endl;
	cout << l << endl;

	l.clear();
	cout << "List after .clear()" << endl;
	cout << l << endl;

	mystruct tmp;
	cout << "We will add this value : " << tmp.c_str() << endl;
	l.push_back(tmp);
	cout << "Here we are : " << endl;
	cout << l << endl;
	
	cout << "After erase(0) : " << endl;
	l.erase(0);
	cout << l << endl;

	cout << "Random gen. and print with size" << endl;
	for (int i = 0; i < 10; i++)
		l.push_back({});

	cout << l;
	cout << l.size() << endl;

	cout << "After .swap(0)" << endl;
	l.swap(0);
	cout << l << endl;

	cout << "Create second list with 2 elements : " << endl;
	list_<mystruct> l2;
	for (int i = 0; i < 2; i++)
		l2.insert({}, 0);
	cout << l2 << endl;

	cout << "l3 = l + l2 : " << endl;
	list_<mystruct> l3 = l + l2;
	cout << l3;
	cout << l3.size() << endl;
	*/

	list_<mystruct> l;
	do
	{
		int menu;
		cout << "List is : " << endl;
		cout << l << endl;
		cout << "1) Clear" << endl;
		cout << "2) Add new element" << endl;
		cout << "3) Delete by index" << endl;
		cout << "4) Size()" << endl;
		cout << "5) Swap elements by index" << endl;
		cout << "6) Add new list in the end" << endl;
		cout << "7) Read from file" << endl;
		cout << "8) Write to file" << endl;
		cout << "0) Exit" << endl;
		try
		{
			cout << ">>>";
			cin >> menu;
		}
		catch(...)
		{
			cout << "Your enter is pretty bad" << endl;
			continue;
		}

		if (menu == 0)
		{
			return 0;
		}
		else if (menu == 1)
		{
			l.clear();
			cout << "Done" << endl;
		}
		else if (menu == 2)
		{
			cout << "Keyboard input(0) or random value(1)" << endl;
			int n;
			try
			{
				cin >> n;
			}
			catch (...)
			{
				cout << "Wow, don't do that" << endl;
				continue;
			}

			if (n == 1)
			{

			}
			else if (n == 0)
			{
				mystruct new_e;
				cout << "Ok, then enter float, float and int : " << endl;
				try
				{
					cin >> new_e.a;
					cin >> *new_e.b;
					cin >> new_e.c;
				}
				catch (...)
				{
					cout << "U are... never mind. Try again" << endl;
					continue;
				}

				l.push_back(new_e);
				continue;
			}
			else {
				cout << "I'll generate value by myself..." << endl;
			}

			mystruct new_e;
			cout << "This informaiton will be added in the end : " << new_e.c_str() << endl;
			l.push_back(new_e);
			cout << "Done" << endl;
		}
		else if (menu == 3)
		{
			cout << "Enter index : "; int n; cin >> n;
			try
			{
				l.erase(n);
			}
			catch (...)
			{
				cout << "Wrong index" << endl;
				continue;
			}
			cout << "Done" << endl;
		}
		else if (menu == 4)
		{
			cout << "Size of the list : " << l.size() << endl;
		}
		else if (menu == 5)
		{
			cout << "Enter index (.swap(index, index + 1) : "; int n; cin >> n;
			try
			{
				l.swap(n);
			}
			catch (...)
			{
				cout << "Wrong index" << endl;
				continue;
			}
			cout << "Done" << endl;
		}
		else if (menu == 6)
		{
			list_<mystruct> l2;
			for (int i = 0; i < 3; i++)
			{
				l2.push_back({});
			}
			cout << "Ok, will be added this list : " << endl;
			cout << l2 << endl;
			l += l2;
			cout << "Done" << endl;
		}
		else if (menu == 7)
		{
			// read
			ifstream fin("file.txt");
			while (!fin.eof())
			{
				mystruct a;
				fin >> a;
				l.push_back(a);
			}
			l.erase(l.size() - 1);
			fin.close();
		}
		else if (menu == 8)
		{
			// wrtie
			ofstream fout("file.txt");
			for (int i = 0; i < l.size(); i++)
			{
				fout << l[i] << endl;
			}
			fout.close();
			cout << "Done" << endl;
		}

	} while (true);


	return 0;
}