#include <bits/stdc++.h>
using namespace std;
#define INF 9999999
typedef vector<int> vi;

void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s); // nao direcionado
}


void BFS(vector<int> adj[], int V, int s){
  vector<bool> visited(V, false);
  queue<int> q;
  vector<int> distance(V,0);
  visited[s] = true;
  q.push(s); // adiciona o primeiro na fila
  while(!q.empty()){
    s = q.front();
    cout << s << " ";
    cout << endl;
    q.pop();
    for(auto i: adj[s]){
      if(!visited[i]){
        visited[i] = true;
        distance[i] = distance[s]+1;
        q.push(i);
        }
      }
    }
   for(int c = 0; c< V; c++){
    cout << c << " ";}
  cout << endl; 
  for(auto dist: distance){
    cout << dist << " ";
  }
}

void DFS(vector<set<int>>&adj, int V, int s){
    vector<bool> visited(V, false);
    stack<int> stk;
    int cont = 0;
    stk.push(s);
    visited[s] = true;
    while(!stk.empty()){
        s = stk.top();
        visited[s] = true;
        stk.pop();
        for(auto i: adj[s]){
            if(!visited[i]){
                cont+=2;
                stk.push(i);
            }
        }
    }
    cout << cont << endl;
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
  int a, b;
  cout << "Digite o numero de vertices: ";
  cin >> V;
  cout << "Digite o numero de arestas: ";
  cin >> E;
  // Create a graph
  vector<int> adj[V];
  for(int i = 0; i<E; i++){
    cout << "Digite 2 numeros: ";
    cin >> a >> b;
    addEdge(adj, a, b);
  }
  //BFS(adj, V, 1);
  //DFS(adj,V, 2);
  printGraph(adj, V); 
  

  // Add edges
   addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 1, 2);
  printGraph(adj, V); 
  return 0;
}
