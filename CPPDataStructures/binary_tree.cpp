#include "binary_tree.h"

template<typename T>
binary_tree_node<T>::binary_tree_node()
{

}

template<typename T>
binary_tree_node<T>::binary_tree_node(T data)
{
	data = new T(data);
}

template<typename T>
binary_tree_node<T>::binary_tree_node(const binary_tree_node& btn)
{
	// I should do this one
}

template<typename T>
binary_tree_node<T>::~binary_tree_node()
{
	// And this one
}

template<typename T>
template<typename _Func>
void binary_tree_node<T>::pre_order(_Func func)
{
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
	symmetric(this, func);
}

template<typename T>
template<typename _Func>
void binary_tree_node<T>::symmetric(binary_tree_node* btn, _Func func)
{
	if (btn)
	{
		post_order(btn->left, func);
		func(*btn->data);
		post_order(btn->right, func);
	}
}

template<typename T>
T& binary_tree_node<T>::get_data()
{
	if (data)
		return data;
	throw "Node is empty";
}

template<typename T>
void binary_tree_node<T>::set_data(T data)
{
	this->data = new T(data);
}

template<typename T>
binary_tree_node<T>* binary_tree_node<T>::get_left()
{
	return left;
}

template<typename T>
binary_tree_node<T>* binary_tree_node<T>::get_right()
{
	return right;
}

