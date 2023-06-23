#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;



int N, W;
vector<pair<int,int>>joias;
vector<vector<ll>>dp;

ll solve(int indice, int target){
    if(target == 0)  return 0;
    if(indice >= N || target < 0) return 1e9+1LL;
    if(dp[indice][target] != -1) return dp[indice][target];

    ll notTake = solve(indice + 1, target);
    ll take = 1e9+1;
    if(target - joias[indice].second >= 0){
        take = joias[indice].first + 
        solve(indice+1,target - joias[indice].second);
    }

    return dp[indice][target] = min(take, notTake);


}





int main(){

    cin >> N >> W;

    joias.resize(N);
    int total = 0;
    for(int i = 0; i < N; i++){
        int peso, valor;
        cin >> peso >> valor;
        total += valor;
        joias[i] = {peso,valor};
    }

    dp.resize(N, vector<ll>(total+1,-1));

    ll res;
    for(int i = total; i >= 0; i--){
        res = solve(0,i);
        if(res <= W && res != -1){
            cout << i  << endl;
            break;
        }
    }


}