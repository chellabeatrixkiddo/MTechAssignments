/**
*	All Pairs Shortest Path - Dynamic Programming - Floyd-Warshall's Algorithm
*
*	Code written by: Chellapriyadharshini.M. (MT2016041)
**/
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#define INF 99999

using namespace std;

int V;

void printSolution(int * dist[V]);
 
void floydWarshall (int * graph[V]) {
    int i, j, k;
	int *dist[V];
    for (i = 0; i < V; i++) {
    	dist[i] = (int *)malloc(V * sizeof(int));
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    }
 
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist);
}
 
void printSolution(int * dist[V]) {
    printf ("The shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
 
int main() {

	int E;
    int u, v, w, i, j, k;
    cout << "Enter the no. of Vertices: ";
    cin >> V;
    cout << "Enter the no. of Edges: ";
    cin >> E;
    
    int *graph[V];
    for(int i = 0; i < V; i++) {
    	graph[i] = (int *)malloc(V * sizeof(int));
    	for(int j = 0; j < V; j++) {
    		if(i == j)
    			graph[i][j] = 0;
    		else
    			graph[i][j] = INF;
    	}
    }
    cout << "Enter the Edges U->V and their Weight: \n";
    for(int k = 0; k < E; k++) {
    	cout << "Edge: " << (k+1) << " : ";
    	cin >> u >> v >> w;
    	graph[u][v] = w;
    }
 
    floydWarshall(graph);
    return 0;
}