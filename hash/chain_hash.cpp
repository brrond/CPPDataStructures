#include "chain_hash.h"

template<typename T>
chain_hash<T>::chain_hash(size_t m, function<size_t(T)> h)
{
	table.resize(m);
	table.shrink_to_fit();
	this->h = h;
}

template<typename T>
chain_hash<T>::~chain_hash()
{

}

template<typename T>
void chain_hash<T>::insert(T val)
{
	size_t pos = h(val);
	if (pos >= table.size())
		throw "Incorrect work of hash function";

	table[pos].push_front(val);
}

template<typename T>
int chain_hash<T>::find(T val)
{
	size_t pos = h(val);
	if (pos >= table.size())
		throw "Incorrect work of hash function";

	auto it = std::find(table[pos].begin(), table[pos].end(), val);
	if (it != table[pos].end())
		return pos;

	return -1;
}

template<typename T>
void chain_hash<T>::remove(T val)
{
	size_t pos = h(val);
	if (pos >= table.size())
		throw "Incorrect work of hash function";

	table[pos].remove(val);
	return;
}

