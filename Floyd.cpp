#include <bits/stdc++.h>

using namespace std;
const int INF = 9999999;

vector<vector<int>> creathGraph(vector<vector<int>> graph, int a, int b, int weight){
  graph[a][b] = weight;
  return graph;
}

void printGraph(vector<vector<int>> graphs) {
  for (int i = 0; i < graphs.size(); i++) {
    cout << "[" << i << "]";
    for (auto &k : graphs[i]) {
      if (k == INF) {
        cout << " => "
             << "INF";
      } else
        cout << " => " << k;
    }
    cout << endl;
  }
  for(int i =0;i < graphs.size();i++){
        cout<< "\n";
        for(int j =0; j<graphs.size();j++){
          if(graphs[i][j] == INF){
            graphs[i][j] = 0;
          }
            cout<< graphs[i][j]<<" ";
        }
    }
  cout << "\n";
}

vector<vector<int>> floyd(vector<vector<int>> dist){
  int v = dist.size();
  for(int k = 0; k < v; k++){
    for(int i = 0; i < v; i++){
      for(int j = 0;j < v;j++){
        if(dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
  return dist;
}



vector<vector<int>> creathM(int v){
  vector<vector<int>> matriz;
  matriz.resize(v);
  for(int i = 0; i<v;i++)
    matriz[i].resize(v);
  
  for(int l = 0; l<v;l++ ){
    for(int c = 0; c<v; c++){
      matriz[l][c] = INF;
    }
  }
  return matriz;
}



int main(){
  int v,e;
  int a,b;
  int weight;
  cout << "Digite o vertice e a aresta: ";
  cin >> v >> e;
  
  vector<vector<int>> graph;
  graph = creathM(v);
  for (int i = 0; i< e; i++){
    cout << "Digite A e B: ";
    cin >> a >> b;
    cout << "Digite o peso: ";
    cin >> weight;
    graph = creathGraph(graph, a, b, weight);
  }
  vector<vector<int>> distancia;
  printGraph(graph);
  cout << "-----------------" << endl;
  distancia = floyd(graph);
  printGraph(distancia);
  
}
