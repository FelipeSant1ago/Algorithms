#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define ALL(x) x.begin(),x.end() 
#define MAXN 1000000
#define INF 1000000007
#define MOD 1000000007
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
    {
        int visited[V] = {0};
        long long sum = 0;
        priority_queue<pair<int,long long>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            if(visited[it.second])continue;
            sum += -it.first;
            visited[it.second] = 1;
            for(auto x : adj[it.second]){
                if(!visited[x[0]]){
                    pq.push({-x[1],x[0]});
                }

            }
        }
        return sum;
    }

int main(){

    optimize;



}