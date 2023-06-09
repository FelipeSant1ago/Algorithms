#include<bits/stdc++.h>

using namespace std;
//problem link: https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/0

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int nr = image.size();
    int nc = image[0].size();
    int color = image[sr][sc];
    vector<vector<int>> visitados(nr, vector<int>(nc,0));
    queue<pair<int,int>>q;
    q.push({sr,sc});
    int dr[] = {1,0,-1,0};
    int dc[] = {0,1,0,-1};
    visitados[sr][sc] = 1;

    while(!q.empty()){
        int r = q.front().first; 
        int c = q.front().second;
        image[r][c] = newColor;
        q.pop();

        for(int i = 0; i < 4; i++){
            int newr = r + dr[i];
            int newc = c + dc[i];
            if(newr >= 0 && newc >= 0 && newr < nr && newc < nc && image[newr][newc] == color 
            && visitados[newr][newc] == 0){
                 q.push({newr,newc});
                 visitados[newr][newc] = 1;
            }
        }
    }
    
    

    return image;
         
}