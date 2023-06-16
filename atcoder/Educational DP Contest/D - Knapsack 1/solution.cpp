#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;



int main(){

    optimize;

    int n,w;
    cin >> n >> w;

    vector<pair<int,int>> pesoValor(n);

    for(int i = 0; i < n; i++){
        cin >> pesoValor[i].first;
        cin >> pesoValor[i].second;
    }

    vector<vector<ll>> dp(n, vector<ll>(w+1,0));

    if(pesoValor[0].first <= w){
        for(int capacidade = pesoValor[0].first; capacidade <= w; capacidade++){
            dp[0][capacidade] = pesoValor[0].second;
        }
    }

    for(int indice = 1; indice < n; indice++){
        for(int capacidade = 1; capacidade <= w; capacidade++){
            ll take = 0;
            if(pesoValor[indice].first <= capacidade){
                take = dp[indice-1][capacidade -pesoValor[indice].first] + pesoValor[indice].second;
            }
            ll notTake = dp[indice-1][capacidade];
            dp[indice][capacidade] = max(take, notTake);

        }
    }

    cout << dp[n-1][w] << endl;



   
  

}