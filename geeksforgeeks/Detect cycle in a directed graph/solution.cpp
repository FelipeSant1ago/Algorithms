#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define MAXN 1000000
#define INF 1000000007
#define MOD 1000000007
using namespace std;
// problem link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
bool dfs(int no, vector<int> adj[],int visitados[],int x[] ){
    visitados[no] = 1;
    x[no] = 1;
    for(int adjacente : adj[no]){
        if(x[adjacente] == 1) return true;
        if(visitados[adjacente] == 0){
            if(dfs(adjacente,adj,visitados,x) == true) return true;
        }
    }
    x[no] = 0;
    return false;
    
   


}
bool isCyclic(int V, vector<int> adj[]) {
    int visitados[V] = {0};
    int x[V] = {0};


    for(int i = 0; i < V; i++){
        if(visitados[i] == 0){
            if(dfs(i,adj,visitados,x) == true) return true;
        }
    }
    return false;
        
    }

int main(){
    optimize;



}