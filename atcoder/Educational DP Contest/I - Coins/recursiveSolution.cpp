#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int N;
vector<double>probabilidades;


vector<double>moedas;
vector<vector<double>>dp;

double solve(int indice, int qtdCaras){

    if(indice == N && qtdCaras <= N/2) return 0;
    if(indice == N && qtdCaras > N/2) return 1;
    if(dp[indice][qtdCaras] != -1) return dp[indice][qtdCaras];

    double take = moedas[indice]*solve(indice+1,qtdCaras+1);
    double notTake = (1.0 - moedas[indice])*solve(indice+1,qtdCaras);


    return dp[indice][qtdCaras] = take + notTake;

}





int main(){


    cin >> N;

    moedas.resize(N);
    dp.resize(N, vector<double>(N+1,-1));

    for(auto &e : moedas) cin >> e;

    cout << setprecision(9) <<  solve(0,0) << endl;




}