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
 unordered_map<string,vector<string>>adj;
 unordered_map<string,bool>visitados;

 void dfs(string no){
    visitados[no] = true;
    for(string x : adj[no]){
        if(!visitados[x])dfs(x);
    }


 }


int main(){
    optimize;


    int M, N;
   
    cin >> M >> N;
    string u, v;
    for(int i = 0; i < N; i++){
        cin >> u >> v >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll res = 0;
    for(auto it : adj){
        if(!visitados[it.first]){
            res++;
            dfs(it.first);
        }
    }


    cout << res << endl;



}