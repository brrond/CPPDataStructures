#include "dependencies.h"

using namespace std;

int main_lab3()
{
	cout << "Binary tree test" << 1431430 << endl;
	auto f = [](int n) {cout << n << " "; };
	
	// 100
	binary_tree_node<int> root(100);
	
	for (int i = 95; i <= 105; i++)
	{
		if (i == 102)
			continue;
		root.insert(i);
	}

	root.pre_order(f);
	cout << endl;

	root.insert(102);
	root.pre_order(f);


	/*// 10 20
	root.left = new binary_tree_node<int>(10);
	root.right = new binary_tree_node<int>(20);

	// 100 200 | 300 400
	root.left->left = new binary_tree_node<int>(100);
	root.left->right = new binary_tree_node<int>(200);
	root.right->right = new binary_tree_node<int>(400);

	binary_tree_node<int> root2 = root;

	root2.set_data(1001);
	root2.pre_order(f);
	cout << endl;
	root2.post_order(f);
	cout << endl;
	root2.symmetric(f);
	cout << endl;
	//*/



	return 0;
}