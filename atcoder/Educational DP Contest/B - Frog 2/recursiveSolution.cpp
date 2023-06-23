#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int N, K;

vi dp;
vi heights;

int solve(int indice){
    if(indice == N) return 0;
    if(dp[indice] != -1) return dp[indice];


    int res = 1e9+1;

    for(int i = 1; i <= K; i++){
        if(i + indice <= N){
            int jump = abs(heights[i+indice] - heights[indice]);
            jump += solve(indice + i);
            res = min(res,jump);
        }

    }

    return dp[indice] = res;
}


int main(){

    cin >> N >> K;
    heights.resize(N);

    for(auto &e : heights) cin >> e;
    dp.resize(N);

    for(int i = 0; i < N; i++)dp[i] = -1;

    N--;

    cout << solve(0) << endl;
    

}