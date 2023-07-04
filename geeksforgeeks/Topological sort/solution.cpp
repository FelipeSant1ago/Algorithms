#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

void dfs(int no,vector<int> adj[],int visited[], stack<int>& res){
    visited[no] = 1;

    for(int x : adj[no]){
        if(visited[x] == 0){
            dfs(x,adj,visited,res);
        }


    }
    res.push(no);





}


vector<int> topoSort(int V, vector<int> adj[]) {


    stack<int>res;
    vi linearOrder;
    int visited[V] = {0};
    for(int i = 0; i  < V; i++){
        if(visited[i] == 0){
            dfs(i,adj,visited,res);
        }

    }
        

    while(!res.empty()){
        linearOrder.push_back(res.top());
        res.pop();
    }

    return linearOrder;

    
}



int main(){

    optimize;

}