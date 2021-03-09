#pragma once
#ifndef STACK_H
#define STACK_H

#include "../slist_llist_cllist/list.h"

template <typename Ty, typename base_type = list<Ty>>
class stack : protected base_type{
public:
	stack();
	stack(const stack& st);
	~stack();

	void clear();
	size_t size();
	void push(const Ty& data);
	void pop();
	Ty& top();

	Ty min_value();
	Ty max_value();

	stack create_reverse();

	friend std::ostream& operator<<(std::ostream& out, stack st)
	{
		if (st.size() == 0) return out;
		Ty el = st.top();
		st.pop();
		out << st;
		out << el << " ";
		return out;
	}

protected:
	

private:


};


#include "stack.cpp"

#endif 