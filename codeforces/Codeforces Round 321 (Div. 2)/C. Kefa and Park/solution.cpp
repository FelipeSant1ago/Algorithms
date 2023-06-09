#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
using namespace std;


int main(){

    int n, m;
    cin >> n >> m;
    vector<int>temGato(n+1);
    for(int i = 1; i <= n; i++) cin >> temGato[i];

    vi adj[n+1];
    for(int i = 1; i < n;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //nó origem, nó atual, numero de gatos no nó;
    queue<pair<pair<int,int>,int>>q;
    q.push({{-1,1},temGato[1]});

    int res = 0;

    while(!q.empty()){
        int noOrigem = q.front().first.first;
        int n = q.front().first.second;
        int gatos = q.front().second;
        q.pop();
        for(int no : adj[n]){
            if(no != noOrigem){
                int ngatos = gatos;
                if(temGato[no]) ngatos++;
                else ngatos = 0;
                if(adj[no].size() > 1 && ngatos <= m){
                    q.push({{n,no},ngatos});
                }
                else if(adj[no].size() == 1 && ngatos <= m)res++;

            }
            
        }
    }

    cout << res << endl;



}