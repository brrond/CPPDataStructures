#include "dependencies.h"

using namespace std;

int main_lab7_lab8()
{
	cout << "Hello, Graph" << 12 << endl;
	
	string input;
	int menu;
	graph* gh = nullptr;

	do
	{
		cout << "1) Load graph" << endl;
		cout << "2) Print adjacency matrix" << endl;
		cout << "3) Print incidence matrix" << endl;
		cout << "4) Print edges list" << endl;
		cout << "5) Print adjacency list" << endl;
		cout << "6) Load edges list from file" << endl;/**/
		cout << "7) Enter edges list" << endl;/**/
		cout << "8) Print dfs" << endl;
		cout << "9) Print bfd" << endl;
		cout << "10) Print Floyd-Warshall distance table (8)" << endl;
		cout << "11) Print Dijkstras algorithm for specific ver (8)" << endl;
		cout << "0) Exit" << endl;
		cout << ">>>";
		cin >> input;

		if (input == "exit")
		{
			return 0;
		}
		else if (input == "cls" || input == "clear")
		{
			system("cls");
			continue;
		}

		try
		{
			menu = stoi(input);
		}
		catch (...)
		{
			cout << "Try again" << endl;
			continue;
		}

		if (menu == 0)
		{
			return 0;
		}
		else if (menu == 1)
		{
			if (!gh) delete gh;
			gh = new graph();
		}
		else if (menu == 2)
		{
			if (gh)
			{
				cout << "Enter to file(1) or to console (something else) : ";
				getline(cin, input);
				getline(cin, input);
				try
				{
					int n = stoi(input);
					if (n == 1)
					{
						ofstream fout;
						fout.open("graph_out.txt");
						fout << gh->get_adjacency_matrix_printer();
						fout.close();
						continue;
					}
				}
				catch (...) {}
				cout << gh->get_adjacency_matrix_printer();
			}
			else cout << "Create graph first" << endl;
		}
		else if (menu == 3)
		{
			if (gh)
			{
				cout << "Enter to file(1) or to console (something else) : ";
				getline(cin, input);
				getline(cin, input);
				try
				{
					int n = stoi(input);
					if (n == 1)
					{
						ofstream fout;
						fout.open("graph_out.txt");
						fout << gh->get_incidence_matrix_printer();
						fout.close(); 
						continue;
					}
				}
				catch (...) {}
				cout << gh->get_incidence_matrix_printer();
			}
			else cout << "Create graph first" << endl;
		}
		else if (menu == 4)
		{
			if (gh)
			{
				cout << "Enter to file(1) or to console (something else) : ";
				getline(cin, input);
				getline(cin, input);
				try
				{
					int n = stoi(input);
					if (n == 1)
					{
						ofstream fout;
						fout.open("graph_out.txt");
						fout << gh->get_edges_list_printer();
						fout.close();
						continue;
					}
				}
				catch (...) {}
				cout << gh->get_edges_list_printer();
			}
			else cout << "Create graph first" << endl;
		}
		else if (menu == 5)
		{
			if (gh)
			{
				cout << "Enter to file(1) or to console (something else) : ";
				getline(cin, input);
				getline(cin, input);
				try
				{
					int n = stoi(input);
					if (n == 1)
					{
						ofstream fout;
						fout.open("graph_out.txt");
						fout << gh->get_adjacency_list_printer();
						fout.close();
						continue;
					}
				}
				catch (...) {}
				cout << gh->get_adjacency_list_printer();
			}
			else cout << "Create graph first" << endl;
		}
		else if (menu == 6)
		{
			ifstream fin;
			fin.open("graph_inp.txt");
			int n; fin >> n;
			vector<vector<int>> am(n, vector<int>(n, 0));
			getline(fin, input);
			while (!fin.eof())
			{
				getline(fin, input);
				istringstream iss{ input };
				stringstream ss; ss.str(iss.str());
				int a, b, v; ss >> a >> b >> v;
				am[a][b] = v;
			}
			fin.close();
			if (gh) delete gh;
			gh = new graph(am);
		}
		else if (menu == 7)
		{
			cout << "Enter amount of ver : ";
			int n; cin >> input;
			try { n = stoi(input); }
			catch (...) { cout << "Try again" << endl; continue; }
			vector<vector<int>> am(n, vector<int>(n, 0));
			cout << "Enter \"stop\" if that's all" << endl;
			getline(cin, input);
			while (input != "stop")
			{
				cout << "Enter: ver1 ver2 value : ";
				getline(cin, input);
				istringstream iss{input};
				stringstream ss; ss.str(iss.str());
				int a, b, v; ss >> a >> b >> v;
				am[a][b] = v;
			}
			if (gh) delete gh;
			gh = new graph(am);
		}
		else if (menu == 8)
		{
			if (gh)
			{
				vector<int> ver = gh->dfs();
				cout << "Result : ";
				for_each(ver.begin(), ver.end(), [](int n) {cout << n << " "; });
				cout << endl << "Result in char : ";
				for_each(ver.begin(), ver.end(), [](int n) {cout << (char)('A' + n) << " "; });
				cout << endl;
			}
			else cout << "Create graph first" << endl;
		}
		else if(menu == 9)
		{
			if (gh)
			{
				vector<int> ver = gh->bfd();
				cout << "Result : ";
				for_each(ver.begin(), ver.end(), [](int n) {cout << n << " "; });
				cout << endl << "Result in char : ";
				for_each(ver.begin(), ver.end(), [](int n) {cout << (char)('A' + n) << " "; });
				cout << endl;
			}
			else cout << "Create graph first" << endl;
		}
		else if (menu == 10)
		{
			vector<vector<int>> r = gh->wfi();
			cout << adjacency_matrix_printer(r, false);
		}
		else if (menu == 11)
		{
			cout << "Enter ver : ";
			cin >> input;
			int n;
			try { n = stoi(input); }
			catch (...) { cout << "Something wrong. I'll use n = 0"; n = 0; }
			vector<int> r = gh->dijkstras_algorithm(n);
			cout << "\t";
			for (int b = 0; b < r.size(); b++)
			{
				cout << setw(4) << b;
			}
			cout << endl;
			cout << "\t";
			for (char b = 'A'; b < ('A' + r.size()); b++)
			{
				cout << setw(4) << b;
			}
			cout << endl;
			cout << n << " " << (char)('A' + n) << '\t';

			for_each(r.begin(), r.end(), [](int n) {
				cout << setw(4);
				if (n == 0) cout << " ";
				else cout << n;
				});
			cout << endl;
		}

		cout << "Done" << endl;
	} while (true);
	

	return 0;
}