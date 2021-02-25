#include "queue.h"

template<typename Ty, typename base_type>
queue<Ty, base_type>::queue() : linked_list<Ty>() {}

template<typename Ty, typename base_type>
queue<Ty, base_type>::queue(const queue& q) :
	linked_list<Ty>(static_cast<const linked_list<Ty>&>(q))
{

}

template<typename Ty, typename base_type>
void queue<Ty, base_type>::push(Ty val)
{
	static_cast<linked_list<Ty>&>(*this).push_back(val);
}

template<typename Ty, typename base_type>
void queue<Ty, base_type>::pop()
{
	static_cast<linked_list<Ty>&>(*this).erase(0);
}

template<typename Ty, typename base_type>
Ty& queue<Ty, base_type>::front()
{
	return static_cast<linked_list<Ty>&>(*this).operator[](0);
}

template<typename Ty, typename base_type>
size_t queue<Ty, base_type>::size()
{
	return static_cast<linked_list<Ty>>(*this).size();
}

template<typename Ty, typename base_type>
void queue<Ty, base_type>::clear()
{
	static_cast<linked_list<Ty>&>(*this).clear();
}

template<typename Ty, typename base_type>
Ty queue<Ty, base_type>::front_pop()
{
	if (!size()) throw "There is no elements";
	Ty val = front();
	pop();
	return val;
}