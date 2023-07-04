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

    vi adjReaching[N+1];
    vi adjReachedBy[N+1];

    for(int i = 0; i < M; i++){
        int u,v;

        cin >> u >> v;
        adjReaching[u].push_back(v);
        adjReachedBy[v].push_back(u);
    }

    int visitedReaching[N+1] = {0};
    int visitedReachedBy[N+1] = {0};
    // for(int i = 0; i <= N; i++) cout << visited[i] << " ";
    // cout << endl;

    queue<int>q;
    q.push(1);
    visitedReaching[1] = true;

    while(!q.empty()){
        int no = q.front();
        q.pop();

        for(int x : adjReaching[no]){
            if(visitedReaching[x] == 0){
                visitedReaching[x] = 1;
                q.push(x);
            }
        }

    }
    q.push(1);
    visitedReachedBy[1] = true;
    while(!q.empty()){
        int no = q.front();
        q.pop();

        for(int x : adjReachedBy[no]){
            if(visitedReachedBy[x] == 0){
                visitedReachedBy[x] = 1;
                q.push(x);
            }
        }

    }   

    bool res = true;

    // for(int i = 0; i <= N; i++) cout << visitedReachedBy[i] << " ";
    // cout << endl;

    // for(int i = 0; i <= N; i++) cout << visitedReaching[i] << " ";
    // cout << endl;

    for(int i = 1; i <= N; i++){
        if(visitedReachedBy[i] == 0 && visitedReaching[i] == 0){
            res = false;
            break;
        }

    }

    



    if(res) cout << "Bolada" << endl;
    else cout << "Nao Bolada" << endl;




}