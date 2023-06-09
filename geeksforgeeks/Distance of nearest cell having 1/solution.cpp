#include<bits/stdc++.h>

using namespace std;
//problem link: https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/0


class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid){
    int H = grid.size();
    int W = grid[0].size();
	vector<vector<int>>ans(H, vector<int>(W,0));
    //no atual, no de origem
    queue<pair<pair<int,int>,pair<int,int>>>q;

    for(int row = 0; row < H; row++){
        for(int col = 0; col < W; col++){
            if(grid[row][col] == 1){
                q.push({{row,col},{row,col}});
            }
            
        }
    }

    int dr[] = {1,0,-1,0};
    int dc[] = {0,1,0,-1};

    while(!q.empty()){
        int linhaOrigem = q.front().second.first;
        int colunaOrigem = q.front().second.second;
        int linhaAtual = q.front().first.first;
        int colunaAtual = q.front().first.second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nr = linhaAtual + dr[i];
            int nc = colunaAtual + dc[i];
            if(nr >= 0 && nc >= 0 && nr < H && nc < W && ans[nr][nc] == 0 && grid[nr][nc] == 0){
                ans[nr][nc] = abs(linhaOrigem - nr) + abs(colunaOrigem - nc);
                q.push({{nr,nc},{linhaOrigem,colunaOrigem}});
            }
        }

    }

    return ans;
}
};