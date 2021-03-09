#include "stack.h"

template<typename Ty, typename base_type>
stack<Ty, base_type>::stack() : base_type()
{

}

template<typename Ty, typename base_type>
stack<Ty, base_type>::stack(const stack& st) : base_type(static_cast<const base_type&>(st))
{

}

template<typename Ty, typename base_type>
stack<Ty, base_type>::~stack()
{

}

template<typename Ty, typename base_type>
void stack<Ty, base_type>::clear()
{
	static_cast<base_type&>(*this).clear();
}

template<typename Ty, typename base_type>
size_t stack<Ty, base_type>::size()
{
	return static_cast<base_type>(*this).size();
}

template<typename Ty, typename base_type>
void stack<Ty, base_type>::push(const Ty& data)
{
	static_cast<base_type&>(*this).insert(data, 0);
}

template<typename Ty, typename base_type>
void stack<Ty, base_type>::pop()
{
	static_cast<base_type&>(*this).erase(0);
}

template<typename Ty, typename base_type>
Ty& stack<Ty, base_type>::top()
{
	return static_cast<base_type&>(*this).operator[](0);
}

template<typename Ty, typename base_type>
Ty stack<Ty, base_type>::min_value()
{
	if (!size())
		throw "No elements";
	stack<Ty, base_type> s_copy = *this;
	Ty min = s_copy.top();
	s_copy.pop();
	while (s_copy.size())
	{
		if (s_copy.top() < min)
			min = s_copy.top();
		s_copy.pop();
	}
	return min;
}


template<typename Ty, typename base_type>
Ty stack<Ty, base_type>::max_value()
{
	if (!size())
		throw "No elements";
	stack<Ty, base_type> s_copy = *this;
	Ty max = s_copy.top();
	s_copy.pop();
	while (s_copy.size())
	{
		if (s_copy.top() > max)
			max = s_copy.top();
		s_copy.pop();
	}
	return max;
}

template<typename Ty, typename base_type>
stack<Ty, base_type> stack<Ty, base_type>::create_reverse()
{
	stack<Ty, base_type> st = *this;
	stack<Ty, base_type> reversed;
	while (st.size())
	{
		reversed.push(st.top());
		st.pop();
	}
	return reversed;
}