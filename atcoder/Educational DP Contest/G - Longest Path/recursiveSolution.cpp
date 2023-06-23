#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int V, A;

vi  adj[100001];
vi dp;

int solve(int vertice){

    int res = 0;
    if(dp[vertice] != -1) return dp[vertice];

    for(int no : adj[vertice]){
        res = max(res, solve(no) + 1);
    }



    return dp[vertice] = res;

}




int main(){

    cin >> V >> A;


    for(int i = 0; i < A; i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    dp.resize(V+1,-1);
    int res = 0;
    int aux;
    for(int i = 1; i <= V; i++){

        aux = solve(i);
        if(aux > res) res = aux;

    }

    cout << res << endl;

    


}