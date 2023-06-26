#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;



int main(){

    optimize;


    while(true){
        int vertices, arestas;
        cin >> vertices >>  arestas;
        if(vertices == 0 && arestas == 0 )break;

        vi adj[vertices + 1];


        for(int i = 0; i < arestas; i++){
            int u, v, tipo;
            cin >> u >> v >> tipo;
            adj[u].push_back(v);

            if(tipo == 2) adj[v].push_back(u);

        }
        int res = 1;
        for(int no = 1; no <= vertices; no++){
            int visitados[vertices+1] = {0};

            queue<int>q;
            q.push(no);
            visitados[no] = 1;
            while(!q.empty()){
                int vertice = q.front();
                q.pop();

                for(int adjacente : adj[vertice]){
                    if(visitados[adjacente] == 0){
                        visitados[adjacente] = 1;
                        q.push(adjacente);
                    }
                }
            }

            for(int i = 1; i <= vertices; i++){
                if(visitados[i] == 0){
                    res = 0;
                    break;
                }
            }
            if(res == 0) break;
            
        }

        cout <<  res << endl;



    

    }

    
}