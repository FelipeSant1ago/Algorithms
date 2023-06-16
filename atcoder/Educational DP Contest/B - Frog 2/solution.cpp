#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;



int main(){

    optimize;

    int steps,k;

    cin >> steps >> k;

    vi heights(steps);
    for(int i = 0; i < steps; i++)cin >> heights[i];

    vi dp(steps);

    dp[0] = 0;

    for(int i = 1; i < steps; i++){
        dp[i] = 1e9+1;
        for(int j = 1; j <= k; j++){
            if(i - j >= 0){
                dp[i] = min(dp[i], dp[i-j] + abs(heights[i] - heights[i-j]));
            }

        }
    }

    cout << dp[steps-1] << endl;

}