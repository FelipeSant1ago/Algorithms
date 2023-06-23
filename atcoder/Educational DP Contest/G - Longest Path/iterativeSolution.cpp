#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int V, A;

vi  adj[100001];
vi dp;





int main(){

    cin >> V >> A;


    for(int i = 0; i < A; i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    dp.resize(V+1,-1);
    

    


}