/**
*	Single Source Shortest Path - Dynamic Programming - Bellman-Ford's Algorithm
*
*	Code written by: Chellapriyadharshini.M. (MT2016041)
**/
 
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};
 
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = 
         (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = 
       (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}
 
void printArr(int dist[], int n) {
    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
 
void BellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];
 
    for (int i = 0; i < V; i++)
        dist[i]   = INT_MAX;
    dist[src] = 0;
 
    for (int i = 1; i <= V-1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
 
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            cout << "Graph contains negative weight cycle";
    }
 
    printArr(dist, V);
 
    return;
}
 
int main() {
    int V, E;
    int u, v, w;
    cout << "Enter the no. of Vertices: ";
    cin >> V;
    cout << "Enter the no. of Edges: ";
    cin >> E;
    struct Graph* graph = createGraph(V, E);
 
 	cout << "Enter the Edges U->V and their Weight: \n";
 	for(int i = 0; i < E; i++) {
 		cout << "Edge: " << (i+1) << " : ";
 		cin >> u >> v >> w;
 		graph->edge[i].src = u;
    	graph->edge[i].dest = v;
    	graph->edge[i].weight = w;
 	}
 
    BellmanFord(graph, 0);
 
    return 0;
}