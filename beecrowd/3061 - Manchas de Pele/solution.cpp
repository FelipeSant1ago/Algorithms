#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;





int main(){

    int n, m;

    cin >> n >> m;

    vii grid(n, vi (m));

    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            cin >> grid[row][col];

        }
    }
    int res = 0;
    vii visitados(n, vi(m,0));
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    queue<pair<int,int>>q;
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
           if(grid[row][col] == 1 && visitados[row][col] == 0){
            res++;
            visitados[row][col] = 1;
            q.push({row,col});
            while(!q.empty()){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nr = r + dx[i];
                    int nc = c + dy[i];

                    if(nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    visitados[nr][nc] == 0 && grid[nr][nc] == 1){
                        visitados[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }

            }

           }

        }
    }


    cout << res << endl;

    










    
}