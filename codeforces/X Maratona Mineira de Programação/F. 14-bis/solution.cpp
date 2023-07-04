#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define MAXN 1000000
#define INF 1000000007
using namespace std;



int main(){
    optimize;

    int H, W;

    cin >> H >> W;

    int grid[H][W];

    for(int row = 0; row < H; row++){
        for(int col = 0; col < W; col++){
            cin >> grid[row][col];
        }
    }
    int res = 1;
    int atual = 0;

     for(int row = 0; row < H; row++){
        atual = 1;
        for(int col = 0; col < W-1; col++){
            if(abs(grid[row][col+1] - grid[row][col]) > 1){
                if(atual > res) res = atual;
                atual = 1;
            }
            else atual++;
            
        }
        if(atual > res) res = atual;
    }


    for(int col = 0; col < W; col++){
        atual = 1;
        for(int row = 0; row < H-1; row++){
            if(abs(grid[row+1][col] - grid[row][col]) > 1){
                if(atual > res) res = atual;
                atual = 1;
            }
            else atual++;
            
        }
        if(atual > res) res = atual;
    }


    cout << res << endl;

}