#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int N;
vi heights;
vi dp;

int solve(int indice){
    if(indice == N) return 0;
    if(indice == N - 1) return abs(heights[indice] - heights[indice+1]);
    if(dp[indice] != -1) return dp[indice];
    int j1 = abs(heights[indice] - heights[indice+1]) + solve(indice+1);
    int j2 = abs(heights[indice] - heights[indice+2]) + solve(indice+2);

    return dp[indice] =  min(j1,j2);
}


int main(){

    optimize;
    cin >> N;
    heights.resize(N);
    dp.resize(N);
    for(int i = 0; i < N;i++)dp[i] = -1;

    for(auto &e : heights) cin >> e;

    N--;

    cout << solve(0) << endl;


}