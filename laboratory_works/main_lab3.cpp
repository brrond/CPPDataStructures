#include "dependencies.h"

using namespace std;

struct student
{
	string name;
	int number;
	int group;

	student()
	{
		name = "";
		number = 10;
		group = 5;
	}

	student(string n, int num, int g)
	{
		name = n;
		number = num;
		group = g;
	}

	student(const student& st)
	{
		name = st.name;
		number = st.number;
		group = st.group;
	}

	~student()
	{

	}

	bool operator<(student st2)
	{
		return name < st2.name;
	}

	bool operator>(student st2)
	{
		return name > st2.name;
	}

	bool operator<=(student st2)
	{
		return name <= st2.name;
	}

	bool operator>=(student st2)
	{
		return name > st2.name;
	}

	bool operator==(student st2)
	{
		return name == st2.name;
	}
};

struct superstudent : student
{

	superstudent(string n, int num, int g) : student(n, num, g) {}
	superstudent() : student() {}
	superstudent(const superstudent& ss) : student(static_cast<const student&>(ss)) {}
	superstudent(student s) : student(s) {}

	bool operator<(superstudent ss)
	{
		return number < ss.number;
	}

	bool operator>(superstudent ss)
	{
		return number > ss.number;
	}

	bool operator<=(superstudent ss)
	{
		return number <= ss.number;
	}

	bool operator>=(superstudent ss)
	{
		return number >= ss.number;
	}

	bool operator==(superstudent ss)
	{
		return number == ss.number;
	}

};

void print(binary_tree_node<student> *temp, int l) {
	if (temp != nullptr) {
		print(temp->right, l + 1);
		try {
			for (int i = 0; i < l; i++) cout << "        ";
			printf("%5s", temp->get_data().name.c_str());
			cout << endl;
			for (int i = 0; i < l; i++) cout << "        ";
			printf("%5d", temp->get_data().number);
			cout << endl;
			for (int i = 0; i < l; i++) cout << "        ";
			printf("%5d", temp->get_data().group);
			cout << endl;
		}
		catch (...)
		{
			cout << endl;
		}
		print(temp->left, l + 1);
	}
	else
		cout << endl;
}

void elegant_print(binary_tree_node<student>* tmp, int l, FILE* f = nullptr)
{
	bool del_file = false;
	if (f == nullptr) 
	{
		del_file = true;
		f = fopen("special_tree.txt", "w");
	}

	if (tmp != nullptr) {
		elegant_print(tmp->right, l + 1, f);
		try {
			//fprintf(f, )
			for (int i = 0; i < l; i++)fprintf(f, "        ");
			fprintf(f, "%5s\n", tmp->get_data().name.c_str());
			for (int i = 0; i < l; i++) fprintf(f, "        ");
			fprintf(f, "%5d\n", tmp->get_data().number);
			for (int i = 0; i < l; i++) fprintf(f, "        ");
			fprintf(f, "%5d\n", tmp->get_data().group);
		}
		catch (...)
		{

		}
		elegant_print(tmp->left, l + 1, f);
	}
	else
		fprintf(f, "\n");

	if (del_file)
	{
		fclose(f);
	}
}

void print(binary_tree_node<superstudent>* temp, int l) {
	if (temp != nullptr) {
		print(temp->right, l + 1);
		try {
			for (int i = 0; i < l; i++) cout << "        ";
			printf("%5s", temp->get_data().name.c_str());
			cout << endl;
			for (int i = 0; i < l; i++) cout << "        ";
			printf("%5d", temp->get_data().number);
			cout << endl;
			for (int i = 0; i < l; i++) cout << "        ";
			printf("%5d", temp->get_data().group);
			cout << endl;
		}
		catch (...)
		{
			cout << endl;
		}
		print(temp->left, l + 1);
	}
	else
		cout << endl;
}

void print(red_black_tree_node<student>* temp, int l) {
	if (temp != nullptr) 
	{
		print(temp->right, l + 1);
		try {
			for (int i = 0; i < l; i++) cout << "        ";
			if (temp->color == 0) {
				cout << "R  ";
			}
			else {
				cout << "B  ";
			}
			printf("%5s", temp->get_data().name.c_str());
			cout << endl;
			for (int i = 0; i < l; i++) cout << "        ";
			printf("%5d", temp->get_data().number);
			cout << endl;
			for (int i = 0; i < l; i++) cout << "        ";
			printf("%5d", temp->get_data().group);
			cout << endl;
		}
		catch (...)
		{
			cout << endl;
		}
		print(temp->left, l + 1);
	}
	else
		cout << endl;
}

int main_lab3_binary_search_tree()
{
	cout << "Binary tree test" << 1431430 << endl;
	auto print_function = [](student st)
	{
		cout << st.name << " " << st.number << " " << st.group << endl;
	};


	/*
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
	*/

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

	binary_tree_node<student> root;
	root.insert({ "John Kalligan", 111, 101 });
	root.insert({ "Frank Malcow", 112, 101 });
	root.insert({ "SuperDuude", 110, 102 });
	root.insert({ "SuperWoman", 90, 102 });

	binary_tree_node<superstudent> root2;

	bool cmp_by_number = false;

	do
	{
		cout << "Ok, tree is (forward) : " << endl;
		if (cmp_by_number)
			root2.pre_order(print_function);
		else
			root.pre_order(print_function);

		cout << "1) Avg by  number" << endl;
		cout << "2) Print in backward" << endl;
		cout << "3) Print in symmetric" << endl;
		cout << "4) Amount of leafs " << endl;
		cout << "5) Clear" << endl;
		cout << "6) Clear left tree" << endl;
		cout << "7) Clear right tree" << endl;
		cout << "8) Delete root" << endl;
		if (!cmp_by_number)
			cout << "9) Compare by number" << endl;
		else
			cout << "9) Compare by name" << endl;
		cout << "10) Insert student" << endl;
		cout << "11) Write to file" << endl;
		cout << "12) Read from file" << endl;
		cout << "13) Write to file but elegant" << endl;


		if (!cmp_by_number)
		{
			print(&root, 0);
		}
		else
		{
			print(&root2, 0);
		}

		cout << ">>>";
		string menu_string;
		int menu;

		try
		{
			cin >> menu_string;
			if (menu_string == "exit")
				return 0;
			else if (menu_string == "clear" || menu_string == "cls")
			{
				system("cls");
				continue;
			}

			menu = stoi(menu_string);
		}
		catch (...)
		{
			cout << "Try again" << endl;
			continue;
		}

		if (menu == 1)
		{
			int avg = 0;
			int amount = 0;
			if (cmp_by_number)
				root2.pre_order([&avg, &amount](student st) {
				amount++;
				avg += st.number; });
			else
				root.pre_order([&avg, &amount](student st) {
				amount++;
				avg += st.number; });
			//root.pre_order([&avg, &amount](student st) {
			//	amount++; 
			//	avg += st.number; });

			cout << "Avg : " << avg / (float)amount << endl;
		}
		else if (menu == 2)
		{
			if (cmp_by_number)
				root2.post_order(print_function);
			else
				root.post_order(print_function);
			//root.post_order(print_function);
		}
		else if (menu == 3)
		{
			if (cmp_by_number)
				root2.symmetric(print_function);
			else
				root.symmetric(print_function);
			//root.symmetric(print_function);
		}
		else if (menu == 4)
		{
			size_t aol = 0;
			if (cmp_by_number)
				aol = root2.amount_of_leafs();
			else
				aol = root.amount_of_leafs();
			cout << "Leafs : " << aol << endl;
		}
		else if (menu == 5)
		{
			if (cmp_by_number)
				root2.clear();
			else
				root.clear();
			//root.clear();
			cout << "Done" << endl;
		}
		else if (menu == 6)
		{
			if (cmp_by_number)
				root2.clear_left();
			else
				root.clear_left();
			//root.clear_left();
			cout << "Done" << endl;
		}
		else if (menu == 7)
		{
			if (cmp_by_number)
				root2.clear_right();
			else
				root.clear_right();
			//root.clear_right();
			cout << "Done" << endl;
		}
		else if (menu == 8)
		{
			if (cmp_by_number)
				root2.erase();
			else
				root.erase();
			//root.erase();
			cout << "Done" << endl;
		}
		else if (menu == 9 && !cmp_by_number)
		{
			cmp_by_number = true;
			do
			{
				try
				{
					root2.insert({ root.get_data() });
					root.erase();
				}
				catch (...)
				{
					break;
				}

			} while (true);

			cout << "Ok" << endl;
		}
		else if (menu == 9 && cmp_by_number)
		{
			cmp_by_number = false;
			do
			{
				try
				{
					root.insert({ root2.get_data() });
					root2.erase();
				}
				catch (...)
				{
					break;
				}

			} while (true);

			cout << "Ok" << endl;
		}
		else if (menu == 10)
		{
			if (cmp_by_number)
			{
				superstudent ss;
				cout << "Enter student name : "; cin >> ss.name;
				cout << "Enter student number : "; cin >> ss.number;
				cout << "Enter student group : "; cin >> ss.group;
				root2.insert(ss);
			}
			else
			{
				student s;
				cout << "Enter student name : "; cin >> s.name;
				cout << "Enter student number : "; cin >> s.number;
				cout << "Enter student group : "; cin >> s.group;
				root.insert(s);
			}
			cout << "Done" << endl;
		}
		else if (menu == 11) 
		{
			if (cmp_by_number)
			{
				int size = 0;
				root.pre_order([ &size ](student st) { size++; });
				fstream fout;
				fout.open("file.txt");
				fout << size << endl;
				root.pre_order([&fout](superstudent st) {
					fout << st.name << endl << st.number << endl << st.group << endl;
					});
				fout.close();
			}
			else
			{
				int size = 0;
				root.pre_order([ &size ](student st) { size++; });
				fstream fout;
				fout.open("file.txt");
				fout << size << endl;
				root.pre_order([&fout](student st) {
					fout << st.name << endl << st.number << endl << st.group << endl;
					});
				fout.close();
			}
		}
		else if (menu == 12)
		{
			if (cmp_by_number)
			{
				ifstream fin;
				fin.open("file.txt");
				superstudent tmp;
				int size;
				string tmp_str;
				fin >> tmp_str;
				size = stoi(tmp_str);
				getline(fin, tmp_str);
				while (size--)
				{
					getline(fin, tmp.name);
					fin >> tmp.number >> tmp.group;
					getline(fin, tmp_str);
					root2.insert(tmp);
				}
				fin.close();
			}
			else
			{
				ifstream fin;
				fin.open("file.txt");
				student tmp;
				int size;
				string tmp_str;
				fin >> tmp_str;
				size = stoi(tmp_str);
				getline(fin, tmp_str);
				while(size--)
				{
					getline(fin, tmp.name);
					fin >> tmp.number >> tmp.group;
					getline(fin, tmp_str);
					root.insert(tmp);
				}
				fin.close();
			}

		}
		else if (menu == 13)
		{
		elegant_print(&root, 0);
		}



		cout << endl;
	} 	while (true);


	return 0;
}

int main_lab3_red_black_tree()
{
	cout << "Test" << 11 << endl;
	
	/*
	else if (menu == 11) 
		{
			if (cmp_by_number)
			{
				int size = 0;
				root.pre_order([ &size ](student st) { size++; });
				fstream fout;
				fout.open("file.txt");
				fout << size << endl;
				root.pre_order([&fout](superstudent st) {
					fout << st.name << endl << st.number << endl << st.group << endl;
					});
				fout.close();
			}
			else
			{
				int size = 0;
				root.pre_order([ &size ](student st) { size++; });
				fstream fout;
				fout.open("file.txt");
				fout << size << endl;
				root.pre_order([&fout](student st) {
					fout << st.name << endl << st.number << endl << st.group << endl;
					});
				fout.close();
			}
		}
		else if (menu == 12)
		{
			if (cmp_by_number)
			{
				ifstream fin;
				fin.open("file.txt");
				superstudent tmp;
				int size;
				string tmp_str;
				fin >> tmp_str;
				size = stoi(tmp_str);
				getline(fin, tmp_str);
				while (size--)
				{
					getline(fin, tmp.name);
					fin >> tmp.number >> tmp.group;
					getline(fin, tmp_str);
					root.insert(tmp);
				}
				fin.close();
			}
			else
			{
				ifstream fin;
				fin.open("file.txt");
				student tmp;
				int size;
				string tmp_str;
				fin >> tmp_str;
				size = stoi(tmp_str);
				getline(fin, tmp_str);
				while(size--)
				{
					getline(fin, tmp.name);
					fin >> tmp.number >> tmp.group;
					getline(fin, tmp_str);
					root.insert(tmp);
				}
				fin.close();
			}

		}
	*/

	/*red_black_tree_node<int>* root = new red_black_tree_node<int>();
	//root->insert(100);
	//root->insert(120);
	//root->insert(140);
	//root->insert(90);
	
	while (root->parent)
	{
		root = root->parent;
	}

	root->pre_order_with_color([](int a, COLOR cl) 
		{cout << a << " " << cl << endl; });

	//root->insert(110);
	//root->pre_order_with_color([](int a, COLOR cl)
	//	{cout << a << " " << cl << endl; });
	
	//root->left->left->erase();
	//auto* tmp = root->left;
	//root->erase();
	
	//root = tmp;
	//root->insert(100);

	//root->right->erase(); // B0
	//root->left->right->erase(); // R0 (110)
	//root->left->erase(); // b1
	//root->left->erase(); // b2 with 110

	// special insert
	root->insert(120);
	root->insert(140);
	root->insert(120);
	root->insert(150);
	root->insert(130);
	root->insert(125);
	root->insert(110);
	root->insert(122);

	//root->right->erase();
	root->right->left->erase();

	cout << "Final : " << endl;
	root->pre_order_with_color([](int a, COLOR cl)
		{cout << a << " " << cl << endl; });
	//*/

	auto print_function = [](student st, COLOR cl) {

		cout << st.name << " " << st.number << " " << st.group;
		cout << " ";
		if (cl == BLACK)
		{
			cout << "BLACK" << endl;
		}
		else
		{
			cout << "RED" << endl;
		}

	};

	red_black_tree_node<student> *root = new red_black_tree_node<student>;

	root->insert({ "John Kalligan", 111, 101 });
	root->insert({ "Frank Malcow", 112, 101 });
	root->insert({ "SuperDuude", 110, 102 });
	root->insert({ "SuperWoman", 90, 102 });

	string menu_string;
	int menu_int;

	do
	{
		cout << "Tree is : " << endl;
		root->pre_order_with_color(print_function);
		cout << "1) Print in backward" << endl;
		cout << "2) Print in symmetric" << endl;
		cout << "3) Amount of leafs " << endl;
		cout << "4) Insert student" << endl;
		cout << "5) Erase root" << endl;
		cout << "6) Write to file" << endl;
		cout << "7) Read from file" << endl;

		print(root, 0);

		cout << ">>>";

		try
		{
			cin >> menu_string;
			if (menu_string == "exit")
				return 0;
			else if (menu_string == "cls" || menu_string == "clear")
			{
				system("cls");
				continue;
			}

			menu_int = stoi(menu_string);
		}
		catch (...)
		{
			cout << "Nope" << endl;
			continue;
		}

		if (menu_int == 1)
		{
			root->post_order_with_color(print_function);
			cout << "Done" << endl;
		}
		else if (menu_int == 2)
		{
			root->symmetric_with_color(print_function);
			cout << "Done" << endl;
		}
		else if (menu_int == 3)
		{
			cout << "Amount of leafs : " << root->amount_of_leafs() << endl;
		}
		else if (menu_int == 4)
		{
			student st;
			cout << "Enter student name : ";
			getline(cin, menu_string);
			getline(cin, st.name);
			cout << "Enter student number : ";
			cin >> st.number;
			cout << "Enter student gorup : ";
			cin >> st.group;
			root->insert(st);
		}
		else if (menu_int == 5)
		{
			if (root->left || root->right)
			{
				red_black_tree_node<student>* tmp = 
					(root->left) ? root->left : root->right;
				root->erase();
				root = tmp;
				while (root->parent)
				{
					root = root->parent;
				}
			}
			else
			{
				root->erase();
			}
		}
		else if (menu_int == 6)
		{
			int size = 0;
			root->pre_order([&size](student st) { size++; });
			fstream fout;
			fout.open("file.txt");
			fout << size << endl;
			root->pre_order([&fout](student st) {
				fout << st.name << endl << st.number << endl << st.group << endl;
				});
			fout.close();
		}
		else if (menu_int == 7)
		{
			ifstream fin;
			fin.open("file.txt");
			student tmp;
			int size;
			string tmp_str;
			fin >> tmp_str;
			size = stoi(tmp_str);
			getline(fin, tmp_str);
			while (size--)
			{
				getline(fin, tmp.name);
				fin >> tmp.number >> tmp.group;
				getline(fin, tmp_str);
				root->insert(tmp);
			}
			fin.close();
		}



		cout << endl;
	} while (true);





	return 0;
}