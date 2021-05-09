#include "dependencies.h"

using namespace std;

int main_lab6()
{
	cout << "Hello world" << 2144 << endl;

	vector<int> arr = { 49, 32, 75, 53, 85, 19, 76, 44, 5 };

	/* First
	float A = (sqrt(5) - 1) / 2;
	chain_hash<int> table(20, [A](int k) {
		float t = k * A;
		return (size_t)((t - floor(t)) * 20);
		});

	table.insert(81);
	table.insert(82);
	table.insert(83);
	table.insert(84);
	table.insert(85);
	*/

	//* Second
	chain_hash<int> table(9, [](int k) {return k % 9; });
	for_each(arr.begin(), arr.end(), [&table](int n) {table.insert(n); });
	cout << table;
	//*/

	

	return 0;
}