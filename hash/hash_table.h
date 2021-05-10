#pragma once

#include <functional>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using std::function;
using std::vector;

template <typename T>
class hash_table
{
public:
	hash_table(size_t m, function<size_t(T)> h, function<size_t(T, size_t)> h_ = NULL);
	~hash_table();

	void insert(T val);
	int find(T val);
	void remove(T val);

	friend std::ostream& operator<<(std::ostream& out, hash_table ht)
	{
		for (size_t i = 0; i < ht.M; i++)
		{
			out << i << " : ";
			if (ht.table[i] == nullptr)
				out << '-';
			else
				out << *ht.table[i];
			out << std::endl;
		}
		return out;
	}

protected:

private:
	function<size_t(T)> h;
	function<size_t(T, size_t)> h_;
	vector<T*> table;

	size_t M;
	size_t size;
};

#include "hash_table.cpp"