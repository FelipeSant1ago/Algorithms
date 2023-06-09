#include<bits/stdc++.h>

using namespace std;

// problem link: https://practice.geeksforgeeks.org/problems/number-of-enclaves/0

class Solution {
  public:
    void dfs(int row, int col,vector<vector<int>> &grid,vector<vector<int>> &visitados, int dr[], int dc[]){
    visitados[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();

    for(int i = 0; i < 4; i++){
        int nr = row + dr[i];
        int nc = col + dc[i];
        if(nr >= 0 && nc >= 0 && nr < n && nc < m
        && grid[nr][nc] == 1 && visitados[nr][nc] == 0){
            dfs(nr,nc,grid,visitados,dr,dc);
        }
    }
}


int numberOfEnclaves(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>visitados(n,vector<int>(m,0));
    int dr[] = {1,0,-1,0};
    int dc[] = {0,-1,0,1};

    for(int c = 0; c < m; c++){
        if(grid[0][c] == 1 && visitados[0][c] == 0)dfs(0,c,grid,visitados,dr,dc);
        if(grid[n-1][c] == 1 && visitados[n-1][c] == 0)dfs(n-1,c,grid,visitados,dr,dc);
    }
    for(int r = 0; r < n; r++){
        if(grid[r][0] == 1 && visitados[r][0] == 0)dfs(r,0,grid,visitados,dr,dc);
        if(grid[r][m-1] == 1 && visitados[r][m-1] == 0)dfs(r,m-1,grid,visitados,dr,dc);

    }

    int res = 0;
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            if(grid[row][col] == 1 && visitados[row][col] == 0)res++;
        }
    }


    return res;

    
        
}
};