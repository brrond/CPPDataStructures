#include "queue.h"

template<typename Ty, typename base_type>
queue<Ty, base_type>::queue() : base_type() {}

template<typename Ty, typename base_type>
queue<Ty, base_type>::queue(const queue& q) :
	linked_list<Ty>(static_cast<const base_type&>(q))
{

}

template<typename Ty, typename base_type>
void queue<Ty, base_type>::push(Ty val)
{
	static_cast<base_type&>(*this).push_back(val);
}

template<typename Ty, typename base_type>
void queue<Ty, base_type>::pop()
{
	static_cast<base_type&>(*this).erase(0);
}

template<typename Ty, typename base_type>
Ty& queue<Ty, base_type>::front()
{
	return static_cast<base_type&>(*this).operator[](0);
}

template<typename Ty, typename base_type>
size_t queue<Ty, base_type>::size()
{
	return static_cast<base_type>(*this).size();
}

template<typename Ty, typename base_type>
void queue<Ty, base_type>::clear()
{
	static_cast<base_type&>(*this).clear();
}

template<typename Ty, typename base_type>
Ty queue<Ty, base_type>::front_pop()
{
	if (!size()) throw "There is no elements";
	Ty val = front();
	pop();
	return val;
}