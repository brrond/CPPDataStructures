#include "circular_linked_list.h"

template<typename Ty>
circular_linked_list<Ty>::circular_linked_list()
{
	begin = new node_circular_linked_t<Ty>;
}

template<typename Ty>
circular_linked_list<Ty>::circular_linked_list(const circular_linked_list& l)
{
	begin = new node_circular_linked_t<Ty>;
	if (!l.begin->data) return;
	node_circular_linked_t<Ty>* d = begin;
	bool first = true;
	for (node_circular_linked_t<Ty>* b = l.begin; (b != l.begin || first); b = b->next)
	{
		first = false;
		d->data = new Ty(*b->data);
		d->next = new node_circular_linked_t<Ty>;
		d->next->prev = d;
		d = d->next;
	}
	d->prev->next = begin;
	begin->prev = d->prev;
	delete d;
}

template<typename Ty>
circular_linked_list<Ty>::~circular_linked_list()
{
	node_circular_linked_t<Ty>* p = begin->prev;
	node_circular_linked_t<Ty>* pb;
	while (p != begin)
	{
		pb = p;
		p = p->prev;
		delete pb->data;
		delete pb;
	}
	delete begin->data;
	delete begin;
}

template<typename Ty>
void circular_linked_list<Ty>::push_back(const Ty& value)
{
	if (begin->data == nullptr)
	{
		begin->data = new Ty(value);
		return;
	}
	node_circular_linked_t<Ty>* new_node = new node_circular_linked_t<Ty>;
	new_node->data = new Ty(value);
	new_node->next = begin;
	new_node->prev = begin->prev;

	begin->prev->next = new_node;
	begin->prev = new_node;
}

template<typename Ty>
void circular_linked_list<Ty>::insert(const Ty& value, size_t index)
{
	node_circular_linked_t<Ty>* b = begin;

	if (index == 0 && begin->data == nullptr)
	{
		begin->data = new Ty(value);
		return;
	}

	if (index == 0)
	{
		node_circular_linked_t<Ty>* new_begin = new node_circular_linked_t<Ty>;
		new_begin->data = new Ty(value);

		new_begin->next = begin;
		new_begin->prev = begin->prev;
		new_begin->prev->next = new_begin;
		begin->prev = new_begin;
		
		begin = new_begin;
		return;
	}
	bool first = true;
	while (index-- && (b != begin || first))
	{
		b = b->next;
		first = false;
	}
	node_circular_linked_t<Ty>* new_el = new node_circular_linked_t<Ty>;
	new_el->next = b;
	new_el->prev = b->prev;
	b->prev = new_el;
	new_el->prev->next = new_el;
	new_el->data = new Ty(value);
}

template<typename Ty>
void circular_linked_list<Ty>::erase(size_t index)
{
	if (index == 0 && begin->data == nullptr)
		return;

	if (index == 0 && begin->next == begin)
	{
		delete begin->data;
		delete begin;
		begin = new node_circular_linked_t<Ty>;
		return;
	}

	if (index == 0)
	{
		node_circular_linked_t<Ty>* d = begin;
		begin = begin->next;
		begin->prev = d->prev;
		d->prev->next = begin;
		delete d->data;
		delete d;

		if (!begin)
			begin = new node_circular_linked_t<Ty>;
		return;
	}

	node_circular_linked_t<Ty>* b = begin;
	bool first = true;
	for (size_t i = 0; i < index; i++)
	{
		if (b == begin && !first)
			throw "Index out of range";
		first = false;
		b = b->next;
	}
	//pb->next = b->next;
	b->prev->next = b->next;
	b->next->prev = b->prev;
	delete b->data;
	delete b;
}

template<typename Ty>
void circular_linked_list<Ty>::clear()
{
	node_circular_linked_t<Ty>* p = begin->prev;
	node_circular_linked_t<Ty>* pb;
	while (p != begin)
	{
		pb = p;
		p = p->prev;
		delete pb->data;
		delete pb;
	}
	delete begin;
	begin = new node_circular_linked_t<Ty>;
}

template<typename Ty>
size_t circular_linked_list<Ty>::size()
{
	if (begin->data == nullptr)
		return 0;
	size_t s = 0;
	bool first = true;
	for (node_circular_linked_t<Ty>* f = begin; 
		f != begin || first; 
		f = f->next, s++, first = false);
	return s;
}

template<typename Ty>
void circular_linked_list<Ty>::swap(size_t index)
{
	swap(index, index + 1);
}

template<typename Ty>
void circular_linked_list<Ty>::swap(size_t index1, size_t index2)
{
	if (index1 == index2)
		return;
	node_circular_linked_t<Ty>* b = begin;
	node_circular_linked_t<Ty>* first, * second;
	size_t f = index1 < index2 ? index1 : index2;
	size_t s = index1 < index2 ? index2 : index1;
	s -= f;
	bool first_i = true;
	while ((b != begin || first_i) && f--)
	{
		first_i = false;
		b = b->next;
	}
	
	if (b == begin && f+1 != 0)
		throw "Index out of range";
	first = b;

	first_i = true;
	while ((b != begin || first_i) && s--)
	{
		first_i = false;
		b = b->next;
	}

	if (b == begin && s+1 != 0)
		throw "Index out of range";
	second = b;

	Ty* tmp = first->data;
	first->data = second->data;
	second->data = tmp;
}

template<typename Ty>
int64_t circular_linked_list<Ty>::find(const Ty& value)
{
	int64_t i = 0;
	bool first = true;
	for (node_circular_linked_t<Ty>* b = begin; (b != begin || first);
		b = b->next, i++, first = false)
	{
		if ((*b->data) == value)
		{
			return i;
		}
	}
	return -1;
}

template<typename Ty>
Ty& circular_linked_list<Ty>::operator[](size_t index)
{
	node_circular_linked_t<Ty>* b = begin;
	size_t i = 0;
	bool first = true;
	for (; (i < index && (b != begin || first)); b = b->next, i++, first = false);
	if (i == index)
		return *b->data;
	throw "Index out of range";
}

template<typename Ty>
circular_linked_list<Ty> circular_linked_list<Ty>::operator+(const circular_linked_list& l2) 
{
	circular_linked_list<Ty> new_circular_linked_list;
	node_circular_linked_t<Ty>* b1 = this->begin;
	bool first = true;
	if (begin->data != nullptr)
	{
		while (b1 != begin || first)
		{
			first = false;
			if (new_circular_linked_list.begin->data == nullptr)
			{
				new_circular_linked_list.begin->data = new Ty(*b1->data);
				b1 = b1->next;
				continue;
			}

			node_circular_linked_t<Ty>* new_node = new node_circular_linked_t<Ty>;
			new_node->data = new Ty(*b1->data);
			new_node->prev = new_circular_linked_list.begin->prev;
			new_node->next = new_circular_linked_list.begin;
			new_node->prev->next = new_node;
			new_node->next->prev = new_node;

			b1 = b1->next;
		}
	}

	node_circular_linked_t<Ty>* b2 = l2.begin;
	first = true;
	if (l2.begin->data != nullptr)
	{
		while (b2 != l2.begin || first)
		{
			first = false;
			if (new_circular_linked_list.begin->data == nullptr)
			{
				new_circular_linked_list.begin->data = new Ty(*b2->data);
				b2 = b2->next;
				continue;
			}

			node_circular_linked_t<Ty>* new_node = new node_circular_linked_t<Ty>;
			new_node->data = new Ty(*b2->data);
			new_node->prev = new_circular_linked_list.begin->prev;
			new_node->next = new_circular_linked_list.begin;
			new_node->prev->next = new_node;
			new_node->next->prev = new_node;

			b2 = b2->next;
		}
	}
	return new_circular_linked_list;
}

template<typename Ty>
circular_linked_list<Ty>& circular_linked_list<Ty>::operator+=(const circular_linked_list& l2)
{
	if (l2.begin->data == nullptr)
		throw "List must be not empty";

	node_circular_linked_t<Ty>* b = begin->prev;
	node_circular_linked_t<Ty>* b2 = l2.begin;
	bool first = true;
	while (b2 != l2.begin || first)
	{
		first = false;
		if (begin->data == nullptr)
		{
			begin->data = new Ty(*b2->data);
			b2 = b2->next;
			continue;
		}
		node_circular_linked_t<Ty>* new_node = new node_circular_linked_t<Ty>;
		new_node->data = new Ty(*b2->data);
		new_node->next = begin;
		new_node->prev = begin->prev;
		begin->prev->next = new_node;
		begin->prev = new_node;

		b2 = b2->next;
	}
	return *this;
}

template <typename Ty>
std::ostream& operator<<(std::ostream& out, const circular_linked_list<Ty>& l)
{
	if (l.begin->data == nullptr)
		return out;
	try
	{
		size_t i = 0;
		bool first = true;
		for (node_circular_linked_t<Ty>* f = l.begin; 
			f != l.begin || first; f = f->next, first = false)
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
