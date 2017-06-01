/**
*	Single Source Shortest Path - Greedy - Dijkstra's Algorithm
*
*	Code written by: Chellapriyadharshini.M. (MT2016041)
**/

#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
 
typedef pair<int, int> iPair;

class Graph {
    int V;   
    list< pair<int, int> > *adj;
 
public:
    Graph(int V); 
 
    void addEdge(int u, int v, int w);
 
    void shortestPath(int s);
};
 
Graph::Graph(int V) {
    this->V = V;
    adj = new list<iPair> [V];
}
 
void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 
void Graph::shortestPath(int src) {
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    
    vector<int> dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;
 
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
 
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;
 
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
 
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
 
int main() {
    int V, E;
    int u, v, w;
    cout << "Enter the no. of Vertices: ";
    cin >> V;
    cout << "Enter the no. of Edges: ";
    cin >> E;
    
    Graph g(V);
 	
 	cout << "Enter the Edges U->V and their Weight: \n";
 	for(int i = 0; i < E; i++) {
 		 cout << "Edge: " << (i+1) << " : ";
 		 cin >> u >> v >> w;
 		 g.addEdge(u, v, w);
 	}
 	
    g.shortestPath(0);
 
    return 0;
}