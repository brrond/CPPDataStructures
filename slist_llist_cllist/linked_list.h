#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <typename Ty>
struct node_linked_t
{
	node_linked_t* next = nullptr;
	node_linked_t* prev = nullptr;
	Ty* data = nullptr;
};

template <typename Ty>
class linked_list
{
public:
	linked_list();
	linked_list(const linked_list& l);
	~linked_list();

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
	linked_list operator+(const linked_list& l2);
	linked_list& operator+=(const linked_list& l2);

	template <typename Ty>
	friend std::ostream& operator<<(std::ostream& out, const linked_list<Ty>& l);

protected:
	node_linked_t<Ty>* begin;
	node_linked_t<Ty>* tail;

private:

};

#include "linked_list.cpp"
#endif /*LINKED_LIST_H*/