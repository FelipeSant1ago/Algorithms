#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

//time limit exceeded
int main(){
    optimize;
    int t;
    cin >> t;

    while(t--){
        int n, c0;
        cin >> n >> c0;
        vi operacoes(n-1);
        for(int i = 0; i < n-1; i++)cin >> operacoes[i];

        vi adj[n+1];

        for(int i = 0; i < n-1; i++){
            int u,v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //pai,no,numero de passos
        queue<pair<pair<int,int>,int>>q;
        vi ehpreto(n+1,0);
        ehpreto[c0] = 1;
        int res = n;
        int maxPassos = n-1;
        for(int i = 0; i < n-1; i++){
            int novoPreto = operacoes[i];
            ehpreto[novoPreto] = 1;
            if(res == 1){
                cout << 1 << " ";
                continue;
            }

            q.push({{0,novoPreto},0});

            while(!q.empty()){
                int pai = q.front().first.first;
                int no = q.front().first.second;
                int passos = q.front().second;
                q.pop();
                if(passos >= maxPassos)continue;

                for(int noAdjacente : adj[no]){
                    if(noAdjacente != pai){
                        if(ehpreto[noAdjacente]){
                            res = passos + 1;
                            maxPassos = res-1;
                            break;
                        }
                        else{
                            q.push({{no,noAdjacente},passos + 1});
                        }

                    }
                }
            }

            cout << res << " ";
        }

        cout << endl;



    }


}