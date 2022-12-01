#include <bits/stdc++.h>


using namespace std;
#define INF 9999999
typedef vector<int> vi;

void addEdge(vector<pair<int, int>> grafo[], int v1, int v2, int custo) {
		grafo[v1].push_back(make_pair(custo, v2));
}

void dijkstra(vector<set<pair<int,int>>> adj,int first,int last){
   priority_queue<pair <int,int>, vector<pair<int,int>>,greater<pair <int,int>>> pqueue;
   vector<int> dist(adj.size(),INF);
   vector<int> previous(adj.size(),0);
   pair<int,int> current;
   dist[first]=0;
   pqueue.push(make_pair(0,first));
 
   while(!pqueue.empty() && current.second != last){
       current = pqueue.top();
       //cout << " Estou no "<< current.second << " //  " <<endl;
       pqueue.pop();
       for(auto value: adj[current.second]){
           if(dist[current.second] + value.second < dist[value.first]){
               dist[value.first] = dist[current.second] + value.second;
               pqueue.push(make_pair(dist[value.first],value.first));
               //cout << current.second << " to "<< value.first << " // Distancia: " <<dist[value.first] <<endl;
           }
       }
   }
   cout << "Distancia minima: " << dist[last] << endl;
}

void printGraph(vector<int> adj[], int V) {
  for (int d = 0; d < V; ++d) {
    cout << "\n Vertex " << d << ":";
    for (auto x : adj[d]) 
      cout << "-> " << x;
    printf("\n");
  }
}

int main() {
  
  int V, E;
  int a, b, custo;
  cout << "Digite o numero de vertices: ";
  cin >> V;
  cout << "Digite o numero de arestas: ";
  cin >> E;
  // Create a graph
  vector<pair<int, int>> adj[V];
  for(int i = 0; i<E; i++){
    cout << "Digite 2 numeros e o custo: ";
    cin >> a >> b >> custo;
    addEdge(adj, a, b, custo);
  }
  //Dijkstra(adj,0,4, 1);
  
  //printGraph(adj, V); 
  return 0;
}
