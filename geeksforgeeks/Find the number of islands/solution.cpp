#include<bits/stdc++.h>

using namespace std;
//problem link: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/0

class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>visited(m, vector<int>(n,-1));
    int res = 0;
    queue<pair<int,int>>q;

    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(visited[i][j] == -1 && grid[i][j] == '1'){
                res++;
                visited[i][j] = 1;
                q.push({i,j});
                while(!q.empty()){
                    auto it = q.front();
                    q.pop();
                    for(int h = -1; h <= 1; h++){
                        for(int v = -1; v <= 1; v++){
                            if(h + it.second >= 0 && h + it.second < n && v + it.first >= 0 && v + it.first < m){
                                if(visited[it.first + v][h + it.second] == -1 && grid[it.first + v][h + it.second] == '1'){
                                    q.push({it.first+v,h+it.second});
                                    visited[it.first + v][h + it.second] = 1;

                                }
                            }

                        }
                    }

                }

            }
            
        }
    }

    return res;

    
       

    }
};