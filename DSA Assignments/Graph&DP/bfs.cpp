/**
*	Graph Traversal - Breadth First Search
*
*	Code written by: Chellapriyadharshini.M. (MT2016041)
**/

#define VERTICES 5
#define EDGES 7
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <utility>

std::vector < std::list < std::pair <int, int> > > adjacency_list(VERTICES+1);

void create_graph();
void print_adj_list();
void bfs(int);

void create_graph() {
	int i, u, v, weight;
	std::cout << "Creating a Graph of " << VERTICES << " Vertices and " << EDGES << " Edges..\n";
	std::cout << "Enter the Edges U->V and their Weight:\n";
	for(i = 0; i < EDGES; i++) {
		std::cout << "Edge: " << i+1 << " : ";
		std::cin >> u >> v >> weight;
		adjacency_list[u].push_back(std::make_pair(v, weight));
	}
}

void print_adj_list() {
	int i;
	std::cout << "Adjacency List for the Graph: \n";
	for(i = 1; i < VERTICES+1; i++) {
		std::cout << "Adjacency List [" << i << "] : ";
		std::list<std::pair<int, int> >::iterator itr = adjacency_list[i].begin();
		while(itr != adjacency_list[i].end()) {
			std::cout << " -> " << itr->first << " (Weight: " << itr->second << ")";
			++itr;
		}
		std::cout << std::endl;
	}
}


void bfs(int s) {
	bool visited[VERTICES+1];
	int predecessor[VERTICES+1];
	int i, u, v;
	std::list<std::pair<int, int> >::iterator itr;
	std::queue <int> Q;
	
	for(i = 1; i < VERTICES+1; i++)
		visited[i] = 0;
	
	std::cout << "BFS Traversal:\n";
	Q.push(s);
	predecessor[s] = 0;
	while(!Q.empty()) {
		// Dequeue
		u = Q.front();
		Q.pop();
		std::cout << u ;
		visited[u] = 1;
		itr = adjacency_list[u].begin();
		while(itr != adjacency_list[u].end()) {
			v = itr->first;
			if(visited[v] == 0) {
				Q.push(v);
				visited[v] = 1;
				predecessor[v] = u;
			}
			++itr;
		}
		std::cout << " -> ";
	}
	std::cout << "\b\b\b   ";
	std::cout << std::endl;
}

int main() {
	
	// Create a Graph
	create_graph();
	
	// Display the adjacency list for the Graph
	print_adj_list();
	
	// Breadth First Search Traversal
	bfs(1);
	
	return 0;
}