#include "deque.h"

template<typename Ty, typename base_type>
deque<Ty, base_type>::deque() : base_type() {}

template<typename Ty, typename base_type>
deque<Ty, base_type>::deque(const deque& d) :
	base_type(static_cast<const base_type&>(d))
{
}

template<typename Ty, typename base_type>
bool deque<Ty, base_type>::is_empty()
{
	return !size();
}

template<typename Ty, typename base_type>
void deque<Ty, base_type>::clear()
{
	static_cast<circular_linked_list<Ty>&>(*this).clear();
}

template<typename Ty, typename base_type>
size_t deque<Ty, base_type>::size()
{
	return static_cast<base_type>(*this).size();
}

template<typename Ty, typename base_type>
void deque<Ty, base_type>::push_front(const Ty& val)
{
	static_cast<circular_linked_list<Ty>&>(*this).insert(val, 0);
}

template<typename Ty, typename base_type>
void deque<Ty, base_type>::push_back(const Ty& val)
{
	static_cast<circular_linked_list<Ty>&>(*this).push_back(val);
}

template<typename Ty, typename base_type>
void deque<Ty, base_type>::pop_front()
{
	static_cast<circular_linked_list<Ty>&>(*this).erase(0);
}

template<typename Ty, typename base_type>
void deque<Ty, base_type>::pop_back()
{
	static_cast<circular_linked_list<Ty>&>(*this).erase(size() - 1);
}

template<typename Ty, typename base_type>
Ty& deque<Ty, base_type>::front()
{
	return static_cast<circular_linked_list<Ty>&>(*this).operator[](0);
}

template<typename Ty, typename base_type>
Ty& deque<Ty, base_type>::back()
{
	if (size())
	{
		return *this->begin->prev->data;
		//return *static_cast<circular_linked_list<Ty>&>(*this).begin->prev->data;
	}
	throw "There is no elements";
}



template<typename Ty, typename base_type>
void deque<Ty, base_type>::insert(size_t index, Ty val)
{
	static_cast<base_type&>(*this).insert(val, index);
}

//template<typename Ty, typename base_type>
//Ty& deque<Ty, base_type>::operator[](size_t index)
//{
//	return static_cast<base_type>(*this).operator[](index);
//}



