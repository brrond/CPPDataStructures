#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using std::vector;
using std::pair;
using std::make_pair;
using std::find;

class adjacency_matrix_printer
{
public:

	adjacency_matrix_printer(vector<vector<int>> am, bool print_with_zero)
	{
		adjacency_matrix = am;
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
	vector<vector<int>> adjacency_matrix;
	bool print_with_zero;
};

class incidence_matrix_printer
{
public:

	incidence_matrix_printer(vector<vector<int>> im, bool pwz)
	{
		incidence_matrix = im;
		print_with_zero = pwz;
	}

	friend std::ostream& operator<<(std::ostream& out, incidence_matrix_printer gh)
	{
		// ver
		vector<pair<int, int>> ver;
		for (int i = 0; i < gh.incidence_matrix.size(); i++)
		{
			for (int j = 0; j < gh.incidence_matrix[i].size(); j++)
			{
				if (gh.incidence_matrix[i][j] != 0)
				{
					for (int k = 0; k < gh.incidence_matrix.size(); k++)
					{
						if (gh.incidence_matrix[k][j] == -gh.incidence_matrix[i][j])
						{
							pair<int, int> new_pair = make_pair(k, i);
							for (auto pa : ver)
							{
								if (pa == new_pair)
									goto break__;
							}
							ver.push_back(make_pair(i, k));
							break__:
							break;
						}
					}
				}
			}
		}

		out << std::setw(7) << " ";
		for (size_t i = 0; i < ver.size(); i++)
			out << std::setw(4) << ver[i].first <<
			ver[i].second << std::setw(4);
		out << "\n";

		out << std::setw(7) << " ";
		for (size_t i = 0; i < ver.size(); i++)
			out << std::setw(4) << (char)('A' + ver[i].first) << 
			(char)('A' + ver[i].second) << std::setw(4);
		out << "\n";

		for (size_t i = 0; i < gh.incidence_matrix.size(); i++)
		{
			out << std::setw(4);
			out << i << " " << (char)('A' + i) << " ";
			for (size_t j = 0; j < gh.incidence_matrix[i].size(); j++)
			{
				out << std::setw(5);
				if (gh.print_with_zero)
					out << gh.incidence_matrix[i][j];
				else
					if (gh.incidence_matrix[i][j] == 0)
						out << " ";
					else
						out << gh.incidence_matrix[i][j];
			}
			out << std::endl;
		}
		return out;
	}

private:
	vector<vector<int>> incidence_matrix;
	bool print_with_zero;
};

class edges_list_printer
{
public:

	edges_list_printer(vector<pair<pair<int, int>, int>> el)
	{
		edges_list = el;
	}

	friend std::ostream& operator<<(std::ostream& out, edges_list_printer gh)
	{
		for (int i = 0; i < gh.edges_list.size(); i++)
		{
			out << (char)('A' + gh.edges_list[i].first.first) << 
				(char)('A' + gh.edges_list[i].first.second) << " => ";
			out << gh.edges_list[i].second << "\n";
		}
		return out;
	}

private:
	vector<pair<pair<int, int>, int>> edges_list;
};

class adjacency_list_printer
{
public:

	adjacency_list_printer(vector<vector<pair<int, int>>> al)
	{
		adjacency_list = al;
	}

	friend std::ostream& operator<<(std::ostream& out, adjacency_list_printer gh)
	{
		for (int i = 0; i < gh.adjacency_list.size(); i++)
		{
			for(auto it : gh.adjacency_list[i])
			{
				out << it.first << " " << (char)('A' + it.first) << " " << it.second << " => ";
			}
			out << "\n";
		}
		return out;
	}

private:
	vector<vector<pair<int, int>>> adjacency_list;
};

class graph
{
public:
	bool print_with_zero = true;

public:

	graph(vector<vector<int>> am)
	{
		// check if am is good
		for (int i = 0; i < am.size(); i++)
			if (am[i].size() != am.size())
				return;

		adjacency_matrix = am;
	}

	graph()
	{
		adjacency_matrix.resize(13);
		std::for_each(adjacency_matrix.begin(), adjacency_matrix.end(), [](vector<int>& v) {
			v.resize(13);
			std::for_each(v.begin(), v.end(), [](int& n) {n = 0; });
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

		/*
		adjacency_matrix.resize(8);
		for (int i = 0; i < 8; i++)
		{
			adjacency_matrix[i].resize(8);
			for (int j = 0; j < 8; j++)
			{
				adjacency_matrix[i][j] = 0;
			}
		}
		adjacency_matrix[0][1] = 3;
		adjacency_matrix[0][5] = 5;
		adjacency_matrix[1][6] = 2;
		adjacency_matrix[2][4] = 1;
		adjacency_matrix[2][7] = 4;
		adjacency_matrix[3][0] = 2;
		adjacency_matrix[5][1] = 3;
		adjacency_matrix[5][6] = 6;
		adjacency_matrix[7][4] = 1;
		*/
	}

	~graph() {}

	inline vector<vector<int>> get_adjacency_matrix()
	{ 
		return adjacency_matrix; 
	}

	inline vector<vector<int>> get_incidence_matrix()
	{ 
		return adjacency_matrix_to_incidence_matrix(adjacency_matrix); 
	}

	inline vector<pair<pair<int, int>, int>> get_edges_list()
	{ 
		return incidence_matrix_to_edges_list(adjacency_matrix_to_incidence_matrix(adjacency_matrix)); 
	}

	inline vector<vector<pair<int, int>>> get_adjacency_list()
	{
		return adjacency_matrix_to_adjacency_list(adjacency_matrix);
	}

	inline adjacency_matrix_printer get_adjacency_matrix_printer()
	{
		return adjacency_matrix_printer(adjacency_matrix, print_with_zero);
	}

	inline incidence_matrix_printer get_incidence_matrix_printer()
	{
		return incidence_matrix_printer(adjacency_matrix_to_incidence_matrix(adjacency_matrix),
			print_with_zero);
	}

	inline edges_list_printer get_edges_list_printer()
	{
		return edges_list_printer(get_edges_list());
	}

	inline adjacency_list_printer get_adjacency_list_printer()
	{
		return adjacency_list_printer(get_adjacency_list());
	}

	static vector<vector<int>> adjacency_matrix_to_incidence_matrix(vector<vector<int>> am)
	{
		vector<vector<int>> im(am.size());
		size_t count = 0;
		for_each(am.begin(), am.end(), [&count](vector<int>& vec) {
			for_each(vec.begin(), vec.end(), [&count](int& el) {
				if (el != 0) count++;
				});
			});

		for (size_t i = 0; i < im.size(); i++)
			im[i].resize(count);

		size_t index = 0;
		for (size_t i = 0; i < am.size(); i++)
		{
			for(size_t j = 0; j < am[i].size(); j++)
			{
				if (am[i][j] != 0)
				{
					im[i][index] = -am[i][j];
					im[j][index++] = am[i][j];
				}
			}
		}
		return im;
	}

	static vector<vector<int>> incidence_matrix_to_adjacency_matrix(vector<vector<int>> im)
	{
		vector<vector<int>> am(im.size(), vector<int>(im.size()));
		for (int i = 0; i < im.size(); i++)
		{
			for (int j = 0; j < im[i].size(); j++)
			{
				if (im[i][j] != 0)
				{
					for (int k = i + 1; k < im.size(); k++)
					{
						if (im[k][j] == -im[i][j])
						{
							if (im[i][j] < 0)
								am[i][k] = -im[i][j];
							else
								am[k][i] = im[i][j];
							break;
						}
					}
				}
			}
		}
		return am;
	}

	static vector<pair<pair<int, int>, int>> incidence_matrix_to_edges_list(vector<vector<int>> im)
	{
		vector<pair<pair<int, int>, int>> el;

		for (int i = 0; i < im.size(); i++)
		{
			for (int j = 0; j < im[i].size(); j++)
			{
				if (im[i][j] < 0)
				{
					for (int k = 0; k < im.size(); k++)
					{
						if (im[k][j] == -im[i][j])
						{
							// (i, k) // (k, i) == (i, k)
							if (find(el.begin(), el.end(), make_pair(make_pair(k, i), abs(im[k][j]))) == el.end())
							{
								el.push_back(make_pair(make_pair(i, k), abs(im[k][j])));
								break;
							}
						}
					}
				}
				continue;
			}
		}
		return el;
	}

	static vector<vector<pair<int, int>>> adjacency_matrix_to_adjacency_list(vector<vector<int>> am)
	{
		vector<vector<pair<int, int>>> al;
		for (int i = 0; i < am.size(); i++)
		{
			al.push_back({});
			al[i].push_back(make_pair(i, 0));
			for (int j = 0; j < am.size(); j++)
			{
				if (am[i][j] > 0)
				{
					al[i].push_back(make_pair(j, am[i][j]));
				}
			}
		}
		return al;
	}

	vector<int> dfs(int begin = 0)
	{
		vector<int> res;
		vector<bool> visited(adjacency_matrix.size(), false);
		res.push_back(begin);//////wd/ewd/e/dwe/d/ewed/we/de/dw/dw/ew/d
		dfs_step(adjacency_matrix[begin], res, visited);
		return res;
	}

	vector<int> bfd(int begin = 0)
	{
		vector<bool> visited(adjacency_matrix.size(), false);
		vector<int> res;
		vector<int> should_be_checked;
		should_be_checked.push_back(begin);
		visited[begin] = true;
		res.push_back(begin);
		while (should_be_checked.size())
		{
			int curr = should_be_checked[0];
			should_be_checked.erase(should_be_checked.begin());
			for (int i = 0; i < adjacency_matrix[curr].size(); i++)
			{
				if (adjacency_matrix[curr][i] && !visited[i])
				{
					visited[i] = true;
					should_be_checked.push_back(i);
					res.push_back(i);
				}
			}
		}
		return res;
	}

	// Floyd–Warshall algorithm (get distance matrix)
	vector<vector<int>> wfi()
	{
		int S = 1;
		for (auto vec : adjacency_matrix)
			for (int v : vec)
				S += abs(v);

		vector<vector<int>> dist(adjacency_matrix.size(), vector<int>(adjacency_matrix.size(), S));
		for (int i = 0; i < adjacency_matrix.size(); i++)
			for (int j = 0; j < adjacency_matrix[i].size(); j++)
				if (adjacency_matrix[i][j])
					dist[i][j] = adjacency_matrix[i][j];

		for (int i = 0; i < adjacency_matrix.size(); i++)
			dist[i][i] = 0;

		for (int k = 0; k < adjacency_matrix.size(); k++)
			for (int i = 0; i < adjacency_matrix.size(); i++)
				for (int j = 0; j < adjacency_matrix.size(); j++)
					if (dist[i][j] > dist[i][k] + dist[k][j])
						dist[i][j] = dist[i][k] + dist[k][j];

		for (int i = 0; i < adjacency_matrix.size(); i++)
			for (int j = 0; j < adjacency_matrix.size(); j++)
				if (dist[i][j] == S)
					dist[i][j] = 0;

		return dist;
	}

	vector<int> dijkstras_algorithm(int start = 0)
	{
		int S = 1;
		for (auto vec : adjacency_matrix)
			for (int v : vec)
				S += abs(v);

		vector<int> d(adjacency_matrix.size(), S);
		d[start] = 0;
		vector<int> ver = bfd(start);
		while (ver.size())
		{
			int curr = ver[0];
			ver.erase(ver.begin());
			for(int v = 0; v < adjacency_matrix.size(); v++)
				if (adjacency_matrix[curr][v])
					if (d[v] > d[curr] + adjacency_matrix[curr][v])
						d[v] = d[curr] + adjacency_matrix[curr][v];
		}

		return d;
	}

protected:
	void dfs_step(vector<int> ml, vector<int>& r, vector<bool>& v)
	{
		vector<int> cur;
		for (int i = 0; i < ml.size(); i++)
			if (ml[i] != 0)
				cur.push_back(i);

		while (cur.size())
		{
			if (!v[cur[0]])
			{
				v[cur[0]] = true;
				r.push_back(cur[0]);
				dfs_step(adjacency_matrix[cur[0]], r, v);
			}

			cur.erase(cur.begin());
		}
	}

private:
	vector<vector<int>> adjacency_matrix;
};


