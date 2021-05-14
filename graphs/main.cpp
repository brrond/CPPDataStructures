#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
	cout << "Hello, Graph" << 12 << endl;

	graph gh;
	gh.print_with_zero = false;
	cout << gh.get_adjacency_matrix_printer();
	return 0;
}