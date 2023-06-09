#include<bits/stdc++.h>

using namespace std;

//problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/0


bool isCycle(int V, vector<int> adj[]){
    vector<int>visitados(V,0);
    stack<pair<int,int>>q;

    for(int i = 0; i < V; i++){
        if(visitados[i] == 0){
            q.push({i,-1});
            visitados[i] = 1;
            while(!q.empty()){
                int no = q.top().first;
                int origem = q.top().second;
                q.pop();
                for(int x : adj[no]){
                    if(x != origem && visitados[x] == 1) return 1;
                    else if(x != origem){
                        visitados[x] = 1;
                        q.push({x,no});
                    }

                }

            }

        }
    }

    return 0;


        
}