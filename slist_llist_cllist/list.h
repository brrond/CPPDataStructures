#pragma once
#ifndef LIST_H
#define LIST_H

#include <iostream>

template <typename Ty>
struct node_t
{
	node_t* next = nullptr;
	Ty* data = nullptr;
};

template <typename Ty>
class list
{
public:
	list();
	list(const list& l);
	~list();

	void push_back(const Ty& value);
	void insert(const Ty& value, size_t index);
	void erase(size_t index);
	void clear();
	
	size_t size();

	// swap(index, index + 1)
	void swap(size_t index);
	void swap(size_t index1, size_t index2);
	
	int64_t find(const Ty& value);

	Ty& operator[](size_t index);
	list operator+(const list& l2);
	list& operator+=(const list& l2);

	template <typename Ty>
	friend std::ostream& operator<<(std::ostream& out, const list<Ty>& l);

protected:
	node_t<Ty>* begin;

private:

};

#include "list.cpp"
#endif /* LIST_H */