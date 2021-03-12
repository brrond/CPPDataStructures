#include "dependencies.h"

using namespace std;

int main_lab3()
{
	cout << "Binary tree test" << 1431430 << endl;
	auto f = [](int n) {cout << n << " "; };
	
	// 100
	binary_tree_node<int> root(100);
	
	root.insert(99);
	root.insert(98);
	root.insert(98);
	root.insert(110);
	root.insert(108);
	root.insert(111);
	root.insert(103);
	root.insert(105);
	root.insert(105);
	root.insert(106);

	root.pre_order(f);
	cout << endl;

	cout << root.left->left->left->get_data();
	cout << endl;
	root.left->left->left->erase();

	root.left->left->erase();
	root.pre_order(f);
	cout << endl;

	root.right->left->left->erase();
	root.pre_order(f);
	cout << endl;

	cout << root.right->left->left->get_data();
	cout << endl;

	root.right->left->erase();
	cout << root.right->left->get_data() << endl;
	root.pre_order(f);
	cout << endl;
	cout << root.right->left->get_data() << endl;

	root.right->erase();
	root.pre_order(f);
	cout << endl;

	root.erase();
	root.pre_order(f);
	cout << endl;


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