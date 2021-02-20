#include "list.h"

template<typename Ty>
list<Ty>::list()
{
	begin = new node_t<Ty>;
}

template<typename Ty>
list<Ty>::list(const list& l)
{
	begin = new node_t<Ty>;
	node_t<Ty>* d = begin;
	for (node_t<Ty>* b = l.begin; b->next != nullptr; b = b->next)
	{
		d->data = new Ty(*b->data);
		d->next = new node_t<Ty>;
		d = d->next;
	}
}

template<typename Ty>
list<Ty>::~list()
{
	node_t<Ty>* pb = begin;
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
void list<Ty>::push_back(const Ty& value)
{
	node_t<Ty>* b = begin;
	while (b->next != nullptr)
		b = b->next;
	b->data = new Ty(value);
	b->next = new node_t<Ty>();
	b->next->next = nullptr;
}

template<typename Ty>
void list<Ty>::insert(const Ty& value, size_t index)
{
	node_t<Ty>* b = begin;
	if (index == 0)
	{
		node_t<Ty>* new_begin = new node_t<Ty>;
		new_begin->data = new Ty(value);
		new_begin->next = begin;
		begin = new_begin;
		return;
	}
	index--;
	while (index-- && b->next != nullptr)
		b = b->next;
	node_t<Ty>* new_el = new node_t<Ty>;
	new_el->data = new Ty(value);
	new_el->next = b->next;
	b->next = new_el;
}

template<typename Ty>
void list<Ty>::erase(size_t index)
{
	if (index == 0)
	{
		if (begin->data == nullptr)
			throw "Index out of range";

		node_t<Ty>* d = begin;
		begin = begin->next;
		delete d->data;
		delete d;
		return;
	}

	node_t<Ty>* b = begin;
	node_t<Ty>* pb = b;
	for (size_t i = 0; i < index; i++)
	{
		if (b->next == nullptr)
			throw "Index out of range";
		pb = b;
		b = b->next;
	}
	pb->next = b->next;
	delete b->data;
	delete b;
}

template<typename Ty>
void list<Ty>::clear()
{
	node_t<Ty>* pb = begin;
	while (begin->next != nullptr)
	{
		pb = begin;
		begin = begin->next;
		delete pb->data;
		delete pb;
	}
	delete begin;
	begin = new node_t<Ty>;
}

template<typename Ty>
size_t list<Ty>::size()
{
	size_t s = 0;
	for (node_t<Ty>* f = begin; f->next != nullptr; f = f->next, s++);
	return s;
}

template<typename Ty>
void list<Ty>::swap(size_t index)
{
	node_t<Ty>* b = begin;
	if (index == 0)
	{
		if (b->next == nullptr)
		{
			throw "There is no more elements";
		}

		node_t<Ty>* second = b->next;
		b->next = second->next;
		second->next = b;
		begin = second;
	}
	else
	{
		index--;
		while (index-- && b->next != nullptr)
		{
			b = b->next;
		}
		node_t<Ty>* first, * second;
		try
		{
			first = b->next;
			second = b->next->next;
		}
		catch (...)
		{
			throw "There are no more elements";
		}

		b->next = b->next->next;
		first->next = second->next;
		second->next = first;
	}
}

template<typename Ty>
void list<Ty>::swap(size_t index1, size_t index2)
{
	if (index1 == index2)
		return;
	node_t<Ty>* b = begin;
	node_t<Ty>* first, * second;
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
int64_t list<Ty>::find(const Ty& value)
{
	int64_t i = 0;
	for (node_t<Ty>* b = begin; b->next != nullptr; b = b->next, i++)
	{
		if ((*b->data) == value)
		{
			return i;
		}
	}
	return -1;
}

template<typename Ty>
Ty& list<Ty>::operator[](size_t index)
{
	node_t<Ty>* b = begin;
	size_t i = 0;
	for (; (i < index && b->next != nullptr); b = b->next, i++);
	if (i == index)
		return *b->data;
	throw "Index out of range";
}

template<typename Ty>
list<Ty> list<Ty>::operator+(const list& l2) 
{
	list<Ty> new_list;
	node_t<Ty>* b = new_list.begin;
	node_t<Ty>* b1 = this->begin;
	while (b1->next != nullptr)
	{
		b->data = new Ty(*b1->data);
		b->next = new node_t<Ty>;
		b = b->next;
		b1 = b1->next;
	}

	node_t<Ty>* b2 = l2.begin;
	while (b2->next != nullptr)
	{
		b->data = new Ty(*b2->data);
		b->next = new node_t<Ty>;
		b = b->next;
		b2 = b2->next;
	}
	return new_list;
}

template<typename Ty>
list<Ty>& list<Ty>::operator+=(const list& l2)
{
	node_t<Ty>* b = begin;
	while (b->next != nullptr)
		b = b->next;
	node_t<Ty>* b2 = l2.begin;
	while (b2->next != nullptr)
	{
		b->data = new Ty(*b2->data);
		b->next = new node_t<Ty>;
		b = b->next;
		b2 = b2->next;
	}
	return *this;
}

template <typename Ty>
std::ostream& operator<<(std::ostream& out, const list<Ty>& l)
{
	try
	{
		size_t i = 0;
		for (node_t<Ty>* f = l.begin; f->next != nullptr; f = f->next)
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
