#pragma once
//#ifndef STACK_H
//#define STACK_H

#include "../slist_llist_cllist/list.h"

template <typename Ty, typename base_type = list<Ty>>
class stack : protected base_type{
public:
	stack();
	stack(const stack& st);
	~stack();

	void clear();
	size_t size();
	void push_back(const Ty& data);
	void pop();
	Ty& back();

protected:
	
private:


};


#include "stack.cpp"

//#endif 