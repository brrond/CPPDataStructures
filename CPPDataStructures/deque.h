#pragma once

#include "../slist_llist_cllist/circular_linked_list.h"

template <typename Ty = int,
    typename base_type = circular_linked_list<Ty>>
class deque : circular_linked_list<Ty>
{
public:
    deque();
    deque(const deque& d);
    ~deque() {}

    bool is_empty();
    void clear();
    size_t size();
    void push_front(const Ty& val);
    void push_back(const Ty& val);
    void pop_front();
    void pop_back();
    Ty& front();
    Ty& back();

    void insert(size_t index, Ty val);

    Ty& operator[](size_t index)
    {
        return static_cast<base_type&>(*this).operator[](index);
    }

    friend std::ostream& operator<<(std::ostream& out, deque q)
    {
        while (q.size())
        {
            out << q.front() << " ";
            q.pop_front();
        }
        return out;
    }

protected:


private:


};

#include "deque.cpp"