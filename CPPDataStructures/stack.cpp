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
void stack<Ty, base_type>::push_back(const Ty& data)
{
	static_cast<base_type&>(*this).insert(data, 0);
}

template<typename Ty, typename base_type>
void stack<Ty, base_type>::pop()
{
	static_cast<base_type&>(*this).erase(0);
}

template<typename Ty, typename base_type>
Ty& stack<Ty, base_type>::back()
{
	return static_cast<base_type&>(*this).operator[](0);
}
