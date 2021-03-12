#pragma once

template <typename T>
class binary_tree_node
{
public:
	binary_tree_node();
	binary_tree_node(T data);
	binary_tree_node(const binary_tree_node& btn);
	~binary_tree_node();

	void insert(T data);

	// For next three functions we pass some function func
	//and it'll work for every element
	
	template <typename _Func>
	void pre_order(_Func func);

	template <typename _Func>
	static void pre_order(binary_tree_node* btn, _Func func);

	template <typename _Func>
	void post_order(_Func func);

	template <typename _Func>
	static void post_order(binary_tree_node* btn, _Func func);

	template <typename _Func>
	void symmetric(_Func func);
	
	template <typename _Func>
	static void symmetric(binary_tree_node* btn, _Func func);

	void clear();

	void clear_left();
	void clear_right();

	void erase();

	T& get_data();
	void set_data(T data);

	//binary_tree_node* get_left();
	//binary_tree_node* get_right();

	binary_tree_node* left = nullptr;
	binary_tree_node* right = nullptr;
	binary_tree_node* parent = nullptr;

protected:
	//binary_tree_node* left = nullptr;
	//binary_tree_node* right = nullptr;
	
	static binary_tree_node* min(binary_tree_node*);

private:
	T* data = nullptr;
};

#include "binary_tree.cpp"
