#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define ALL(x) x.begin(),x.end() 
#define MAXN 1000000
#define INF 1000000007
#define MOD 1000000007
using namespace std;

class DisjointSet{

    private:
        vector<int> pai,rank;

    public:
        DisjointSet(int V){
            pai.resize(V+1);
            rank.resize(V+1);
            for(int i = 0; i <= V; i++){
                pai[i] = i;
            }
        }
        
        int find(int u){
            return pai[u] = (pai[u] == u)? u :  find(pai[u]);
        }
        void unionByRank(int u, int v){
            u = find(u);
            v = find(v);
            if(u == v) return;
            if(rank[u] < rank[v]) swap(u,v);
            if(rank[u] == rank[v]) rank[u]++;
            pai[v] = u;
        }
};



int spanningTree(int V, vector<vector<int>> adj[])
{
    DisjointSet ds(V);
    priority_queue<pair<int,pair<int,int>>>pq;
    for(int i = 0; i < V; i++){
        for(auto x : adj[i]){
            pq.push({-x[1],{i,x[0]}});
        }
    }
    long long res = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int origem = it.second.first;
        int destino = it.second.second;
        int peso = it.first;
        if(ds.find(origem) != ds.find(destino)){
            ds.unionByRank(origem,destino);
            res += -peso;
        }
    }
    return res;
}


int main(){

    optimize;

}