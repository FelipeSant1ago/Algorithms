#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


using namespace std;
int main(){

    optimize;

    int cidades, estradas;

    cin >> cidades >> estradas;
    vector<pii> adj[cidades +1];
    vector<int>distanciaPar(cidades+1,1000000007);
    vector<int>distanciaImpar(cidades+1,1000000007);
    int processadoPar[cidades+1] = {0};
    int processadoImpar[cidades+1] = {0};


    for(int i = 0; i < estradas; i++){
        int c1,c2,p;
        cin >> c1 >> c2 >> p;
        adj[c1].push_back({c2,p});
        adj[c2].push_back({c1,p});
    }
    distanciaPar[1] = 0;
    distanciaImpar[1] = 0;
    priority_queue<pair<pii,bool>>pq;
    pq.push({{0,1},true});
    while(!pq.empty()){
        int no = pq.top().first.second;
        bool ehPar = pq.top().second;
        pq.pop();
        if(processadoPar[no] && ehPar) continue;
        if(processadoImpar[no] && !ehPar) continue;
        if(ehPar) processadoPar[no] = true;
        else processadoImpar[no] = true;
        for(auto x : adj[no]){
            int adjacente = x.first;
            int custo = x.second;
           if(ehPar){
            if(distanciaImpar[adjacente] > distanciaPar[no] + custo){
                distanciaImpar[adjacente] = distanciaPar[no] + custo;
                pq.push({{-distanciaImpar[adjacente],adjacente},!ehPar});
            }

           }
           else{

            if(distanciaPar[adjacente] > distanciaImpar[no] + custo){
                distanciaPar[adjacente] = distanciaImpar[no] + custo;
                pq.push({{-distanciaPar[adjacente],adjacente},!ehPar});
            }

           }
            
        }
    }
    vi res;
    if(distanciaPar[cidades] != 1000000007) res.push_back(distanciaPar[cidades]);
    for(auto x : adj[cidades]){
        if(x.first != 1 && distanciaImpar[x.first] != 1000000007) res.push_back(distanciaImpar[x.first] + x.second);
    }
    int menor = 1e9;
    if(res.size() == 0) menor = -1;
    else for(int x : res) if( x < menor) menor = x;
    cout << menor << endl;

}