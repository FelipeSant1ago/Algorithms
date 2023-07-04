#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define MAXN 1000000
#define INF 1000000007
#define MOD 1000000007
using namespace std;
// problem link : https://practice.geeksforgeeks.org/problems/bipartite-graph/1
bool isBipartite(int V, vector<int>adj[]){
	    
        int colorido[V] = {0};
        queue<pii>q;
        for(int i = 0; i < V; i++){
            if(colorido[i] == 0){
                colorido[i] = 1;
                q.push({i,1});
                while(!q.empty()){
                    int no = q.front().first;
                    int cor = q.front().second;
                    q.pop();
                    for(int adjacente : adj[no]){
                        if(colorido[adjacente] == 0){
                            colorido[adjacente] = -cor;
                            q.push({adjacente,-cor});
                        }
                        else if(colorido[adjacente] == cor){
                            return false;
                           

                        }
                    }

                }
                
            }

        }

        return true;
	}


int main(){
    optimize;



}