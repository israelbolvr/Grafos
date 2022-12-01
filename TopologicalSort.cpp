#include <bits/stdc++.h>
using namespace std;

#define INF 99999
void topologicalSort(vector<int> graph[INF], int grade[INF], int m, int n){
    vector<int> list; // dos vértices de grau zero
    for(int i = 0;i < n;i++) {
        //cout << "o grau de " << i << "eh " << grade[i];
        if(grade[i] == 0){
        //cout <<"Adicionei o " << i;
        list.push_back(i);
        }
    }
    int initial = 0;
    while(initial < (int)list.size()){
        int current = list[initial];
        initial++;
        for(int i = 0;i < (int)graph[current].size();i++){
        int v = graph[current][i]; 
        //cout << "O grau de:" << v << "é" << grade[v]<< endl; 
        grade[v]--;
        if(grade[v] == 0){
            list.push_back(v); // se o grau se tornar zero, acrescenta-se a list
        }
        }
    }
    if((int)list.size() < n) 
        cout << "*" << endl;
    else{
        for(int i = 0;i < (int)list.size();i++) 
        cout << list[i] << endl;
        } 
    }


int main(){
    int n, m; // número de vértices e arestas
    vector<int> graph[INF];
    int grade[INF];
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int x, y;
        cin >> x >> y;
        grade[y]++;
        graph[x].push_back(y);
    }
    topologicalSort(graph, grade, m, n);
    
    
    return 0;
}
