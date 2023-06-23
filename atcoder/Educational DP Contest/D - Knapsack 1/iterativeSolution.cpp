#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int N, W;

vector<pair<int,int>> joias;



int main(){

    cin >> N >> W;

    joias.resize(N);

    int peso, valor;
    int total = 0;

    for(int i = 0; i < N; i++){
        cin >> peso >> valor;
        total += peso;

        joias[i] = {peso,valor};
    }
    vector<vector<ll>> dp(N, vector<ll>(W+1,0));

    if(joias[0].first <= W){
        for(int i = joias[0].first; i <= W; i++){
            dp[0][i] = joias[0].second;
        }
    }
    for(int indice = 1; indice < N; indice++){
        for(int capacidade = 1; capacidade <= W; capacidade++){
            ll notTake = dp[indice-1][capacidade];
            ll take = 0;
            if(capacidade >= joias[indice].first){
                take = dp[indice-1][capacidade - joias[indice].first] 
                + joias[indice].second;
            }

            dp[indice][capacidade] = max(take,notTake);

        }
    }

    cout << dp[N-1][W] << endl;;


   





}