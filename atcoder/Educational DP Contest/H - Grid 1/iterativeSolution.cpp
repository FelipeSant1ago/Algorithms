#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;





int main(){

    int H, W;
    cin >> H >> W;

    char grid[H][W];
    for(int row = 0; row < H; row++){
        for(int col = 0; col < W; col++){
            cin >>grid[row][col]; 
        }
    }

    vector<vector<ll>> dp(H, vector<ll>(W,0));
    dp[H-1][W-1] = 1;

    int x = 1;
    for(int row = H -2; row >= 0; row--){
        if(x == 0){
            dp[row][W-1] = 0;
        }
         else if(grid[row][W-1] == '.'){
            dp[row][W-1] = x;
         }
         else{
            x = 0;
            dp[row][W-1] = 0;
         }
    }
    x = 1;
    for(int col = W -2; col >= 0; col--){
        if(x == 0){
            dp[H-1][col] = 0;
        }
         else if(grid[H-1][col] == '.'){
            dp[H-1][col] = x;
         }
         else{
            x = 0;
            dp[H-1][col] = 0;
         }
    }


    for(int row = H - 2; row >= 0; row--){
        for(int col = W-2; col >= 0; col--){
            if(grid[row][col] == '#') continue;

            dp[row][col] = (dp[row+1][col] + dp[row][col+1])%1000000007;
            

        }
    }


    cout << dp[0][0] << endl;

    






}