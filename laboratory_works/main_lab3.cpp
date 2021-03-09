#include "dependencies.h"

using namespace std;

int main_lab3()
{
	binary_tree_node<int> root;
	root.set_data(100);

	root.pre_order([](int n) {cout << n << " "; });

	return 0;
}