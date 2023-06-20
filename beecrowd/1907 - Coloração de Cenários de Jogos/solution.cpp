#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;



int main(){

    optimize;

    int n, m;

    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }


    vii visitados(n, vi(m,0));


    queue<pair<int,int>>q;
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    int res = 0;
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            if(grid[row][col] == '.' && visitados[row][col] == 0){
                res++;
                q.push({row,col});
                visitados[row][col] = 1;
                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    for(int i = 0; i < 4; i++){
                        int nr = r + dx[i];
                        int nc = c + dy[i];
                        if(nr >= 0 && nc >= 0 && nr < n && nc < m &&  grid[nr][nc] == '.' && visitados[nr][nc] == 0){
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