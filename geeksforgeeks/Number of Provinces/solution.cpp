#include<bits/stdc++.h>

using namespace std;

// problem link: https://practice.geeksforgeeks.org/problems/number-of-provinces/0


void dfs(vector<vector<int>>& adj, vector<int>& visited,int node,int V){
    visited[node] = 1;
    
    for(int i = 0; i < V; i++){
        if(adj[node][i] == 1 && visited[i] == -1) dfs(adj,visited,i,V);
    } 
}

int numProvinces(vector<vector<int>> adj, int V) {
    vector<int>visited(V,-1);
    int res = 0;
    
    for(int i = 0; i < V;i++){
        if(visited[i] == -1){
            res++;
            dfs(adj,visited,i,V);
        }
    }
    
    return res;
}
