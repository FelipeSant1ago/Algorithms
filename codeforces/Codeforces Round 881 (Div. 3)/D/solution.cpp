#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define MAXN 1000000
#define INF 1000000007



using namespace std;

ll dfs(int no, vi adj[], int vis[], vector<ll>& res){
    vis[no] = true;
    ll y = 0;
    for(int x : adj[no]){
        if(vis[x] == false){
            y += dfs(x,adj,vis,res);
        }

    }

    if(y == 0) y = 1;

    res[no] = y;

    return res[no];
}



int main(){

    optimize;


    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vi adj[n+1];
        int u,v;
        for(int i = 1; i <= n-1; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        int vis[n+1] = {0};

        vector<ll> res(n+1,0);
       

        dfs(1,adj,vis,res);

        int q;
        cin >> q;
       

        while(q--){
            int x,y;
            cin >> x >> y;
            ll a = res[x]*res[y];
            cout << a << endl;
        }
    }

}