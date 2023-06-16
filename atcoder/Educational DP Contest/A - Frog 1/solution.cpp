#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

// int solve(int step, vi& heights, vi& dp){
//     if(step == 0) return 0;

//     if(dp[step] != -1) return dp[step];

//     int jump1 = solve(step-1,heights,dp) + abs(heights[step] - heights[step-1]);

//     int jump2 = 1e9+1;
//     if(step - 2 >= 0) jump2 = solve(step-2,heights,dp) + abs(heights[step] - heights[step-2]);

//     return dp[step] = min(jump1,jump2);
// }


int main(){

    optimize;

    int steps;
    cin >> steps;
    vi heights(steps);
    vi dp(steps,-1);
    for(int i = 0; i < steps; i++)cin >> heights[i];

    //cout << solve(steps-1,heights,dp) << endl;
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);
    for(int i = 2; i < steps; i++){

        dp[i] = min(dp[i -2] + abs(heights[i] - heights[i-2]),dp[i -1] + abs(heights[i] - heights[i-1]));


    }

    cout << dp[steps-1] << endl;

}