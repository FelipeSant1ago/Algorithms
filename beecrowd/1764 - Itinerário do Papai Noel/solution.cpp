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

    int M, N;

    while(cin >> M && cin >> N && (M + N != 0)){
        vector<int> processados(M,0);
        DisjointSet ds(M);
        vector<pair<int,pii>>arestas;
        int x,y,z;
        for(int i = 0; i < N; i++){
            cin >> x >> y >> z;
            arestas.push_back({z,{x,y}});
        }
        sort(ALL(arestas));
        ll res = 0;
        for(auto it : arestas){
            int custo = it.first;
            int origem = it.second.first;
            int destino = it.second.second;
            if(ds.find(origem) != ds.find(destino)){
                res += custo;
                ds.unionByRank(origem,destino);

            }
        }

        cout << res << endl;
    }

    

}