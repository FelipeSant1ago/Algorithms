#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int N;
vii atividades;
vii dp;

int solve(int indice, int cantPick){
   if(indice == N+1) return 0;

   if(dp[indice][cantPick] != -1) return dp[indice][cantPick];


   int pontos = 0;

   for(int i = 0; i< 3;i++){
    if(i != cantPick){
        pontos = max(pontos,solve(indice+1,i) + atividades[indice][i]);

    }
   }


   return dp[indice][cantPick] =  pontos;







}


int main(){

    cin >> N;

    atividades.resize(N,vi(3));

    dp.resize(N,vi(4,-1));

    for(int i = 0; i < N; i++){
        cin >> atividades[i][0];
        cin >> atividades[i][1];
        cin >> atividades[i][2];
        
    }
    N--;

    cout <<solve(0,3) << endl;


   

}