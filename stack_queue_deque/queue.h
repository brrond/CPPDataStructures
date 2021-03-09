#pragma once
#include "../slist_llist_cllist/linked_list.h"

template<typename Ty, typename base_type = linked_list<Ty>>
class queue : protected base_type
{
public:
	queue();
	queue(const queue& q);
	~queue() {}

	void push(Ty val);
	void pop();
	Ty& front();

	size_t size();
	void clear();

	Ty front_pop();

	friend std::ostream& operator<<(std::ostream& out, queue q)
	{
		queue q2(q);
		while (q2.size())
		{
			out << q2.front() << " ";
			q2.pop();
		}
		return out;

		/*if (!q.size()) return out;
		Ty val = q.front();
		q.pop();
		out << q << val << " ";
		return out;*/
	}

protected:


private:

};


#include "queue.cpp"