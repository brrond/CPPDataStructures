#include "hash_table.h"

template<typename T>
hash_table<T>::hash_table(size_t m, function<size_t(T)> h, function<size_t(T, size_t)> h_)
{
	M = m;
	this->h = h;
	this->h_ = h_;

	table.resize(M);
	size = 0;

	std::for_each(table.begin(), table.end(), [](T*& n) {n = nullptr; });
}

template<typename T>
hash_table<T>::~hash_table()
{

}

template<typename T>
void hash_table<T>::insert(T val)
{
	size_t pos = h(val);
	if(pos >= M)
		throw "Incorrect work of hash function";

	if(size == M)
		throw "Table is full";

	if (table.at(pos) != nullptr)
	{
		size_t new_pos = pos + 1;
		if (h_ != NULL)
		{
			size_t i = 1;
			while (true)
			{
				new_pos = h_(val, i++);
				if (table.at(new_pos) == nullptr)
				{
					table[new_pos] = new T(val);
					size++;
					return;
				}
			}
			
		}
		else
		{
			while (new_pos != pos)
			{
				if (new_pos == M)
					new_pos = 0;
				
				if (table.at(new_pos) == nullptr)
				{
					table[new_pos] = new T(val);
					size++;
					return;
				}

				new_pos++;
			}
			throw "Table is full";
		}
	}
	else
	{
		table[pos] = new T(val);
		size++;
	}
}

template<typename T>
int hash_table<T>::find(T val)
{
	size_t pos = h(val);
	if (pos >= M)
		throw "Incorrect work of hash function";

	if (*table[pos] == val)
		return pos;

	size_t new_pos;
	
	if (h_ == NULL)
		new_pos = pos + 1;
	else
		new_pos = h_(val, 1);
	
	size_t i = 2;
	while (i < M * 10)
	{
		if (h_ == NULL)
		{
			new_pos++;
			if (new_pos >= M)
				new_pos = 0;
		}
		else
		{
			new_pos = h_(val, i);
		}

		if ((table[new_pos] != nullptr) && *table[new_pos] == val)
			return new_pos;

		i++;
	}

	return -1;
}

template<typename T>
void hash_table<T>::remove(T val)
{
	size_t pos = h(val);
	if (pos >= M)
		throw "Incorrect work of hash function";

	if ((table[pos] != nullptr) && *table[pos] == val)
	{
		delete table[pos];
		table[pos] = nullptr;
		size--;
		return;
	}

	size_t new_pos;
	if (h_ == NULL)
		new_pos = pos + 1;
	else
		new_pos = h_(val, 1);

	size_t i = 2;
	while (i < M * 10)
	{
		if (h_ == NULL)
		{
			new_pos++;
			if (new_pos >= M)
				new_pos = 0;
		}
		else
		{
			new_pos = h_(val, i);
		}

		if ((table[new_pos] != nullptr) && *table[new_pos] == val)
		{
			delete table[new_pos];
			table[new_pos] = nullptr;
			size--;
			return;
		}

		i++;
	}

	return;
}

