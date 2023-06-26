#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int,int>>
#define pii pair<int,int>
#define ll long long


using namespace std;

int main(){

    int n, m;

    cin >> n >> m;
    vi gold(n);

    for(int i = 0; i < n; i++) cin >> gold[i];

    vector<int> adj[n+1];
    vi visitados(n+1,0);

    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    ll res = 0;
    
    queue<int>q;
    for(int personagem = 1; personagem <= n; personagem++){
        int menor = 1e9+1;
        if(visitados[personagem] == 0){
            visitados[personagem] = 1;
            q.push(personagem);
            menor = gold[personagem-1];
            while(!q.empty()){
                int pers = q.front();
                q.pop();
                if(gold[pers-1] < menor) menor = gold[pers-1];
                for(int i= 0; i < adj[pers].size(); i++){// int amigo : adj[pers]
                    int amigo = adj[pers][i];
                    if(visitados[amigo] == 0){
                        visitados[amigo] = 1;
                        q.push(amigo);
                    }
                }
            }
            res += menor;
        }

    }


    cout << res << endl;






}