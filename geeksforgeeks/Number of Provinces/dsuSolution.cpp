#include<bits/stdc++.h>

using namespace std;

// problem link: https://practice.geeksforgeeks.org/problems/number-of-provinces/0

class DisjointSet{
    private:
        vector<int> pai, rank;
    
    public:
        DisjointSet(int V){
            pai.resize(V+1);
            rank.resize(V+1);
            for(int i = 0; i <= V; i++){
                pai[i] = i;
            }
        }

        int find(int u){
            return pai[u] = (pai[u] == u)? u : find(pai[u]);
        }
        void unionByRank(int u, int v){
            u = find(u);
            v = find(v);
            if(u == v) return;
            if(rank[u] < rank[v]) swap(u,v);
            if(rank[u] == rank[v])rank[u]++;
            pai[v] = u;
        }
};


int numProvinces(vector<vector<int>> adj, int V) {
    DisjointSet ds(V);
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(adj[i][j] == 1) ds.unionByRank(i+1,j+1);
        }
    }
    long long res = 0;
    for(int i = 1; i <= V; i++){
        if(ds.find(i) == i) res++;
    }
    return res;
    
}
