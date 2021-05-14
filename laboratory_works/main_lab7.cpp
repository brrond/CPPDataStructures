#include "dependencies.h"

using namespace std;

int main_lab7()
{
	cout << "Hello, Graph" << 12 << endl;

	graph gh;
	gh.print_with_zero = false;

	cout << gh.get_adjacency_matrix_printer();

	auto r = gh.dfs(2);

	auto r2 = gh.bfd();

	return 0;
}