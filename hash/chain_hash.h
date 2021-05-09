#pragma once

#include <forward_list>
#include <vector>
#include <functional>
#include <algorithm>
#include <ostream>
#include <string>

using std::forward_list;
using std::vector;
using std::function;
using std::string;

template <typename T>
class chain_hash
{
public:
	chain_hash(size_t m, function<size_t(T)> h);
	~chain_hash();

	void insert(T val);
	int find(T val);
	void remove(T val);

	friend std::ostream& operator<<(std::ostream& out, chain_hash ht)
	{
		string str = "";
		for (size_t i = 0; i < ht.table.size(); i++)
		{
			str += std::to_string(i) + " : ";
			for (auto it = ht.table[i].begin(); it != ht.table[i].end(); it++)
			{
				str += std::to_string(*it) + " ";
			}
			str += "\n";
			out << str;
			str = "";
		}
		return out;
	}

protected:

private:
	function<size_t(T)> h;
	vector<forward_list<T>> table;
};

#include "chain_hash.cpp"