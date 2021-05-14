#pragma once

#include <forward_list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using std::forward_list;
using std::vector;

class adjacency_matrix_printer
{
public:

	adjacency_matrix_printer(vector<vector<size_t>>& am, bool print_with_zero) : adjacency_matrix(am)
	{
		this->print_with_zero = print_with_zero;
	}

	~adjacency_matrix_printer()
	{

	}

	friend std::ostream& operator<<(std::ostream& out, adjacency_matrix_printer gh)
	{
		out << std::setw(7) << " ";
		for (size_t i = 0; i < gh.adjacency_matrix.size(); i++)
			out << std::setw(4) << i << std::setw(4);
		out << "\n";
		out << std::setw(7) << " ";
		for (size_t i = 0; i < gh.adjacency_matrix.size(); i++)
			out << std::setw(4) << (char)('A' + i) << std::setw(4);
		out << "\n";
		for (size_t i = 0; i < gh.adjacency_matrix.size(); i++)
		{
			out << std::setw(4);
			out << i << " " << (char)('A' + i) << " ";
			for (size_t j = 0; j < gh.adjacency_matrix[i].size(); j++)
			{
				out << std::setw(4);
				if (gh.print_with_zero)
					out << gh.adjacency_matrix[i][j];
				else
					if (gh.adjacency_matrix[i][j] == 0)
						out << " ";
					else
						out << gh.adjacency_matrix[i][j];
			}
			out << std::endl;
		}
		return out;
	}

private:
	vector<vector<size_t>>& adjacency_matrix;
	bool print_with_zero;
};

class graph
{
public:

	graph()
	{
		adjacency_matrix.resize(13);
		std::for_each(adjacency_matrix.begin(), adjacency_matrix.end(), [](vector<size_t>& v) {
			v.resize(13);
			std::for_each(v.begin(), v.end(), [](size_t& n) {n = 0; });
			});

		adjacency_matrix[0][2] = 2;
		adjacency_matrix[0][3] = 5;
		adjacency_matrix[0][5] = 7;

		adjacency_matrix[1][2] = 2;
		adjacency_matrix[1][4] = 1;

		adjacency_matrix[2][4] = 5;

		adjacency_matrix[3][6] = 10;

		adjacency_matrix[4][5] = 2;
		adjacency_matrix[4][10] = 12;

		adjacency_matrix[5][7] = 8;
		adjacency_matrix[5][8] = 5;

		adjacency_matrix[6][5] = 6;
		adjacency_matrix[6][9] = 11;

		adjacency_matrix[7][11] = 12;

		adjacency_matrix[8][6] = 4;
		adjacency_matrix[8][7] = 2;
		adjacency_matrix[8][11] = 7;
		adjacency_matrix[8][12] = 9;

		adjacency_matrix[9][12] = 6;

		adjacency_matrix[10][11] = 9;
	}

	~graph() {}

	vector<vector<size_t>> get_adjacency_matrix() { return adjacency_matrix; }

	adjacency_matrix_printer get_adjacency_matrix_printer()
	{
		return adjacency_matrix_printer(adjacency_matrix, print_with_zero);
	}

	bool print_with_zero = true;

protected:

private:
	vector<vector<size_t>> adjacency_matrix;
};


