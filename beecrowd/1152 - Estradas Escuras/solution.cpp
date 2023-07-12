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

    int m, n;
    while(cin >> m >> n && m+n != 0){
        int u,v,x;
        vector<pair<int,pii>>arestas;
        DisjointSet ds(m);
        ll total = 0;
        for(int i = 0; i < n; i++){
            cin >> u >> v >> x;
            arestas.push_back({x,{u,v}});
            total += x;
        }
        sort(ALL(arestas));
        
        ll res = 0;
        
        for(auto it : arestas){
            x = it.first;
            u = it.second.first;
            v = it.second.second;
            if(ds.find(u) != ds.find(v)){
                res += x;
                ds.unionByRank(u,v);
            }
        }

        cout << total - res << endl;

    }
    
    

}