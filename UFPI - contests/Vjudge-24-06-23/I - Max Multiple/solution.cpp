#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


using namespace std;



int main(){

    optimize;


    int n, k, d;
    cin >> n >> k >> d;
    vi arr(n);

    for(auto &e : arr) cin >> e;
    vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(k+1,vector<ll>(d,-1)));
    dp[0][0][0] = 0;
    dp[0][1][arr[0]%d] = arr[0];

    for(int indice = 1; indice < n; indice++){
        for(int qtd = 0; qtd <= k; qtd++){
            for(int resto = 0; resto < d; resto++){
                ll notTake = dp[indice-1][qtd][resto];
                int x = resto - arr[indice]%d;
                int novoResto;
                if(x >= 0){
                    novoResto = x;
                }
                else{
                    novoResto = d - arr[indice]%d + resto;
                }
                ll take = -1;
                if(qtd >= 1 &&  dp[indice-1][qtd-1][novoResto] != -1){
                    take = dp[indice-1][qtd-1][novoResto] + arr[indice];
                }

                dp[indice][qtd][resto] = max(take, notTake);
                

            }

        }
    }

    cout << dp[n-1][k][0] << endl;


    

    


}