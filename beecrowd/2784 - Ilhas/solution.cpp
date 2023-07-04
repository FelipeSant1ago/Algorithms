#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


using namespace std;



int main(){
    optimize;
    int N, M;
    cin >> N >> M;

    vector<pii> adj[N+1];

    for(int i = 0; i < M; i++){
        int u,v, p;
        cin >> u >> v >> p;
        adj[u].push_back({v,p});
        adj[v].push_back({u,p});
    }

    int origem;
    cin >> origem;

    vi distancia(N+1,1000000007);
    vi processados(N+1,0);
    distancia[origem] = 0;
   

    priority_queue<pii>pq;
    pq.push({0,origem});

    while(!pq.empty()){
        int no = pq.top().second;
        pq.pop();
        if(processados[no]) continue;
        processados[no] = true;
        for(auto x : adj[no]){
            int adjacente = x.first;
            int ping = x.second;
            if(distancia[adjacente] > distancia[no] + ping){
                distancia[adjacente] = distancia[no] + ping;
                pq.push({-distancia[adjacente],adjacente});
            }


        }
    }

    int menor = 1e9, maior = -1;

    for(int i = 1; i <= N; i++){
        int x = distancia[i];
        if(i != origem){
            if(x < menor) menor = x;
            if(x > maior) maior = x;
        }
    }

    cout << abs(menor - maior) << endl;

   



    

}