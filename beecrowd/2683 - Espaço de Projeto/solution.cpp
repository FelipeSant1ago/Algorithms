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

class DisjointSet
{
    vector<int> rank, pai;

public:
    DisjointSet(int V){
        rank.resize(V+1);
        pai.resize(V+1);
        for(int i = 0; i <= V; i++)pai[i] = i;
    }

    int find(int u){
        return pai[u] = (pai[u]== u)? u : find(pai[u]);
    }

    void join(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        if(rank[u] < rank[v]) swap(u,v);
        if(rank[u] == rank[v]) rank[u]++;
        pai[v] = u;

    }
};


int main(){

    optimize;

    int n;
    cin >> n;
    DisjointSet ds(n);

    int u, v, custo;
    ll maximo = 0, minimo = 0;
    vector<pair<int,pii>> arestas;
    for(int i = 0; i < n; i++){
        cin >> u >> v >> custo;
        arestas.push_back({custo,{u,v}});
    }
    sort(ALL(arestas));
    
    for(auto it : arestas){
        custo = it.first;
        u = it.second.first;
        v = it.second.second;
        if(ds.find(u) != ds.find(v)){
            minimo += custo;
            ds.join(u,v);
        }
    }

    reverse(ALL(arestas));

    DisjointSet ds2(n);

    for(auto it : arestas){
        custo = it.first;
        u = it.second.first;
        v = it.second.second;
        if(ds2.find(u) != ds2.find(v)){
            maximo += custo;
            ds2.join(u,v);
        }
    }


    cout << maximo << endl << minimo << endl;


}