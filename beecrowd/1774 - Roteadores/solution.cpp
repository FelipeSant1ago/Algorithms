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
        vi rank,pai;

    public:
        DisjointSet(int V){
            rank.resize(V+1);
            pai.resize(V+1);
            for(int i = 0; i <= V; i++)pai[i] = i;
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


int main(){

    optimize;


    int R, C;

    cin >> R >> C;
    int u, v, p;
    vector<pair<int,pii>> arestas;
    DisjointSet ds(R);
    for(int i = 0; i < C; i++){

        cin >> u >> v >> p;
        arestas.push_back({p,{u,v}});
    }
    ll res = 0;
    sort(ALL(arestas));
    for(auto it : arestas){
        p = it.first;
        u = it.second.first;
        v = it.second.second;
        if(ds.find(u) != ds.find(v)){
            ds.unionByRank(u,v);
            res += p;
        }
    }

    cout << res << endl;

}