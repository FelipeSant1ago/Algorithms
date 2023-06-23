#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;


int N, W;
vector<vector<ll>>dp;
vector<pair<int,int>>joias;

ll solve(int indice, int capacidade){
    if(indice < 0) return 0;
    if(dp[indice][capacidade] != -1) return dp[indice][capacidade];

    ll notTake = solve(indice-1,capacidade);

    ll take = 0;

    if(capacidade - joias[indice].first >= 0){
        take = joias[indice].second + solve(indice-1,capacidade - joias[indice].first);

    }

    return dp[indice][capacidade] = max(take, notTake);

}

int main(){

    cin >> N >> W;

    joias.resize(N);
    dp.resize(N, vector<ll>(W+1,-1));

    for(int i = 0; i < N; i++){
        int peso, valor;

        cin >> peso >> valor;
        joias[i] = {peso,valor};
    }


    cout << solve(N-1,W) << endl;




   

}