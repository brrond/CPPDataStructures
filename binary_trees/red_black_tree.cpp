#include "red_black_tree.h"

template<typename T>
red_black_tree_node<T>::red_black_tree_node() :
	binary_tree_node<T>()
{

}

template<typename T>
red_black_tree_node<T>::red_black_tree_node(T data) :
	binary_tree_node<T>(data)
{

}

template<typename T>
red_black_tree_node<T>::red_black_tree_node(const red_black_tree_node& rbt) :
	binary_tree_node<T>(static_cast<const binary_tree_node&>(rbt))
{

}

template<typename T>
red_black_tree_node<T>::~red_black_tree_node()
{

}

template<typename T>
void red_black_tree_node<T>::insert(T data)
{
	red_black_tree_node* new_node = nullptr;
	bool insert_to_this = true;

	if (!this->data)
	{
		this->data = new T(data);
		new_node = this;
	}
	else if (data <= *this->data)
	{
		if (left)
		{
			left->insert(data); ///////
			insert_to_this = false;
		}
		else
		{
			left = new red_black_tree_node<T>(data);
			left->parent = this;
			new_node = left;
		}
	}
	else
	{
		if (right)
		{
			right->insert(data); /////////
			insert_to_this = false;
		}
		else
		{
			right = new red_black_tree_node<T>(data);
			right->parent = this;
			new_node = right;
		}
	}

	if (insert_to_this)
	{
		new_node->color = RED;
		insert_fixup(new_node);
	}

}

template<typename T>
red_black_tree_node<T>* red_black_tree_node<T>::grandparent(red_black_tree_node* rbt)
{
	if (rbt && rbt->parent)
		return rbt->parent->parent;
	return nullptr;
}

template<typename T>
red_black_tree_node<T>* red_black_tree_node<T>::uncle(red_black_tree_node* rbt)
{
	red_black_tree_node* g = grandparent(rbt);
	if (g)
	{
		if (rbt->parent == g->left)
			return g->right;
		else
			return  g->left;
	}
	return nullptr;
}

template<typename T>
red_black_tree_node<T>* red_black_tree_node<T>::sibling(red_black_tree_node* rbt)
{
	if (rbt == rbt->parent->left)
		return rbt->parent->right;
	return rbt->parent->left;
}

template<typename T>
void red_black_tree_node<T>::insert_fixup(red_black_tree_node* rbt)
{
	// First
	if (!rbt->parent)
		rbt->color = BLACK;
	else
	{
		// Second
		if (rbt->parent->color == BLACK)
			return;
		else
		{
			// Third
			red_black_tree_node<T>* u = uncle(rbt), * g;
			if (u && u->color == RED)
			{
				rbt->parent->color = BLACK;
				u->color = BLACK;
				g = grandparent(rbt);
				g->color = RED;
				insert_fixup(g);
			}
			else
			{
				// Fourth
				g = grandparent(rbt);
				if ((rbt == rbt->parent->right) &&
					(rbt->parent == g->left))
				{
					rotate_left(rbt->parent);
					rbt = rbt->left;
				}
				else if ((rbt == rbt->parent->left) &&
					(rbt->parent == g->right))
				{
					rotate_right(rbt->parent);
					rbt = rbt->right;
				}

				// Fifth
				rbt->parent->color = BLACK;
				g->color = RED;
				if ((rbt == rbt->parent->left) && 
					(rbt->parent == g->left)) {
					rotate_right(g);
				}
				else
				{
					rotate_left(g);
				}



			}
		}
	}
}

template<typename T>
void red_black_tree_node<T>::erase_fixup(red_black_tree_node* rbt)
{
	// First
	if (rbt->parent)
	{

		// SECOND
		red_black_tree_node<T>* s = sibling(rbt);

		if (s && s->color == RED)
		{
			rbt->parent->color = RED;
			s->color = BLACK;
			if (rbt == rbt->parent->left)
				rotate_left(rbt->parent);
			else
				rotate_right(rbt->parent);
		}

		// Third
		if (s &&
			(rbt->parent->color == BLACK) &&
			(s->color == BLACK))
		{
			s->color = RED;
			erase_fixup(rbt->parent);
		}
		else
		{
			// Fourth
			if (s && 
				(rbt->parent->color == RED) &&
				(s->color == BLACK)) {
				s->color = RED;
				rbt->parent->color = BLACK;
			}
			else
			{
				// Fifth
				if (s && s->color == BLACK)
				{
					if ((rbt == rbt->parent->left)) {
						s->color = RED;
						s->left->color = BLACK;
						rotate_right(s);
					}
					else if ((rbt == rbt->parent->right)) {
						s->color = RED;
						s->right->color = BLACK;
						rotate_left(s);
					}
				}


				// Sixth

				s->color = rbt->parent->color;
				rbt->parent->color = BLACK;

				if (rbt == rbt->parent->left)
				{
					s->right->color = BLACK;
					rotate_left(rbt->parent);
				}
				else
				{
					s->left->color = BLACK;
					rotate_right(rbt->parent);
				}
			}
		}
	}
}

template<typename T>
void red_black_tree_node<T>::erase()
{
	///*
	red_black_tree_node<T>* child = nullptr;
	if (left && right)
	{
		//if (right)
		//{
		//	child = static_cast<red_black_tree_node<T>*>(this->min(this->right));
		//	// child don't have left sb
		//	
		//	child->left = left;
		//	if (left)
		//		left->parent = child;
		//}
		//else if (left)
		//{
		//	child = static_cast<red_black_tree_node<T>*>(this->max(this->left));
		//	// here right is empty

		//	child->right = right;
		//	if (right)
		//		right->parent = child;
		//}
		//else
		//	child = nullptr;
		T tmp = *this->data;
		*this->data = *right->data;
		*right->data = tmp;
		right->erase();
		return;

	}
	else if (left)
	{
		child = left;
		//replace_node(this, child);
	}
	else if (right)
	{
		child = right;
		//replace_node(this, child);
	}
	else
	{
		/*if (parent)
		{
			if (parent->left == this)
			{
				parent->left = nullptr;
			}
			else
			{
				parent->right = nullptr;
			}
			erase_fixup(parent);
		}
		else
		{
			if (this->data)
				delete this->data;
		}*/
		// It's not working. I'm sure

		if (this->data)
		{
			delete this->data;
			this->data = nullptr;
		}

		if (parent)
		{
			erase_fixup(parent);
			if (parent->left == this)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		}
		//delete this; //
		return;
	}

	replace_node(this, child);
	if (color == BLACK)
	{
		if (child->color == RED)
			child->color = BLACK;
		else
			erase_fixup(child);
	}

	delete this; // I don't sure about that*/

	/*
	red_black_tree_node* x, * y;

	if (!data)
		return;

	if (!left || !right)
	{
		y = this;
	}
	else
	{
		y = right;
		while (y->left) y = y->left;
	}

	if (y->left)
		x = y->left;
	else
		x = y->right;

	x->parent = y->parent;
	if (y->parent)
		if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
	else
	{
		// root = x;
	}

	if (y != this) this->data = y->data;

	if (y->color == BLACK)
		erase_fixup(x);

	delete y;*/
}

template<typename T>
void red_black_tree_node<T>::rotate_left(red_black_tree_node* rbt)
{
	auto* y = rbt->right;

	if (!y)
		return;

	y->parent = rbt->parent;
	if (rbt->parent)
	{
		if (rbt->parent->left == rbt)
			rbt->parent->left = y;
		else
			rbt->parent->right = y;
	}

	rbt->right = y->left;
	if (y->left)
		y->left->parent = rbt;

	rbt->parent = y;
	y->left = rbt;
}

template<typename T>
void red_black_tree_node<T>::rotate_right(red_black_tree_node* rbt)
{
	red_black_tree_node* y = rbt->left;

	if (!y)
		return;

	y->parent = rbt->parent;
	if (rbt->parent)
	{
		if (rbt->parent->left == rbt)
			rbt->parent->left = y;
		else
			rbt->parent->right = y;
	}

	rbt->left = y->right;
	if (y->right)
		y->right->parent = rbt;

	rbt->parent = y;
	y->right = rbt;
}



template<typename T>
template<typename _Func>
void red_black_tree_node<T>::pre_order_with_color(_Func func)
{
	if (this->data)
		pre_order_with_color(this, func);
}

template<typename T>
template<typename _Func>
void red_black_tree_node<T>::post_order_with_color(_Func func)
{
	if (this->data)
		post_order_with_color(this, func);
}

template<typename T>
template<typename _Func>
void red_black_tree_node<T>::symmetric_with_color(_Func func)
{
	if (this->data)
		symmetric_with_color(this, func);
}

template<typename T>
template<typename _Func>
void red_black_tree_node<T>::pre_order_with_color(red_black_tree_node* rbt, _Func func)
{
	if (rbt)
	{
		func(*rbt->data, rbt->color);
		pre_order_with_color(rbt->left, func);
		pre_order_with_color(rbt->right, func);
	}
}

template<typename T>
template<typename _Func>
void red_black_tree_node<T>::post_order_with_color(red_black_tree_node* rbt, _Func func)
{
	if (rbt)
	{
		post_order_with_color(rbt->left, func);
		post_order_with_color(rbt->right, func);
		func(*rbt->data, rbt->color);
	}
}

template<typename T>
template<typename _Func>
inline void red_black_tree_node<T>::symmetric_with_color(red_black_tree_node* rbt, _Func func)
{
	if (rbt)
	{
		symmetric_with_color(rbt->left, func);
		func(*rbt->data, rbt->color);
		symmetric_with_color(rbt->right, func);
	}
}
