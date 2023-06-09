#include<bits/stdc++.h>

using namespace std;

// problem link: https://practice.geeksforgeeks.org/problems/rotten-oranges2536/0

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
   int orangesRotting(vector<vector<int>>& grid){
    int res = 0;
    int H = grid.size();
    int W = grid[0].size();
    vector<vector<int>>visitados(H,vector<int>(W,0));
    queue<pair<pair<int,int>,int>>q;
    
    for(int row = 0; row < H; row++){
        for(int col = 0; col < W; col++){
            if(grid[row][col] == 2){
                visitados[row][col] = 1;
                q.push({{row,col},0});
            }
        }
    }

    int dr[] = {1,0,-1,0};
    int dc[] = {0,1,0,-1};

    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int tempo = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nc >= 0 && nr < H && nc < W && visitados[nr][nc] == 0 && grid[nr][nc] == 1){
                visitados[nr][nc] = 1;
                q.push({{nr,nc},tempo + 1});
                if(tempo + 1 > res) res = tempo + 1;
            }

        }

    }

     for(int row = 0; row < H; row++){
            for(int col = 0; col < W; col++){
                if(grid[row][col] == 1 && visitados[row][col] == 0) return -1;
            }
        }

    return res;
    

       
}
};