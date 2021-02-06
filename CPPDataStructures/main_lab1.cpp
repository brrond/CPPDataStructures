#include <iostream>
#include <vector>
#include <string>

#include "list.h"

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

};

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
	*/

	list<mystruct> l;
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
	list<mystruct> l2;
	for (int i = 0; i < 2; i++)
		l2.insert({}, 0);
	cout << l2 << endl;

	cout << "l3 = l + l2 : " << endl;
	list<mystruct> l3 = l + l2;
	cout << l3;
	cout << l3.size() << endl;

	return 0;
}