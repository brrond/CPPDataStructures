#pragma once
#include "binary_tree.h"

enum COLOR
{
	RED = 0,
	BLACK = 1
};

template <typename T>
class red_black_tree_node : public binary_tree_node<T> 
{
public:
	red_black_tree_node();
	red_black_tree_node(T data);
	red_black_tree_node(const red_black_tree_node& rbt);
	~red_black_tree_node();

	void insert(T data);

	template <typename _Func>
	void pre_order_with_color(_Func func);

	template <typename _Func>
	void post_order_with_color(_Func func);

	template <typename _Func>
	void symmetric_with_color(_Func func);

	template <typename _Func>
	static void pre_order_with_color(red_black_tree_node* rbt, _Func func);

	template <typename _Func>
	static void post_order_with_color(red_black_tree_node* rbt, _Func func);

	template <typename _Func>
	static void symmetric_with_color(red_black_tree_node* rbt, _Func func);

	void erase();

	static void rotate_left(red_black_tree_node* rbt);

	static void rotate_right(red_black_tree_node* rbt);

	size_t amount_of_leafs()
	{
		size_t l = 0, r = 0;
		if (left)
			l = left->amount_of_leafs();
		if (right)
			r = right->amount_of_leafs();
		return l + r + (1 ? (left == right && right == nullptr) : 0);
	}

	red_black_tree_node* left = nullptr;
	red_black_tree_node* right = nullptr;
	red_black_tree_node* parent = nullptr;

	COLOR color = RED;

protected:

	

	static red_black_tree_node* grandparent(red_black_tree_node* rbt);
	
	static red_black_tree_node* uncle(red_black_tree_node* rbt);

	static red_black_tree_node* sibling(red_black_tree_node* rbt);

	static void insert_fixup(red_black_tree_node* rbt);

	static void erase_fixup(red_black_tree_node* rbt);

	static void replace_node(red_black_tree_node* rbt,
		red_black_tree_node* rbt2)
	{
		rbt2->parent = rbt->parent;
		if (rbt->parent)
		{
			if (rbt == rbt->parent->left)
				rbt->parent->left = rbt2;
			else
				rbt->parent->right = rbt2;
		}

	}

	static red_black_tree_node* min(red_black_tree_node* r)
	{
		if (r->left)
			return min(r->left);
		return r;
	}

	static red_black_tree_node* max(red_black_tree_node* l)
	{
		if (l->right)
			return max(l->right);
		return l;
	}

private:
	void get_links_from_base()
	{
		binary_tree_node<T>* base = static_cast<binary_tree_node<T>*>(this);
		left = static_cast<red_black_tree_node<T>*>(base->left);
		right = static_cast<red_black_tree_node<T>*>(base->right);
		parent = static_cast<red_black_tree_node<T>*>(base->parent);
	}

	void set_links_to_base()
	{
		binary_tree_node<T>* base = static_cast<binary_tree_node<T>*>(this);
		base->left = static_cast<binary_tree_node<T>*>(left);
		base->right = static_cast<binary_tree_node<T>*>(right);
		base->parent = static_cast<binary_tree_node<T>*>(parent);
	}
};





#include "red_black_tree.cpp"
