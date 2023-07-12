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
vi visitados;
vvi adj;
void dfs(int no){
    visitados[no] = 1;

    for(int x : adj[no]){
        if(!visitados[x])dfs(x);
    }
}

int main(){

    optimize;
    int n,m;
    cin >> n >> m;
    visitados.resize(n+1);
    adj.resize(n+1);
    int x,y;
    for(int i = 0; i < m; i++){

        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll res = 0;
    for(int i = 1; i <= n; i++){
        if(!visitados[i]){
            res++;
            dfs(i);
        }
    }

    cout << res << endl;


}