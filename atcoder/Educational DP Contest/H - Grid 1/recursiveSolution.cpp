#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

char grid[1000][1000];
vector<vector<ll>> dp;
int H, W;

ll solve(int row, int col){
    if(row >= H || col >= W) return 0;
    if(row == H-1 && col == W-1) return 1;
    if(grid[row][col] == '#') return 0;
    if(dp[row][col] != -1) return dp[row][col];
    ll res = (solve(row+1,col) +solve(row,col+1))%1000000007;

    return dp[row][col] = res;
}


int main(){

    
    cin >> H >> W;

    
    for(int row = 0; row < H; row++){
        for(int col = 0; col < W; col++){
            cin >>grid[row][col]; 
        }
    }

    dp.resize(H, vector<ll>(W,-1));

    cout << solve(0,0) << endl;
   

    






}