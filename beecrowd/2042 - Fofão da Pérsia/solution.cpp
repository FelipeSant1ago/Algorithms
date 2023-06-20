#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;


long long solve(int verticeAtual, int borrachaAtual ,vector<vector<pair<int,pair<int,int>>>>& adj,int destino, vector<vector<long long>>&dp){
    if(borrachaAtual < 0) return -1;
    if(verticeAtual == destino) return 0;
    if(dp[verticeAtual][borrachaAtual] != -2) return dp[verticeAtual][borrachaAtual];

    long long maximo = -1;

    for(auto x : adj[verticeAtual]){
        int novoVertice = x.first;
        long long felicidade = x.second.first;
        int borracha = x.second.second;

        if(borrachaAtual - borracha >= 0){
            long long tentativa =  solve(novoVertice,borrachaAtual-borracha,adj,destino,dp);
            if(tentativa != -1) maximo = max(maximo, tentativa + felicidade);
             

        }
    }

    return dp[verticeAtual][borrachaAtual] =  maximo;
}


int main(){


    int vertices, arestas;

    cin >> vertices >> arestas;

    int origem, destino;

    cin >> origem >> destino;
    int borrachaInicial;

    cin >> borrachaInicial;

    //{destino,{felicidade,borracha}}
    vector<vector<pair<int,pair<int,int>>>> adj(vertices+1);


    for(int i = 0; i < arestas; i++){
        int o, d, f, b;

        cin >> o >> d >> f >> b;

        adj[o].push_back({d,{f,b}});
        adj[d].push_back({o,{f,b}});
    }
    vector<vector<long long>>dp(vertices+1,vector<long long>(borrachaInicial+1,-2));

    cout << solve(origem,borrachaInicial,adj,destino,dp) << endl;




   



    
}