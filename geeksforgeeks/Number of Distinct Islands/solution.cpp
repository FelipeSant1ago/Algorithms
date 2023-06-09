#include<bits/stdc++.h>

using namespace std;

// problem link: https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/0

class Solution {
  public:
   int countDistinctIslands(vector<vector<int>>& grid) {
        unordered_map<string,int>freq;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visitados(n, vector<int>(m,0));
        int dr[] = {1,0,-1,0};
        int dc[] = {0,1,0,-1};

        queue<pair<int,int>>q;



        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == 1 && visitados[row][col] == 0){
                    string caminho = "";
                    visitados[row][col] = 1;
                    q.push({row,col});
                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        for(int i = 0; i < 4; i++){
                            int nr = r + dr[i];
                            int nc = c + dc[i];
                            if(nr >= 0 && nc >= 0 && nr < n && nc < m && visitados[nr][nc] == 0
                            && grid[nr][nc] == 1){
                                visitados[nr][nc] = 1;
                                caminho += "(" +to_string(nr - row) + " " + to_string(nc-col) +")";
                                

                                q.push({nr,nc});

                            }
                        }

                    }
                    freq[caminho]++;
                }
                
            }
        }
        int res = 0;
        for(auto it : freq){
            res++;

        }

        return res;
    }
};