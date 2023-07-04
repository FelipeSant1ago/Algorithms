#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define MAXN 1000000
#define INF 1000000007
using namespace std;
ll dp[101][2];
ll solve(int pesoTarget,int k, int d, bool passeiPorD){
    if(pesoTarget < 0) return 0;
    if(pesoTarget == 0 && passeiPorD) return 1;
    if(pesoTarget == 0 && ! passeiPorD) return 0;
    if(dp[pesoTarget][passeiPorD] != -1) return dp[pesoTarget][passeiPorD];
    ll res = 0;
    for(int i = 1; i <= k; i++){
        if(i >= d) res += solve(pesoTarget-i,k,d,true);
        else res += solve(pesoTarget-i,k,d,passeiPorD);
        res = res%(1000000007);
    }

    return dp[pesoTarget][passeiPorD] = res;


}


int main(){
    optimize;
    memset(dp,-1,sizeof(dp));
    int n, k, d;
    cin >> n >> k >> d;

    cout << solve(n,k,d, false) << endl;

}