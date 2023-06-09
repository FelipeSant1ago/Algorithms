#include<bits/stdc++.h>

using namespace std;

// problem link: https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/0


class Solution{
public:
  vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    vector<vector<char>>ans(n, vector<char>(m,'X')); 
    queue<pair<int,int>>q;

    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            if(mat[row][col] == 'O' && (row == 0 || row == n-1 || col == 0 || col == m-1)){
                q.push({row,col});
                ans[row][col] = 'O'; 

            }
        }
    }
    int dr[] = {-1,0,1,0};
    int dc[] = {0,-1,0,1};


    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr >= 0 && nc >= 0 && nr < n && nc < m
            && mat[nr][nc] == 'O' && ans[nr][nc] == 'X'){
                ans[nr][nc] = 'O';
                q.push({nr,nc});
            }
        }
    }

    return ans;


        
}
};