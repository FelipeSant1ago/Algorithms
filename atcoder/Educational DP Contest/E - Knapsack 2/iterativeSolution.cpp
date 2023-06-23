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
        total += valor;

        joias[i] = {peso,valor};
    }
    vector<vector<ll>> dp(N, vector<ll>(total+1,1e9+1LL));

    
    dp[0][joias[0].second] = joias[0].first;
    for(int i = 0; i < N; i++)dp[i][0] = 0;

    for(int indice = 1; indice < N; indice++){
        for(int valor = 1; valor <= total; valor++){
            ll notTake = dp[indice-1][valor];
            ll take = 1e9+1LL;
            if(valor - joias[indice].second >= 0){
                take = dp[indice-1][valor - joias[indice].second]
                + joias[indice].first;
            }

            dp[indice][valor] = min(take,notTake);
        }
    }


    for(int valor = total; valor >= 0; valor--){
        if(dp[N-1][valor] <= W){
            cout << valor << endl;
            break;
        }
    }

    


   





}