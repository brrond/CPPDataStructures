#pragma once
#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <iostream>

template <typename Ty>
struct node_circular_linked_t
{
	node_circular_linked_t* next = this;
	node_circular_linked_t* prev = this;
	Ty* data = nullptr;
};

template <typename Ty>
class circular_linked_list
{
public:
	circular_linked_list();
	circular_linked_list(const circular_linked_list& l);
	~circular_linked_list();

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
	circular_linked_list operator+(const circular_linked_list& l2); //
	circular_linked_list& operator+=(const circular_linked_list& l2);//

	template <typename Ty>
	friend std::ostream& operator<<(std::ostream& out, const circular_linked_list<Ty>& l);

protected:
	node_circular_linked_t<Ty>* begin;

private:

};

#include "circular_linked_list.cpp"
#endif /*CIRCULAR_LINKED_LIST_H*/