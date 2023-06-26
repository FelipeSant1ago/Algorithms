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
        int u, v, ping;
        cin >> u >> v >> ping;
        adj[u].push_back({v,ping});
        adj[v].push_back({u,ping});
    }
    int x;
    cin >> x;



    vi distance(N+1);
    vi processed(N+1,0);
    priority_queue<pii>q;




    for (int i = 1; i <= N; i++) distance[i] = 1e9;
    distance[x] = 0;
    q.push({0,x});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.first, w = u.second;
            if (distance[a]+w < distance[b]) {
                distance[b] = distance[a]+w;
                q.push({-distance[b],b});
            }
        }
    }
    int menor = 1e9, maior = -1;
    //cout << "distancias = ";
    for(int z : distance){
       // cout << z << " ";
        if(z > 0){
            if(z < menor) menor = z;
            if(z > maior) maior = z;
        }

    }
    //cout << endl;


    cout << abs(maior - menor) << endl;

}