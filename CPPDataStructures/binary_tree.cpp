#include "binary_tree.h"

template<typename T>
binary_tree_node<T>::binary_tree_node()
{

}

template<typename T>
binary_tree_node<T>::binary_tree_node(T data)
{
	this->data = new T(data);
}

template<typename T>
binary_tree_node<T>::binary_tree_node(const binary_tree_node& btn)
{
	if (btn.data)
		data = new T(*btn.data);
	if (btn.left)
	{
		left = new binary_tree_node(*btn.left);
		left->parent = this;
	}
	if (btn.right)
	{
		right = new binary_tree_node(*btn.right);
		right->parent = this;
	}
}

template<typename T>
binary_tree_node<T>::~binary_tree_node()
{
	if (left)
		delete left;
	if (right)
		delete right;
	if (data)
		delete data;

	if (parent)
	{
		if (parent->left == this)
			parent->left = nullptr;
		else
			parent->right = nullptr;
	}
}

template<typename T>
binary_tree_node<T>* binary_tree_node<T>::insert(T data)
{
	if (!this->data) 
	{
		this->data = new T(data);
		return this;
	}

	if (data <= *this->data)
	{
		if (left)
		{
			return left->insert(data);
		}
		left = new binary_tree_node<T>(data);
		left->parent = this;
		return left;
	}
	else
	{
		if (right)
		{
			return right->insert(data);
		}
		right = new binary_tree_node<T>(data);
		right->parent = this;
		return right;
	}
}

template<typename T>
template<typename _Func>
void binary_tree_node<T>::pre_order(_Func func)
{
	if(data)
		pre_order(this, func);
}

template<typename T>
template<typename _Func>
void binary_tree_node<T>::pre_order(binary_tree_node* btn, _Func func)
{
	if (btn)
	{
		func(*btn->data);
		pre_order(btn->left, func);
		pre_order(btn->right, func);
	}
}

template<typename T>
template<typename _Func>
void binary_tree_node<T>::post_order(_Func func)
{
	if(data)
		post_order(this, func);
}

template<typename T>
template<typename _Func>
void binary_tree_node<T>::post_order(binary_tree_node* btn, _Func func)
{
	if (btn)
	{
		post_order(btn->left, func);
		post_order(btn->right, func);
		func(*btn->data);
	}
}

template<typename T>
template<typename _Func>
void binary_tree_node<T>::symmetric(_Func func)
{
	if(data)
		symmetric(this, func);
}

template<typename T>
template<typename _Func>
void binary_tree_node<T>::symmetric(binary_tree_node* btn, _Func func)
{
	if (btn)
	{
		symmetric(btn->left, func);
		func(*btn->data);
		symmetric(btn->right, func);
	}
}

template<typename T>
void binary_tree_node<T>::clear()
{
	if (left)
	{
		left->clear();
		left = nullptr;
	}
	if (right)
	{
		right->clear();
		right = nullptr;
	}
	if (data)
	{
		delete data;
		data = nullptr;
	}

	if (parent)
	{
		if (parent->left == this)
			parent->left = nullptr;
		else
			parent->right = nullptr;
	}
}

template<typename T>
void binary_tree_node<T>::clear_left()
{
	if (left)
		left->clear();
	left = nullptr;
}

template<typename T>
void binary_tree_node<T>::clear_right()
{
	if (right)
		right->clear();
	right = nullptr;
}

template<typename T>
void binary_tree_node<T>::erase()
{
	if (!data)
		return;

	if (left == nullptr && right == nullptr)
	{
		if (data)
		{
			delete data;
			data = nullptr;
		}
		if (parent)
		{
			if (parent->left == this)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		}
	}
	else if (left == nullptr)
	{
		if (data)
			delete data;
		//data = new T(*right->data);
		if (parent)
		{
			right->parent = parent;
			if (parent->left == this)
				parent->left = right;
			else
				parent->right = right;
		}
		else
		{
			data = new T(*right->data);
			binary_tree_node* tmp = right;
			left = right->left;
			right = right->right;
			tmp->left = nullptr;
			tmp->right = nullptr;
			tmp->parent = nullptr;
			tmp->erase();

			if (right)
				right->parent = this;
			if (left)
				left->parent = this;


		}
	}
	else if (right == nullptr)
	{
		//if (data)
		//	delete data;
		//binary_tree_node* tmp = left;
		//data = new T(*left->data);
		//right = left->right;
		//left = left->left;
		//tmp->left = nullptr;
		//tmp->right = nullptr;
		//delete tmp;
		if (data)
			delete data;
		//data = new T(*right->data);
		if (parent)
		{
			left->parent = parent;
			if (parent->left == this)
				parent->left = left;
			else
				parent->right = left;
		}
		else
		{
			data = new T(*left->data);
			binary_tree_node* tmp = left;
			right = left->right;
			left = left->left;
			tmp->left = nullptr;
			tmp->right = nullptr;
			tmp->parent = nullptr;
			tmp->erase();

			if (right)
				right->parent = this;
			if (left)
				left->parent = this;
				
		}
	}
	else
	{
		binary_tree_node* tmp = nullptr;
		if (right)
			tmp = min(this->right);
		else if (left)
			tmp = max(this->left);
		else
			tmp = nullptr;
		if (tmp)
		{
			data = new T(*tmp->data);
			tmp->erase();
		}
		else
			data = nullptr;
	}

}

template<typename T>
T& binary_tree_node<T>::get_data()
{
	if (data)
		return *data;
	throw "Node is empty";
}

template<typename T>
void binary_tree_node<T>::set_data(T data)
{
	if (this->data)
		delete this->data;
	this->data = new T(data);
}

template<typename T>
size_t binary_tree_node<T>::amount_of_leafs()
{
	size_t l = 0, r = 0;
	if (left)
		l = left->amount_of_leafs();
	if (right)
		r = right->amount_of_leafs();
	return l + r + (1 ? (left == right && right == nullptr) : 0);
}

template<typename T>
binary_tree_node<T>* binary_tree_node<T>::min(binary_tree_node* r)
{
	if (r->left)
		return min(r->left);
	return r;
}

template<typename T>
binary_tree_node<T>* binary_tree_node<T>::max(binary_tree_node* l)
{
	if (l->right)
		return max(l->right);
	return l;
}

//template<typename T>
//binary_tree_node<T>* binary_tree_node<T>::get_left()
//{
//	return left;
//}
//
//template<typename T>
//binary_tree_node<T>* binary_tree_node<T>::get_right()
//{
//	return right;
//}

