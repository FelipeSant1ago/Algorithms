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
    int soma = 0;
    for(int i = 0; i < n; i++){
        cin >> pesoValor[i].first;
        cin >> pesoValor[i].second;
        soma += pesoValor[i].second;
    }

    vector<vector<ll>> dp(n, vector<ll>(soma+1,1e9+1));

    dp[0][pesoValor[0].second] = pesoValor[0].first;
    for(int indice = 0; indice < n; indice++)dp[indice][0] = 0;

    for(int indice = 1; indice < n; indice++){
        for(int valor = 1; valor <= soma; valor++){
            ll notTake = dp[indice-1][valor];
            ll take = 1e9+1;
            if(valor - pesoValor[indice].second >= 0){
                take = dp[indice-1][valor - pesoValor[indice].second] + pesoValor[indice].first;
            }

            dp[indice][valor] = min(take,notTake);
        }
    }


    for(int valor = soma; valor >= 0; valor--){
        if(dp[n-1][valor] <= w){
            cout << valor << endl;
            break;
        }
    }


   


   
  

}