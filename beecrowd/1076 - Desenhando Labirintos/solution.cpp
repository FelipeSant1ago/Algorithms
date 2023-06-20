#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;



int main(){

    optimize;
    int t;

    cin >> t;

    while(t--){
        int origem;
        cin >> origem;


        int vertices, arestas;

        cin >> vertices >> arestas;

        vi adj[vertices];

        int visitados[vertices] = {0};

        for(int i = 0; i < arestas; i++){
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int res = 0;
        queue<int>q;

        q.push(origem);
        visitados[origem] = 1;

        while(!q.empty()){
            int no = q.front();
            q.pop();
            for(int adjacente : adj[no]){
                if(visitados[adjacente] == 0){
                    visitados[adjacente] = 1;
                    res += 2;
                    q.push(adjacente);
                }
            }
        }

        cout <<  res << endl;
    }

}