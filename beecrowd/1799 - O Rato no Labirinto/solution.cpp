#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;



int main(){

    optimize;


    int vertices, arestas;

    cin >> vertices >> arestas;
    unordered_map<string,vector<string>>adj;

    for(int i = 0; i < arestas; i++){
        string u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int res = 0;
    queue<pair<string,int>>q;
    unordered_map<string,int>visitados;
    q.push({"Entrada",0});
    visitados["Entrada"] = 1;
    bool acheiQueijo = false;
    while(!q.empty()){
        string no = q.front().first;
        int passos = q.front().second;
        q.pop();
        if(acheiQueijo == true) continue;

        for(string adjacente : adj[no]){
            if(visitados[adjacente] == 0){
                visitados[adjacente] = 1;
                q.push({adjacente,passos+1});
                if(adjacente == "*"){
                    acheiQueijo = true;
                    res += passos + 1;
                    break;
                }
            }
        }


    }
    bool acheiSaida = false;
    visitados.clear();

    q.push({"*",0});
    visitados["*"] = 1;

    while(!q.empty()){
        string no = q.front().first;
        int passos = q.front().second;
        q.pop();

        for(string adjacente : adj[no]){
            if(visitados[adjacente] == 0){
                visitados[adjacente] = 1;
                q.push({adjacente,passos+1});
                if(adjacente == "Saida"){
                    acheiSaida = true;
                    res += passos + 1;
                    break;
                }
            }
        }
        if(acheiSaida == true) break;
    }


    cout << res << endl;





    
}