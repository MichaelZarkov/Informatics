#include <iostream>
#include <vector>
using namespace std;


void dfs1(int & vertex, vector<vector<int >>& graph, vector <bool>& visited,vector <int>& topo_sort) {
	visited[vertex] = true;
	for (auto neighbor : graph[vertex]) {
		if (!visited[neighbor])
			dfs1(neighbor, graph, visited, topo_sort);
	 }
    
	topo_sort.push_back(vertex);

}

void dfs2(int& vertex, vector<vector<int >>& graph_rev, vector <bool>& visited, vector <int>& current_component) {
		visited[vertex] = 1;
		current_component.push_back(vertex);
		for (auto neighbor : graph_rev[vertex]) {
			if (!visited[neighbor])
				dfs2(neighbor, graph_rev, visited, current_component);
		}

}


//Kosaraju's Algorithm implementation

int main()
{
	int number_of_nodes;
	int number_of_edges;
	int start_vertex;
	int v, u, w;
	cin >> number_of_nodes;
	cin >> number_of_edges;

	if (number_of_nodes < 0	|| number_of_edges < 0) return 0;

	vector <bool> visited(number_of_nodes, false);
	vector<vector<int >> graph(number_of_nodes), graph_rev(number_of_nodes), adj_scc(number_of_nodes);;
	vector <int> topo_sort, current_component, root_nodes, roots(number_of_nodes, 0);
 

	for (int i = 0; i < number_of_edges; ++i) {

		cin >> u>> v;
		graph[u].push_back(v );
		//Graph Transpose ( u ->v to v->u)
		graph_rev[v].push_back( u );

	}
	
	for (int i = 0; i < number_of_nodes; ++i) {
		if (!visited[i])
			dfs1(i, graph, visited, topo_sort);
	}
	visited.assign(number_of_nodes, false);
	reverse(topo_sort.begin(), topo_sort.end());
	cout << "Topological sort of DAG: ";
	for (auto elem : topo_sort) cout << elem << " ";
	std::cout << endl << endl;

	//Condensation Graph

	for (auto elem: topo_sort) {
		if (!visited[elem]) {
				dfs2(elem, graph_rev, visited, current_component);
				cout << "New strongly connected component found: ";
				for (auto elem : current_component)
					std::cout << elem << " ";

				std::cout << endl;

				int root = current_component.front();
				for (auto u : current_component) roots[u] = root;
				root_nodes.push_back(root);


				current_component.clear();

		}
	}
	std::cout << endl;

	for (int vertex = 0; vertex < number_of_nodes; vertex++)
		for (auto neigh : graph[vertex]) {
			int root_vertex = roots[vertex],
				root_neighbor = roots[neigh];

			if (root_vertex != root_neighbor)
				adj_scc[root_vertex].push_back(root_neighbor);
		}



	for (int vertex = 0; vertex < adj_scc.size(); vertex++) {
		if (adj_scc[vertex].size() == 0) continue;
			  cout << "Neighbors of " << vertex << " in the condensed graph are: ";
				for (auto neigh : adj_scc[vertex])
				cout << neigh << " ";


		       cout << endl;


	}

return 0;

}

//example:
/*
9 10
0 1
1 2
2 3
3 0
2 4
4 5
5 6
6 4
7 6
7 8
*/