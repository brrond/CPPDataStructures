#include "linked_list.h"

template<typename Ty>
linked_list<Ty>::linked_list()
{
	begin = new node_linked_t<Ty>;
}

template<typename Ty>
linked_list<Ty>::linked_list(const linked_list& l)
{
	begin = new node_linked_t<Ty>;
	node_linked_t<Ty>* d = begin;
	for (node_linked_t<Ty>* b = l.begin; b->next != nullptr; b = b->next)
	{
		d->data = new Ty(*b->data);
		d->next = new node_linked_t<Ty>;
		d->next->prev = d;
		d = d->next;
	}
}

template<typename Ty>
linked_list<Ty>::~linked_list()
{
	node_linked_t<Ty>* pb = begin;
	while (begin->next != nullptr)
	{
		pb = begin;
		begin = begin->next;
		delete pb->data;
		delete pb;
	}
	delete begin;
}

template<typename Ty>
void linked_list<Ty>::push_back(const Ty& value)
{
	node_linked_t<Ty>* b = begin;
	while (b->next != nullptr)
		b = b->next;
	b->data = new Ty(value);
	b->next = new node_linked_t<Ty>();
	b->next->next = nullptr;
	b->next->prev = b;
}

template<typename Ty>
void linked_list<Ty>::insert(const Ty& value, size_t index)
{
	node_linked_t<Ty>* b = begin;
	if (index == 0)
	{
		node_linked_t<Ty>* new_begin = new node_linked_t<Ty>;
		new_begin->data = new Ty(value);
		new_begin->next = begin;
		begin = new_begin;
		return;
	}
	while (index-- && b->next != nullptr)
		b = b->next;
	node_linked_t<Ty>* new_el = new node_linked_t<Ty>;
	new_el->next = b;
	new_el->prev = b->prev;
	b->prev = new_el;
	new_el->data = new Ty(value);
}

template<typename Ty>
void linked_list<Ty>::erase(size_t index)
{
	if (index == 0)
	{
		node_linked_t<Ty>* d = begin;
		begin = begin->next;
		begin->prev = nullptr;
		delete d->data;
		delete d;
		return;
	}

	node_linked_t<Ty>* b = begin;
	for (size_t i = 0; i < index; i++)
	{
		if (b->next == nullptr)
			throw "Index out of range";
		b = b->next;
	}
	//pb->next = b->next;
	b->prev->next = b->next;
	b->next->prev = b->prev;
	delete b->data;
	delete b;
}

template<typename Ty>
void linked_list<Ty>::clear()
{
	while (begin->next != nullptr)
	{
		begin = begin->next;
		delete begin->prev->data;
		delete begin->prev;
	}
	delete begin;
	begin = new node_linked_t<Ty>;
}

template<typename Ty>
size_t linked_list<Ty>::size()
{
	size_t s = 0;
	for (node_linked_t<Ty>* f = begin; f->next != nullptr; f = f->next, s++);
	return s;
}

template<typename Ty>
void linked_list<Ty>::swap(size_t index)
{
	swap(index, index + 1);
}

template<typename Ty>
void linked_list<Ty>::swap(size_t index1, size_t index2)
{
	if (index1 == index2)
		return;
	node_linked_t<Ty>* b = begin;
	node_linked_t<Ty>* first, * second;
	size_t f = index1 < index2 ? index1 : index2;
	size_t s = index1 < index2 ? index2 : index1;
	while (b->next != nullptr && f--)
	{
		b = b->next;
	}
	
	if (b->next == nullptr)
		throw "Index out of range";
	first = b;

	while (b->next != nullptr && s--)
	{
		b = b->next;
	}

	if (b->next == nullptr)
		throw "Index out of range";
	second = b;

	Ty* tmp = first->data;
	first->data = second->data;
	second->data = tmp;
}

template<typename Ty>
int64_t linked_list<Ty>::find(const Ty& value)
{
	int64_t i = 0;
	for (node_linked_t<Ty>* b = begin; b->next != nullptr; b = b->next, i++)
	{
		if ((*b->data) == value)
		{
			return i;
		}
	}
	return -1;
}

template<typename Ty>
Ty& linked_list<Ty>::operator[](size_t index)
{
	node_linked_t<Ty>* b = begin;
	size_t i = 0;
	for (; (i < index && b->next != nullptr); b = b->next, i++);
	if (i == index)
		return *b->data;
	throw "Index out of range";
}

template<typename Ty>
linked_list<Ty> linked_list<Ty>::operator+(const linked_list& l2) 
{
	linked_list<Ty> new_linked_list;
	node_linked_t<Ty>* b = new_linked_list.begin;
	node_linked_t<Ty>* b1 = this->begin;
	while (b1->next != nullptr)
	{
		b->data = new Ty(*b1->data);
		b->next = new node_linked_t<Ty>;
		b->next->prev = b;

		b = b->next;
		b1 = b1->next;
	}

	node_linked_t<Ty>* b2 = l2.begin;
	while (b2->next != nullptr)
	{
		b->data = new Ty(*b2->data);
		b->next = new node_linked_t<Ty>;
		b->next->prev = b;

		b = b->next;
		b2 = b2->next;
	}
	return new_linked_list;
}

template<typename Ty>
linked_list<Ty>& linked_list<Ty>::operator+=(const linked_list& l2)
{
	node_linked_t<Ty>* b = begin;
	while (b->next != nullptr)
		b = b->next;
	node_linked_t<Ty>* b2 = l2.begin;
	while (b2->next != nullptr)
	{
		b->data = new Ty(*b2->data);
		b->next = new node_linked_t<Ty>;
		b->next->prev = b;

		b = b->next;
		b2 = b2->next;
	}
	return *this;
}

template <typename Ty>
std::ostream& operator<<(std::ostream& out, const linked_list<Ty>& l)
{
	try
	{
		size_t i = 0;
		for (node_linked_t<Ty>* f = l.begin; f->next != nullptr; f = f->next)
		{
			out << i << ") " << f->data->c_str() << std::endl;
			i++;
		}
	}
	catch (...)
	{
		throw "There is no c_str() function";
	}

	return out;
}
